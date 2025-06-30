import express from 'express';
import Order from '../models/Order.js';
import Cart from '../models/Cart.js';
import { authenticate, authorize } from '../middleware/auth.js';
import sendEmail from '../utils/sendEmail.js';
import logAdminAction from '../utils/adminLog.js';
import { getIO } from '../realtime/socket.js';

const router = express.Router();

// Create order from cart (checkout)
import { validateCheckout } from '../middleware/validate.js';

router.post('/checkout', authenticate, validateCheckout, async (req, res) => {
  const { shippingAddress, paymentMethod, coupon } = req.body;
  const cart = await Cart.findOne({ user: req.user._id }).populate('items.product');
  if (!cart || !cart.items.length) return res.status(400).json({ message: 'Cart is empty' });

  // Calculate subtotal
  let subtotal = 0;
  for (const item of cart.items) {
    subtotal += item.product.price * item.quantity;
  }

  // Shipping logic: $5 base, +$2 per item over 3
  const itemCount = cart.items.reduce((sum, item) => sum + item.quantity, 0);
  let shipping = 5;
  if (itemCount > 3) shipping += (itemCount - 3) * 2;

  // Tax logic: 10% for orders under $100, 8% otherwise
  const taxRate = subtotal < 100 ? 0.10 : 0.08;
  const tax = subtotal * taxRate;

  // Coupon/discount logic
  let discount = 0;
  let couponObj = null;
  if (coupon) {
    const Coupon = (await import('../models/Coupon.js')).default;
    couponObj = await Coupon.findOne({ code: coupon.toUpperCase(), active: true });
    if (couponObj) {
      if (couponObj.expiresAt && couponObj.expiresAt < new Date()) {
        couponObj = null;
      } else if (couponObj.usageLimit && couponObj.usedCount >= couponObj.usageLimit) {
        couponObj = null;
      } else if (subtotal < couponObj.minOrder) {
        couponObj = null;
      } else {
        if (couponObj.discountType === 'percent') {
          discount = (subtotal * couponObj.discountValue) / 100;
        } else {
          discount = couponObj.discountValue;
        }
        // Mark coupon as used
        couponObj.usedCount = (couponObj.usedCount || 0) + 1;
        await couponObj.save();
      }
    }
  }

  const total = Math.max(0, subtotal + shipping + tax - discount);
  const order = new Order({
    user: req.user._id,
    items: cart.items.map(item => ({
      product: item.product._id,
      variantId: item.variantId,
      quantity: item.quantity,
      price: item.product.price
    })),
    shippingAddress,
    paymentMethod,
    subtotal,
    shipping,
    tax,
    discount,
    total,
    status: 'pending',
  });
  try {
    // Save order
    await order.save();
    // Emit real-time event to admin dashboard
    try {
      getIO().to('admins').emit('newOrder', { orderId: order._id, user: req.user._id, total });
    } catch (e) {
      console.error('Socket.IO emit error:', e.message);
    }
    // Clear cart
    cart.items = [];
    await cart.save();
    // Send order confirmation email
    try {
      await sendEmail({
        to: req.user.email,
        subject: `Order Confirmation #${order._id}`,
        html: `<h1>Thank you for your order!</h1><p>Your order #${order._id} has been placed successfully.</p>`
      });
    } catch (e) {
      console.error('Email error:', e.message);
    }
    // Return order
    res.status(201).json({
      ...order.toObject(),
      breakdown: {
        subtotal,
        shipping,
        tax,
        discount,
        finalTotal: total,
        coupon: couponObj ? couponObj.code : null
      }
    });
  } catch (err) {
    res.status(500).json({ message: 'Order creation failed' });
  }
  res.status(201).json({
    ...order.toObject(),
    breakdown: {
      subtotal,
      shipping,
      tax,
      discount,
      finalTotal: total,
      coupon: couponObj ? couponObj.code : null
    }
  });
});

// Get current user's orders
router.get('/me', authenticate, async (req, res) => {
  const orders = await Order.find({ user: req.user.id });
  res.json(orders);
});

// Get single order (user or admin)
router.get('/:id', authenticate, async (req, res) => {
  const order = await Order.findById(req.params.id);
  if (!order) return res.status(404).json({ message: 'Not found' });
  if (order.user.toString() !== req.user.id && req.user.role !== 'admin') return res.status(403).json({ message: 'Forbidden' });
  res.json(order);
});

// Admin: get all orders
router.get('/', authenticate, authorize('admin', 'staff'), async (req, res) => {
  const orders = await Order.find();
  res.json(orders);
});

// Admin: update order status
router.put('/:id', authenticate, authorize('admin', 'staff'), async (req, res) => {
  const { status } = req.body;
  const order = await Order.findByIdAndUpdate(req.params.id, { status }, { new: true });
  if (!order) return res.status(404).json({ message: 'Order not found' });
  await logAdminAction({
    admin: req.user._id,
    action: 'update_order_status',
    targetType: 'Order',
    targetId: order._id,
    details: { status }
  });
  // Emit real-time status update to user (if needed)
  try {
    getIO().to(`user_${order.user}`).emit('orderStatusUpdate', { orderId: order._id, status });
  } catch (e) {
    console.error('Socket.IO emit error:', e.message);
  }
  res.json(order);
});

// Admin: delete order
router.delete('/:id', authenticate, authorize('admin'), async (req, res) => {
  await Order.findByIdAndDelete(req.params.id);
  await logAdminAction({
    admin: req.user._id,
    action: 'delete_order',
    targetType: 'Order',
    targetId: req.params.id
  });
  res.json({ message: 'Order deleted' });
});

export default router;

import express from 'express';
import Cart from '../models/Cart.js';
import { authenticate } from '../middleware/auth.js';

const router = express.Router();

// Get current user's cart
router.get('/me', authenticate, async (req, res) => {
  let cart = await Cart.findOne({ user: req.user.id }).populate('items.product');
  if (!cart) cart = await Cart.create({ user: req.user.id, items: [] });
  res.json(cart);
});

// Add/update item in cart
router.post('/me', authenticate, async (req, res) => {
  const { product, variantId, quantity } = req.body;
  let cart = await Cart.findOne({ user: req.user.id });
  if (!cart) cart = await Cart.create({ user: req.user.id, items: [] });
  const idx = cart.items.findIndex(
    (item) => item.product.toString() === product && item.variantId === variantId
  );
  if (idx > -1) {
    cart.items[idx].quantity = quantity;
  } else {
    cart.items.push({ product, variantId, quantity });
  }
  cart.updatedAt = new Date();
  await cart.save();
  res.json(cart);
});

// Remove item from cart
router.delete('/me/item', authenticate, async (req, res) => {
  const { product, variantId } = req.body;
  let cart = await Cart.findOne({ user: req.user.id });
  if (!cart) return res.status(404).json({ message: 'Cart not found' });
  cart.items = cart.items.filter(
    (item) => !(item.product.toString() === product && item.variantId === variantId)
  );
  cart.updatedAt = new Date();
  await cart.save();
  res.json(cart);
});

// Clear cart
router.delete('/me', authenticate, async (req, res) => {
  let cart = await Cart.findOne({ user: req.user.id });
  if (!cart) return res.status(404).json({ message: 'Cart not found' });
  cart.items = [];
  cart.updatedAt = new Date();
  await cart.save();
  res.json(cart);
});

export default router;

import express from 'express';
import Order from '../models/Order.js';
import Cart from '../models/Cart.js';
import { authenticate, authorize } from '../middleware/auth.js';

const router = express.Router();

// Admin stats endpoint
router.get('/stats', authenticate, authorize('admin', 'staff'), async (req, res) => {
  const sales = await Order.countDocuments({ status: 'delivered' });
  const orders = await Order.countDocuments();
  const revenueAgg = await Order.aggregate([
    { $match: { status: 'delivered' } },
    { $group: { _id: null, total: { $sum: "$total" } } }
  ]);
  const revenue = revenueAgg[0]?.total || 0;
  const abandonedCarts = await Cart.countDocuments({ items: { $ne: [] } });
  res.json({ sales, orders, revenue, abandonedCarts });
});

export default router;

import express from 'express';
import Order from '../models/Order.js';
import Product from '../models/Product.js';
import { authenticate, authorize } from '../middleware/auth.js';

const router = express.Router();

// Analytics dashboard endpoint
router.get('/', authenticate, authorize('admin', 'staff'), async (req, res) => {
  // Top products by sales
  const topProductsAgg = await Order.aggregate([
    { $unwind: "$items" },
    { $group: { _id: "$items.product", sales: { $sum: "$items.quantity" } } },
    { $sort: { sales: -1 } },
    { $limit: 5 },
    { $lookup: { from: "products", localField: "_id", foreignField: "_id", as: "product" } },
    { $unwind: "$product" },
    { $project: { name: "$product.name", sales: 1 } }
  ]);
  // Conversion rate (stub: delivered orders / total orders)
  const orders = await Order.countDocuments();
  const delivered = await Order.countDocuments({ status: 'delivered' });
  const conversionRate = orders ? ((delivered / orders) * 100).toFixed(2) : 0;
  // Total revenue
  const revenueAgg = await Order.aggregate([
    { $match: { status: 'delivered' } },
    { $group: { _id: null, total: { $sum: "$total" } } }
  ]);
  const revenue = revenueAgg[0]?.total || 0;
  // Traffic (stub)
  const traffic = 'N/A';
  res.json({
    topProducts: topProductsAgg,
    conversionRate,
    revenue,
    traffic
  });
});

export default router;

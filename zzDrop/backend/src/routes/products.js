import express from 'express';
import Product from '../models/Product.js';
import { authenticate, authorize } from '../middleware/auth.js';
import logAdminAction from '../utils/adminLog.js';

const router = express.Router();

// Create product (admin/staff)
router.post('/', authenticate, authorize('admin', 'staff'), async (req, res) => {
  const product = new Product(req.body);
  await product.save();
  await logAdminAction({
    admin: req.user._id,
    action: 'create_product',
    targetType: 'Product',
    targetId: product._id,
    details: req.body
  });
  res.status(201).json(product);
});

// Get all products (public, with filters)
router.get('/', async (req, res) => {
  const { category, tag, search, page = 1, limit = 20 } = req.query;
  const filter = {};
  if (category) filter.categories = category;
  if (tag) filter.tags = tag;
  if (search) filter.name = { $regex: search, $options: 'i' };
  const products = await Product.find(filter)
    .skip((page - 1) * limit)
    .limit(Number(limit));
  res.json(products);
});

// Get single product (public)
router.get('/:id', async (req, res) => {
  const product = await Product.findById(req.params.id);
  if (!product) return res.status(404).json({ message: 'Product not found' });
  res.json(product);
});

// Update product (admin/staff)
router.put('/:id', authenticate, authorize('admin', 'staff'), async (req, res) => {
  const product = await Product.findByIdAndUpdate(req.params.id, req.body, { new: true });
  if (!product) return res.status(404).json({ message: 'Product not found' });
  await logAdminAction({
    admin: req.user._id,
    action: 'update_product',
    targetType: 'Product',
    targetId: product._id,
    details: req.body
  });
  res.json(product);
});

// Delete product (admin/staff)
router.delete('/:id', authenticate, authorize('admin', 'staff'), async (req, res) => {
  const product = await Product.findByIdAndDelete(req.params.id);
  await logAdminAction({
    admin: req.user._id,
    action: 'delete_product',
    targetType: 'Product',
    targetId: product._id,
    details: {}
  });
  res.json({ message: 'Product deleted' });
});

export default router;

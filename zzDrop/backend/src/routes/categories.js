import express from 'express';
import Category from '../models/Category.js';
import { authenticate, authorize } from '../middleware/auth.js';

const router = express.Router();

// Create category (admin)
router.post('/', authenticate, authorize('admin'), async (req, res) => {
  const category = await Category.create(req.body);
  res.status(201).json(category);
});

// Get all categories (public)
router.get('/', async (req, res) => {
  const categories = await Category.find();
  res.json(categories);
});

// Update category (admin)
router.put('/:id', authenticate, authorize('admin'), async (req, res) => {
  const category = await Category.findByIdAndUpdate(req.params.id, req.body, { new: true });
  if (!category) return res.status(404).json({ message: 'Not found' });
  res.json(category);
});

// Delete category (admin)
router.delete('/:id', authenticate, authorize('admin'), async (req, res) => {
  await Category.findByIdAndDelete(req.params.id);
  res.json({ message: 'Category deleted' });
});

export default router;

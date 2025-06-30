import express from 'express';
import Tag from '../models/Tag.js';
import { authenticate, authorize } from '../middleware/auth.js';

const router = express.Router();

// Create tag (admin)
router.post('/', authenticate, authorize('admin'), async (req, res) => {
  const tag = await Tag.create(req.body);
  res.status(201).json(tag);
});

// Get all tags (public)
router.get('/', async (req, res) => {
  const tags = await Tag.find();
  res.json(tags);
});

// Update tag (admin)
router.put('/:id', authenticate, authorize('admin'), async (req, res) => {
  const tag = await Tag.findByIdAndUpdate(req.params.id, req.body, { new: true });
  if (!tag) return res.status(404).json({ message: 'Not found' });
  res.json(tag);
});

// Delete tag (admin)
router.delete('/:id', authenticate, authorize('admin'), async (req, res) => {
  await Tag.findByIdAndDelete(req.params.id);
  res.json({ message: 'Tag deleted' });
});

export default router;

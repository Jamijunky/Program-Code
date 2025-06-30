import express from 'express';
import Page from '../models/Page.js';
import { authenticate, authorize } from '../middleware/auth.js';
import logAdminAction from '../utils/adminLog.js';

const router = express.Router();

// Public: get page by slug
router.get('/:slug', async (req, res) => {
  const page = await Page.findOne({ slug: req.params.slug, published: true });
  if (!page) return res.status(404).json({ message: 'Page not found' });
  res.json(page);
});

// Admin: list all pages
router.get('/', authenticate, authorize('admin', 'staff'), async (req, res) => {
  const pages = await Page.find();
  res.json(pages);
});

// Admin: create page
router.post('/', authenticate, authorize('admin', 'staff'), async (req, res) => {
  const page = new Page(req.body);
  await page.save();
  await logAdminAction({
    admin: req.user._id,
    action: 'create_page',
    targetType: 'Page',
    targetId: page._id,
    details: req.body
  });
  res.status(201).json(page);
});

// Admin: update page
router.put('/:id', authenticate, authorize('admin', 'staff'), async (req, res) => {
  const { title, content, published } = req.body;
  const page = await Page.findByIdAndUpdate(
    req.params.id,
    { title, content, published, updatedBy: req.user._id, updatedAt: Date.now() },
    { new: true }
  );
  if (!page) return res.status(404).json({ message: 'Page not found' });
  res.json(page);
});

// Admin: delete page
router.delete('/:id', authenticate, authorize('admin', 'staff'), async (req, res) => {
  await Page.findByIdAndDelete(req.params.id);
  await logAdminAction({
    admin: req.user._id,
    action: 'delete_page',
    targetType: 'Page',
    targetId: req.params.id
  });
  res.json({ message: 'Page deleted' });
});

export default router;

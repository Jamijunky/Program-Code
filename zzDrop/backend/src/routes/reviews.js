import express from 'express';
import Review from '../models/Review.js';
import Product from '../models/Product.js';
import { authenticate, authorize } from '../middleware/auth.js';
import logAdminAction from '../utils/adminLog.js';

const router = express.Router();

// Add a review
router.post('/', authenticate, async (req, res) => {
  const { productId, rating, comment } = req.body;
  const review = await Review.create({
    user: req.user.id,
    product: productId,
    rating,
    comment,
  });
  // Update product rating aggregation
  const reviews = await Review.find({ product: productId });
  const avgRating = reviews.reduce((acc, r) => acc + r.rating, 0) / reviews.length;
  await Product.findByIdAndUpdate(productId, {
    rating: avgRating,
    numReviews: reviews.length,
  });
  res.status(201).json(review);
});

// Get reviews for a product
router.get('/product/:productId', async (req, res) => {
  const reviews = await Review.find({ product: req.params.productId }).populate('user', 'name');
  res.json(reviews);
});

// Update a review (user or admin)
router.put('/:id', authenticate, async (req, res) => {
  const review = await Review.findById(req.params.id);
  if (!review) return res.status(404).json({ message: 'Not found' });
  if (review.user.toString() !== req.user.id && req.user.role !== 'admin') return res.status(403).json({ message: 'Forbidden' });
  review.rating = req.body.rating;
  review.comment = req.body.comment;
  review.updatedAt = new Date();
  await review.save();
  res.json(review);
});

// Delete a review (user or admin)
router.delete('/:id', authenticate, async (req, res) => {
  const review = await Review.findById(req.params.id);
  if (!review) return res.status(404).json({ message: 'Review not found' });
  if (review.user.toString() !== req.user._id.toString() && req.user.role !== 'admin') return res.status(403).json({ message: 'Forbidden' });
  await review.deleteOne();
  // Update product rating
  const product = await Product.findById(review.product);
  if (product) {
    const reviews = await Review.find({ product: product._id });
    product.rating = reviews.length ? (reviews.reduce((sum, r) => sum + r.rating, 0) / reviews.length) : 0;
    product.numReviews = reviews.length;
    await product.save();
  }
  if (req.user.role === 'admin') {
    await logAdminAction({
      admin: req.user._id,
      action: 'delete_review',
      targetType: 'Review',
      targetId: req.params.id
    });
  }
  res.json({ message: 'Review deleted' });
});

// Admin: get all reviews
router.get('/', authenticate, authorize('admin', 'staff'), async (req, res) => {
  const reviews = await Review.find().populate('user', 'name').populate('product', 'name');
  res.json(reviews);
});

export default router;

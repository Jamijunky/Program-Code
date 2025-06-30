import express from 'express';
import Coupon from '../models/Coupon.js';
import { authenticate, authorize } from '../middleware/auth.js';
import logAdminAction from '../utils/adminLog.js';

const router = express.Router();

// Admin: create coupon
router.post('/', authenticate, authorize('admin', 'staff'), async (req, res) => {
  const { code, discountType, discountValue, minOrder, expiresAt, usageLimit, active } = req.body;
  const coupon = new Coupon({ code, discountType, discountValue, minOrder, expiresAt, usageLimit, active });
  await coupon.save();
  await logAdminAction({
    admin: req.user._id,
    action: 'create_coupon',
    targetType: 'Coupon',
    targetId: coupon._id,
    details: { code, discountType, discountValue, minOrder, expiresAt, usageLimit, active }
  });
  res.status(201).json(coupon);
});

// Admin: list all coupons
router.get('/', authenticate, authorize('admin', 'staff'), async (req, res) => {
  const coupons = await Coupon.find();
  res.json(coupons);
});

// Admin: update coupon
router.put('/:id', authenticate, authorize('admin', 'staff'), async (req, res) => {
  const coupon = await Coupon.findByIdAndUpdate(req.params.id, req.body, { new: true });
  if (!coupon) return res.status(404).json({ message: 'Coupon not found' });
  await logAdminAction({
    admin: req.user._id,
    action: 'update_coupon',
    targetType: 'Coupon',
    targetId: coupon._id,
    details: req.body
  });
  res.json(coupon);
});

// Admin: delete coupon
router.delete('/:id', authenticate, authorize('admin', 'staff'), async (req, res) => {
  await Coupon.findByIdAndDelete(req.params.id);
  await logAdminAction({
    admin: req.user._id,
    action: 'delete_coupon',
    targetType: 'Coupon',
    targetId: req.params.id
  });
  res.json({ message: 'Coupon deleted' });
});

// Public: validate coupon
router.post('/validate', authenticate, async (req, res) => {
  const { code, orderTotal } = req.body;
  const coupon = await Coupon.findOne({ code: code.toUpperCase(), active: true });
  if (!coupon) return res.status(404).json({ message: 'Coupon not found' });
  if (coupon.expiresAt && coupon.expiresAt < new Date()) return res.status(400).json({ message: 'Coupon expired' });
  if (coupon.usageLimit && coupon.usedCount >= coupon.usageLimit) return res.status(400).json({ message: 'Coupon usage limit reached' });
  if (orderTotal < coupon.minOrder) return res.status(400).json({ message: `Minimum order ${coupon.minOrder}` });
  res.json({ valid: true, coupon });
});

export default router;

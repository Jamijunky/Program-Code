import express from 'express';
import User from '../models/User.js';
import { authenticate, authorize } from '../middleware/auth.js';
import bcrypt from 'bcryptjs';
import logAdminAction from '../utils/adminLog.js';

const router = express.Router();

// Get all users (admin)
router.get('/', authenticate, authorize('admin'), async (req, res) => {
  const users = await User.find().select('-password');
  res.json(users);
});

// Get profile (self)
router.get('/me', authenticate, async (req, res) => {
  const user = await User.findById(req.user.id).select('-password');
  res.json(user);
});

// Update profile (self)
router.put('/me', authenticate, async (req, res) => {
  const { name, avatar, addresses } = req.body;
  const user = await User.findByIdAndUpdate(
    req.user.id,
    { $set: { name, avatar, addresses, updatedAt: new Date() } },
    { new: true }
  ).select('-password');
  res.json(user);
});

// Change password (self)
router.put('/me/password', authenticate, async (req, res) => {
  const { currentPassword, newPassword } = req.body;
  const user = await User.findById(req.user.id);
  if (!await bcrypt.compare(currentPassword, user.password)) {
    return res.status(400).json({ message: 'Current password incorrect' });
  }
  user.password = await bcrypt.hash(newPassword, 10);
  await user.save();
  res.json({ message: 'Password updated' });
});

// Delete user (admin)
router.delete('/:id', authenticate, authorize('admin'), async (req, res) => {
  await User.findByIdAndDelete(req.params.id);
  await logAdminAction({
    admin: req.user._id,
    action: 'delete_user',
    targetType: 'User',
    targetId: req.params.id
  });
  res.json({ message: 'User deleted' });
});

export default router;

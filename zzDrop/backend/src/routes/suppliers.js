import express from 'express';
import Supplier from '../models/Supplier.js';
import { authenticate, authorize } from '../middleware/auth.js';

const router = express.Router();

// Create supplier (admin)
router.post('/', authenticate, authorize('admin'), async (req, res) => {
  const supplier = await Supplier.create(req.body);
  res.status(201).json(supplier);
});

// Get all suppliers (admin)
router.get('/', authenticate, authorize('admin'), async (req, res) => {
  const suppliers = await Supplier.find();
  res.json(suppliers);
});

// Update supplier (admin)
router.put('/:id', authenticate, authorize('admin'), async (req, res) => {
  const supplier = await Supplier.findByIdAndUpdate(req.params.id, req.body, { new: true });
  if (!supplier) return res.status(404).json({ message: 'Not found' });
  res.json(supplier);
});

// Delete supplier (admin)
router.delete('/:id', authenticate, authorize('admin'), async (req, res) => {
  await Supplier.findByIdAndDelete(req.params.id);
  res.json({ message: 'Supplier deleted' });
});

// Product import stub (AliExpress/Spocket)
router.post('/import', authenticate, authorize('admin', 'staff'), async (req, res) => {
  // In real implementation, integrate with supplier API here
  // For now, just return a stub response
  res.json({ message: 'Product import from supplier stubbed', data: req.body });
});

export default router;

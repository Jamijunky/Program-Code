// Simple express-validator wrapper for common validations
import { body, validationResult } from 'express-validator';

export const validateRegister = [
  body('name').isLength({ min: 2 }).withMessage('Name required'),
  body('email').isEmail().withMessage('Valid email required'),
  body('password').isLength({ min: 6 }).withMessage('Password min 6 chars'),

  (req, res, next) => {
    const errors = validationResult(req);
    if (!errors.isEmpty()) return res.status(400).json({ message: errors.array()[0].msg });
    next();
  }
];

export const validateCheckout = [
  body('shippingAddress.street').notEmpty().withMessage('Street required'),
  body('shippingAddress.city').notEmpty().withMessage('City required'),
  body('shippingAddress.state').notEmpty().withMessage('State required'),
  body('shippingAddress.zip').notEmpty().withMessage('ZIP required'),
  body('shippingAddress.country').notEmpty().withMessage('Country required'),
  body('paymentMethod').isIn(['cod', 'stripe']).withMessage('Invalid payment method'),
  (req, res, next) => {
    const errors = validationResult(req);
    if (!errors.isEmpty()) return res.status(400).json({ message: errors.array()[0].msg });
    next();
  }
];

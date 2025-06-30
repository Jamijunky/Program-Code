import express from 'express';
import cors from 'cors';
import helmet from 'helmet';
import morgan from 'morgan';
import apiLimiter from './middleware/rateLimit.js';
import dotenv from 'dotenv';
import mongoose from 'mongoose';
import { initSocket } from './realtime/socket.js';

// Load env vars
dotenv.config();

const app = express();

// Middleware
app.use(express.json());
app.use(cors());
app.use(helmet());
app.use(morgan('dev'));
app.use(apiLimiter);

// DB Connection
mongoose.connect(process.env.MONGO_URI, {
  useNewUrlParser: true,
  useUnifiedTopology: true,
}).then(() => {
  console.log('MongoDB connected');
}).catch((err) => {
  console.error('MongoDB connection error:', err);
});

// Health check
app.get('/api/health', (req, res) => res.json({ status: 'ok' }));

import authRoutes from './routes/auth.js';
import { authenticate, authorize } from './middleware/auth.js';
import User from './models/User.js';

// Auth routes
app.use('/api/auth', authRoutes);
// Users routes
import usersRoutes from './routes/users.js';
app.use('/api/users', usersRoutes);
// Products routes
import productsRoutes from './routes/products.js';
app.use('/api/products', productsRoutes);
// Reviews routes
import reviewsRoutes from './routes/reviews.js';
app.use('/api/reviews', reviewsRoutes);
// Categories routes
import categoriesRoutes from './routes/categories.js';
app.use('/api/categories', categoriesRoutes);
// Tags routes
import tagsRoutes from './routes/tags.js';
app.use('/api/tags', tagsRoutes);
// Suppliers routes
import suppliersRoutes from './routes/suppliers.js';
app.use('/api/suppliers', suppliersRoutes);
// Carts routes
import cartsRoutes from './routes/carts.js';
app.use('/api/carts', cartsRoutes);
// Orders routes
import ordersRoutes from './routes/orders.js';
app.use('/api/orders', ordersRoutes);
// Admin dashboard routes
import adminRoutes from './routes/admin.js';
app.use('/api/admin', adminRoutes);
// Analytics dashboard routes
import analyticsRoutes from './routes/analytics.js';
app.use('/api/admin/analytics', analyticsRoutes);
// CMS page management routes
import pagesRoutes from './routes/pages.js';
app.use('/api/pages', pagesRoutes);
// Coupon management routes
import couponsRoutes from './routes/coupons.js';
app.use('/api/coupons', couponsRoutes);

const PORT = process.env.PORT || 5050;
const server = app.listen(PORT, () => {
  console.log(`Server running on port ${PORT}`);
});

// Initialize Socket.IO
initSocket(server);

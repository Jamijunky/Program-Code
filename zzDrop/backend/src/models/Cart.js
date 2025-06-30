import mongoose from 'mongoose';

const cartItemSchema = new mongoose.Schema({
  product: { type: mongoose.Schema.Types.ObjectId, ref: 'Product', required: true },
  variantId: { type: String },
  quantity: { type: Number, required: true, min: 1 },
});

const cartSchema = new mongoose.Schema({
  user: { type: mongoose.Schema.Types.ObjectId, ref: 'User' },
  sessionId: String, // for guest carts
  items: [cartItemSchema],
  coupon: String,
  updatedAt: { type: Date, default: Date.now },
});

export default mongoose.model('Cart', cartSchema);

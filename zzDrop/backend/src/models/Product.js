import mongoose from 'mongoose';

const variantSchema = new mongoose.Schema({
  sku: { type: String, required: true },
  options: { type: Map, of: String }, // e.g. { size: 'M', color: 'Red' }
  price: { type: Number, required: true },
  cost: { type: Number },
  stock: { type: Number, default: 0 },
  image: String,
});

const productSchema = new mongoose.Schema({
  professions: [{ type: String }], // e.g., ['doctor', 'engineer']
  featured: { type: Boolean, default: false }, // For banner/featured
  popularity: { type: Number, default: 0 }, // For sorting

  name: { type: String, required: true },
  description: String,
  images: [String],
  categories: [String],
  tags: [String],
  variants: [variantSchema],
  supplier: { type: mongoose.Schema.Types.ObjectId, ref: 'Supplier' },
  reviews: [{ type: mongoose.Schema.Types.ObjectId, ref: 'Review' }],
  rating: { type: Number, default: 0 },
  numReviews: { type: Number, default: 0 },
  active: { type: Boolean, default: true },
  createdAt: { type: Date, default: Date.now },
  updatedAt: { type: Date, default: Date.now },
});

export default mongoose.model('Product', productSchema);

import mongoose from 'mongoose';

const supplierSchema = new mongoose.Schema({
  name: { type: String, required: true },
  apiType: { type: String, enum: ['AliExpress', 'Spocket', 'Zendrop', 'Oberlo', 'Custom'], required: true },
  apiKey: String,
  apiUrl: String,
  contactEmail: String,
  active: { type: Boolean, default: true },
  createdAt: { type: Date, default: Date.now },
  updatedAt: { type: Date, default: Date.now },
});

export default mongoose.model('Supplier', supplierSchema);

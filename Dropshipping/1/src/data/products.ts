export const productData = [
  {
    id: "prod-001",
    name: "Wireless Noise Cancelling Headphones",
    description: "Experience superior sound quality with our premium noise cancelling headphones. Perfect for travel, work, or just enjoying your favorite music without distractions.",
    price: 149.99,
    originalPrice: 199.99,
    image: "https://images.pexels.com/photos/3394650/pexels-photo-3394650.jpeg?auto=compress&cs=tinysrgb&w=1260&h=750&dpr=1",
    category: "Electronics",
    rating: 4.8,
    reviews: 124,
    inStock: true,
    variants: [
      { id: "v-001", name: "Black", inStock: true },
      { id: "v-002", name: "White", inStock: true },
      { id: "v-003", name: "Blue", inStock: false }
    ],
    createdAt: "2023-09-10T12:00:00Z"
  },
  {
    id: "prod-002",
    name: "Smart Fitness Tracker Watch",
    description: "Track your health and fitness goals with this advanced smart watch. Includes heart rate monitoring, sleep tracking, and workout analytics.",
    price: 89.99,
    originalPrice: 119.99,
    image: "https://images.pexels.com/photos/437037/pexels-photo-437037.jpeg?auto=compress&cs=tinysrgb&w=1260&h=750&dpr=1",
    category: "Electronics",
    rating: 4.5,
    reviews: 89,
    inStock: true,
    variants: [
      { id: "v-004", name: "Black", inStock: true },
      { id: "v-005", name: "Pink", inStock: true }
    ],
    createdAt: "2023-09-15T14:30:00Z"
  },
  {
    id: "prod-003",
    name: "Ultra HD 4K Streaming Media Player",
    description: "Transform your TV into a smart entertainment hub with this powerful streaming device. Enjoy thousands of channels and apps in stunning 4K quality.",
    price: 69.99,
    originalPrice: 79.99,
    image: "https://images.pexels.com/photos/333984/pexels-photo-333984.jpeg?auto=compress&cs=tinysrgb&w=1260&h=750&dpr=1",
    category: "Electronics",
    rating: 4.3,
    reviews: 56,
    inStock: true,
    variants: [],
    createdAt: "2023-09-20T09:15:00Z"
  },
  {
    id: "prod-004",
    name: "Premium Cotton T-Shirt",
    description: "Stylish and comfortable 100% organic cotton t-shirt. Durable, soft, and perfect for everyday wear.",
    price: 24.99,
    originalPrice: null,
    image: "https://images.pexels.com/photos/4210866/pexels-photo-4210866.jpeg?auto=compress&cs=tinysrgb&w=1260&h=750&dpr=1",
    category: "Clothing",
    rating: 4.2,
    reviews: 42,
    inStock: true,
    variants: [
      { id: "v-006", name: "Small", inStock: true },
      { id: "v-007", name: "Medium", inStock: true },
      { id: "v-008", name: "Large", inStock: true },
      { id: "v-009", name: "XL", inStock: false }
    ],
    createdAt: "2023-09-25T16:45:00Z"
  },
  {
    id: "prod-005",
    name: "Stainless Steel Water Bottle",
    description: "Eco-friendly double-wall insulated water bottle that keeps drinks cold for 24 hours or hot for 12 hours. Durable and leak-proof.",
    price: 29.99,
    originalPrice: 34.99,
    image: "https://images.pexels.com/photos/1342529/pexels-photo-1342529.jpeg?auto=compress&cs=tinysrgb&w=1260&h=750&dpr=1",
    category: "Home",
    rating: 4.7,
    reviews: 78,
    inStock: true,
    variants: [
      { id: "v-010", name: "500ml", inStock: true },
      { id: "v-011", name: "750ml", inStock: true },
      { id: "v-012", name: "1L", inStock: true }
    ],
    createdAt: "2023-10-01T11:20:00Z"
  },
  {
    id: "prod-006",
    name: "Organic Skincare Set",
    description: "Complete skincare routine with all-natural ingredients. Includes cleanser, toner, serum, and moisturizer for radiant, healthy skin.",
    price: 89.99,
    originalPrice: 109.99,
    image: "https://images.pexels.com/photos/3321416/pexels-photo-3321416.jpeg?auto=compress&cs=tinysrgb&w=1260&h=750&dpr=1",
    category: "Beauty",
    rating: 4.9,
    reviews: 64,
    inStock: true,
    variants: [],
    createdAt: "2023-10-05T13:40:00Z"
  },
  {
    id: "prod-007",
    name: "Bluetooth Portable Speaker",
    description: "Compact yet powerful speaker with impressive bass and 20-hour battery life. Waterproof and perfect for outdoor adventures.",
    price: 59.99,
    originalPrice: 79.99,
    image: "https://images.pexels.com/photos/1706694/pexels-photo-1706694.jpeg?auto=compress&cs=tinysrgb&w=1260&h=750&dpr=1",
    category: "Electronics",
    rating: 4.4,
    reviews: 37,
    inStock: true,
    variants: [
      { id: "v-013", name: "Black", inStock: true },
      { id: "v-014", name: "Blue", inStock: true },
      { id: "v-015", name: "Red", inStock: false }
    ],
    createdAt: "2023-10-10T10:10:00Z"
  },
  {
    id: "prod-008",
    name: "Designer Leather Backpack",
    description: "Stylish and functional backpack made from genuine leather. Features multiple compartments including a padded laptop sleeve.",
    price: 129.99,
    originalPrice: 159.99,
    image: "https://images.pexels.com/photos/1152077/pexels-photo-1152077.jpeg?auto=compress&cs=tinysrgb&w=1260&h=750&dpr=1",
    category: "Clothing",
    rating: 4.6,
    reviews: 52,
    inStock: true,
    variants: [
      { id: "v-016", name: "Brown", inStock: true },
      { id: "v-017", name: "Black", inStock: true }
    ],
    createdAt: "2023-10-15T15:25:00Z"
  },
  {
    id: "prod-009",
    name: "Smart Home Security Camera",
    description: "HD security camera with motion detection, two-way audio, and night vision. Easy to install and monitor from your smartphone.",
    price: 79.99,
    originalPrice: 99.99,
    image: "https://images.pexels.com/photos/371103/pexels-photo-371103.jpeg?auto=compress&cs=tinysrgb&w=1260&h=750&dpr=1",
    category: "Electronics",
    rating: 4.2,
    reviews: 31,
    inStock: true,
    variants: [],
    createdAt: "2023-10-20T09:30:00Z"
  },
  {
    id: "prod-010",
    name: "Aromatherapy Essential Oil Diffuser",
    description: "Ultrasonic diffuser that doubles as a humidifier and mood light. Creates a relaxing atmosphere with your favorite essential oils.",
    price: 39.99,
    originalPrice: 49.99,
    image: "https://images.pexels.com/photos/4046718/pexels-photo-4046718.jpeg?auto=compress&cs=tinysrgb&w=1260&h=750&dpr=1",
    category: "Home",
    rating: 4.7,
    reviews: 48,
    inStock: true,
    variants: [],
    createdAt: "2023-10-25T14:15:00Z"
  },
  {
    id: "prod-011",
    name: "Luxury Scented Candle Set",
    description: "Set of 3 hand-poured soy wax candles with premium fragrances. Long-lasting and beautifully packaged.",
    price: 49.99,
    originalPrice: null,
    image: "https://images.pexels.com/photos/4195509/pexels-photo-4195509.jpeg?auto=compress&cs=tinysrgb&w=1260&h=750&dpr=1",
    category: "Home",
    rating: 4.8,
    reviews: 27,
    inStock: true,
    variants: [],
    createdAt: "2023-11-01T12:35:00Z"
  },
  {
    id: "prod-012",
    name: "Professional Knife Set",
    description: "8-piece chef-quality knife set with stainless steel blades and ergonomic handles. Comes with a wooden storage block.",
    price: 119.99,
    originalPrice: 149.99,
    image: "https://images.pexels.com/photos/3626622/pexels-photo-3626622.jpeg?auto=compress&cs=tinysrgb&w=1260&h=750&dpr=1",
    category: "Home",
    rating: 4.5,
    reviews: 35,
    inStock: true,
    variants: [],
    createdAt: "2023-11-05T10:50:00Z"
  }
];
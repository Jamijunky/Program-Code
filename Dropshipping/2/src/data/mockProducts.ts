import { ProductType } from '../types/product';

export const mockProducts: ProductType[] = [
  {
    id: '1',
    title: 'Premium Wireless Earbuds',
    description: 'High-quality wireless earbuds with noise cancellation and long battery life. Perfect for workouts and daily use.',
    images: [
      'https://images.pexels.com/photos/3780681/pexels-photo-3780681.jpeg?auto=compress&cs=tinysrgb&w=600',
      'https://images.pexels.com/photos/3394666/pexels-photo-3394666.jpeg?auto=compress&cs=tinysrgb&w=600',
      'https://images.pexels.com/photos/2983464/pexels-photo-2983464.jpeg?auto=compress&cs=tinysrgb&w=600'
    ],
    variants: [
      {
        id: '1-1',
        size: 'Standard',
        color: 'Black',
        SKU: 'EARBUD-BLK',
        price: 129.99,
        cost: 65.00,
        inventory: 45
      },
      {
        id: '1-2',
        size: 'Standard',
        color: 'White',
        SKU: 'EARBUD-WHT',
        price: 129.99,
        cost: 65.00,
        inventory: 32
      },
      {
        id: '1-3',
        size: 'Standard',
        color: 'Blue',
        SKU: 'EARBUD-BLU',
        price: 134.99,
        cost: 68.00,
        inventory: 18
      }
    ],
    categories: ['Electronics', 'Audio'],
    tags: ['wireless', 'earbuds', 'noise-cancellation'],
    ratings: [
      {
        userId: 'user1',
        rating: 5,
        review: "Best earbuds I have ever owned! The sound quality is amazing."
      },
      {
        userId: 'user2',
        rating: 4,
        review: 'Great battery life, but they could be a bit more comfortable.'
      },
      {
        userId: 'user3',
        rating: 5,
        review: 'Perfect for my workouts. They never fall out!'
      }
    ]
  },
  {
    id: '2',
    title: 'Smart Fitness Tracker Watch',
    description: 'Track your fitness goals with this advanced smart watch. Features heart rate monitoring, sleep tracking, and smartphone notifications.',
    images: [
      'https://images.pexels.com/photos/437037/pexels-photo-437037.jpeg?auto=compress&cs=tinysrgb&w=600',
      'https://images.pexels.com/photos/393047/pexels-photo-393047.jpeg?auto=compress&cs=tinysrgb&w=600',
      'https://images.pexels.com/photos/266666/pexels-photo-266666.jpeg?auto=compress&cs=tinysrgb&w=600'
    ],
    variants: [
      {
        id: '2-1',
        size: 'Standard',
        color: 'Black',
        SKU: 'FTWATCH-BLK',
        price: 89.99,
        cost: 42.00,
        inventory: 56
      },
      {
        id: '2-2',
        size: 'Standard',
        color: 'Pink',
        SKU: 'FTWATCH-PNK',
        price: 89.99,
        cost: 42.00,
        inventory: 23
      },
      {
        id: '2-3',
        size: 'Standard',
        color: 'Green',
        SKU: 'FTWATCH-GRN',
        price: 89.99,
        cost: 42.00,
        inventory: 14
      }
    ],
    categories: ['Electronics', 'Fitness'],
    tags: ['fitness', 'smartwatch', 'activity tracker'],
    ratings: [
      {
        userId: 'user4',
        rating: 4,
        review: 'Great value for the price. Battery lasts about 5 days.'
      },
      {
        userId: 'user5',
        rating: 3,
        review: 'The tracking is accurate but the app could be better.'
      }
    ]
  },
  {
    id: '3',
    title: 'Minimalist Desk Lamp',
    description: 'Modern desk lamp with adjustable brightness and color temperature. Perfect for home office or bedside table.',
    images: [
      'https://images.pexels.com/photos/1112598/pexels-photo-1112598.jpeg?auto=compress&cs=tinysrgb&w=600',
      'https://images.pexels.com/photos/37347/office-sitting-room-executive-sitting.jpg?auto=compress&cs=tinysrgb&w=600',
      'https://images.pexels.com/photos/5662876/pexels-photo-5662876.jpeg?auto=compress&cs=tinysrgb&w=600'
    ],
    variants: [
      {
        id: '3-1',
        size: 'Standard',
        color: 'White',
        SKU: 'LAMP-WHT',
        price: 49.99,
        cost: 22.50,
        inventory: 38
      },
      {
        id: '3-2',
        size: 'Standard',
        color: 'Black',
        SKU: 'LAMP-BLK',
        price: 49.99,
        cost: 22.50,
        inventory: 42
      }
    ],
    categories: ['Home', 'Lighting'],
    tags: ['desk lamp', 'office', 'modern'],
    ratings: [
      {
        userId: 'user6',
        rating: 5,
        review: 'Sleek design and great functionality. I love the dimmer feature.'
      },
      {
        userId: 'user7',
        rating: 5,
        review: 'Perfect for my minimalist workspace!'
      },
      {
        userId: 'user8',
        rating: 4,
        review: 'Good lamp, but the cord is a bit short for my setup.'
      }
    ]
  },
  {
    id: '4',
    title: 'Premium Yoga Mat',
    description: 'Eco-friendly, non-slip yoga mat with excellent cushioning and grip. Includes carrying strap.',
    images: [
      'https://images.pexels.com/photos/4056535/pexels-photo-4056535.jpeg?auto=compress&cs=tinysrgb&w=600',
      'https://images.pexels.com/photos/4498515/pexels-photo-4498515.jpeg?auto=compress&cs=tinysrgb&w=600',
      'https://images.pexels.com/photos/6787202/pexels-photo-6787202.jpeg?auto=compress&cs=tinysrgb&w=600'
    ],
    variants: [
      {
        id: '4-1',
        size: 'Standard',
        color: 'Purple',
        SKU: 'YOGA-PUR',
        price: 32.99,
        cost: 14.50,
        inventory: 65
      },
      {
        id: '4-2',
        size: 'Standard',
        color: 'Blue',
        SKU: 'YOGA-BLU',
        price: 32.99,
        cost: 14.50,
        inventory: 48
      },
      {
        id: '4-3',
        size: 'Standard',
        color: 'Green',
        SKU: 'YOGA-GRN',
        price: 32.99,
        cost: 14.50,
        inventory: 52
      }
    ],
    categories: ['Fitness', 'Wellness'],
    tags: ['yoga', 'exercise', 'fitness mat'],
    ratings: [
      {
        userId: 'user9',
        rating: 5,
        review: 'This mat has amazing grip, even during hot yoga sessions.'
      },
      {
        userId: 'user10',
        rating: 4,
        review: 'Great thickness and quality, but it has a slight odor at first.'
      }
    ]
  },
  {
    id: '5',
    title: 'Portable Bluetooth Speaker',
    description: 'Waterproof, compact Bluetooth speaker with 20-hour battery life and deep bass output. Perfect for outdoor adventures.',
    images: [
      'https://images.pexels.com/photos/1279107/pexels-photo-1279107.jpeg?auto=compress&cs=tinysrgb&w=600',
      'https://images.pexels.com/photos/1706694/pexels-photo-1706694.jpeg?auto=compress&cs=tinysrgb&w=600',
      'https://images.pexels.com/photos/745972/pexels-photo-745972.jpeg?auto=compress&cs=tinysrgb&w=600'
    ],
    variants: [
      {
        id: '5-1',
        size: 'Standard',
        color: 'Black',
        SKU: 'SPEAK-BLK',
        price: 59.99,
        cost: 28.00,
        inventory: 34
      },
      {
        id: '5-2',
        size: 'Standard',
        color: 'Blue',
        SKU: 'SPEAK-BLU',
        price: 59.99,
        cost: 28.00,
        inventory: 27
      },
      {
        id: '5-3',
        size: 'Standard',
        color: 'Red',
        SKU: 'SPEAK-RED',
        price: 59.99,
        cost: 28.00,
        inventory: 19
      }
    ],
    categories: ['Electronics', 'Audio'],
    tags: ['bluetooth', 'speaker', 'portable', 'waterproof'],
    ratings: [
      {
        userId: 'user11',
        rating: 5,
        review: 'Incredible sound for such a small speaker. Bass is amazing!'
      },
      {
        userId: 'user12',
        rating: 5,
        review: 'Took this camping and it was perfect. Battery lasted all weekend.'
      },
      {
        userId: 'user13',
        rating: 4,
        review: 'Great sound, but the Bluetooth connection sometimes drops.'
      }
    ]
  },
  {
    id: '6',
    title: 'Stainless Steel Water Bottle',
    description: 'Double-walled, vacuum-insulated water bottle that keeps drinks cold for 24 hours or hot for 12 hours. Eco-friendly and BPA-free.',
    images: [
      'https://images.pexels.com/photos/1188649/pexels-photo-1188649.jpeg?auto=compress&cs=tinysrgb&w=600',
      'https://images.pexels.com/photos/2253643/pexels-photo-2253643.jpeg?auto=compress&cs=tinysrgb&w=600',
      'https://images.pexels.com/photos/1282278/pexels-photo-1282278.jpeg?auto=compress&cs=tinysrgb&w=600'
    ],
    variants: [
      {
        id: '6-1',
        size: '20oz',
        color: 'Silver',
        SKU: 'BOTTLE-20-SLV',
        price: 24.99,
        cost: 11.25,
        inventory: 72
      },
      {
        id: '6-2',
        size: '20oz',
        color: 'Black',
        SKU: 'BOTTLE-20-BLK',
        price: 24.99,
        cost: 11.25,
        inventory: 68
      },
      {
        id: '6-3',
        size: '32oz',
        color: 'Silver',
        SKU: 'BOTTLE-32-SLV',
        price: 29.99,
        cost: 13.50,
        inventory: 54
      },
      {
        id: '6-4',
        size: '32oz',
        color: 'Black',
        SKU: 'BOTTLE-32-BLK',
        price: 29.99,
        cost: 13.50,
        inventory: 47
      }
    ],
    categories: ['Home', 'Outdoor'],
    tags: ['water bottle', 'insulated', 'eco-friendly'],
    ratings: [
      {
        userId: 'user14',
        rating: 5,
        review: 'Keeps ice cold all day, even in hot weather. Love it!'
      },
      {
        userId: 'user15',
        rating: 4,
        review: 'Great bottle, but a bit heavy when filled completely.'
      }
    ]
  },
  {
    id: '7',
    title: 'Modern Ceramic Planter Set',
    description: 'Set of 3 minimalist ceramic planters in varying sizes, perfect for succulents and small houseplants. Includes drainage holes.',
    images: [
      'https://images.pexels.com/photos/5699665/pexels-photo-5699665.jpeg?auto=compress&cs=tinysrgb&w=600',
      'https://images.pexels.com/photos/4505168/pexels-photo-4505168.jpeg?auto=compress&cs=tinysrgb&w=600',
      'https://images.pexels.com/photos/9797029/pexels-photo-9797029.jpeg?auto=compress&cs=tinysrgb&w=600'
    ],
    variants: [
      {
        id: '7-1',
        size: 'Small Set',
        color: 'White',
        SKU: 'PLANT-SM-WHT',
        price: 34.99,
        cost: 16.75,
        inventory: 39
      },
      {
        id: '7-2',
        size: 'Small Set',
        color: 'Black',
        SKU: 'PLANT-SM-BLK',
        price: 34.99,
        cost: 16.75,
        inventory: 31
      },
      {
        id: '7-3',
        size: 'Large Set',
        color: 'White',
        SKU: 'PLANT-LG-WHT',
        price: 44.99,
        cost: 21.50,
        inventory: 25
      },
      {
        id: '7-4',
        size: 'Large Set',
        color: 'Black',
        SKU: 'PLANT-LG-BLK',
        price: 44.99,
        cost: 21.50,
        inventory: 23
      }
    ],
    categories: ['Home', 'Garden'],
    tags: ['planters', 'ceramic', 'succulents', 'home decor'],
    ratings: [
      {
        userId: 'user16',
        rating: 5,
        review: 'These planters look so elegant on my bookshelf!'
      },
      {
        userId: 'user17',
        rating: 4,
        review: 'Good quality and nice design, but slightly smaller than expected.'
      },
      {
        userId: 'user18',
        rating: 5,
        review: 'Perfect size for my succulents and the drainage is great.'
      }
    ]
  },
  {
    id: '8',
    title: 'Leather Laptop Sleeve',
    description: 'Premium genuine leather laptop sleeve with soft microfiber interior. Fits most 13-15 inch laptops and includes a front pocket for accessories.',
    images: [
      'https://images.pexels.com/photos/69767/pexels-photo-69767.jpeg?auto=compress&cs=tinysrgb&w=600',
      'https://images.pexels.com/photos/1667088/pexels-photo-1667088.jpeg?auto=compress&cs=tinysrgb&w=600',
      'https://images.pexels.com/photos/5082579/pexels-photo-5082579.jpeg?auto=compress&cs=tinysrgb&w=600'
    ],
    variants: [
      {
        id: '8-1',
        size: '13 inch',
        color: 'Brown',
        SKU: 'SLEEVE-13-BRN',
        price: 59.99,
        cost: 28.50,
        inventory: 42
      },
      {
        id: '8-2',
        size: '13 inch',
        color: 'Black',
        SKU: 'SLEEVE-13-BLK',
        price: 59.99,
        cost: 28.50,
        inventory: 38
      },
      {
        id: '8-3',
        size: '15 inch',
        color: 'Brown',
        SKU: 'SLEEVE-15-BRN',
        price: 69.99,
        cost: 33.50,
        inventory: 29
      },
      {
        id: '8-4',
        size: '15 inch',
        color: 'Black',
        SKU: 'SLEEVE-15-BLK',
        price: 69.99,
        cost: 33.50,
        inventory: 35
      }
    ],
    categories: ['Electronics', 'Accessories'],
    tags: ['laptop sleeve', 'leather', 'computer accessory'],
    ratings: [
      {
        userId: 'user19',
        rating: 5,
        review: 'Beautiful craftsmanship and the leather smells amazing!'
      },
      {
        userId: 'user20',
        rating: 4,
        review: 'Good protection for my MacBook, but a bit pricey.'
      }
    ]
  }
];

export const getProductById = (id: string): ProductType | undefined => {
  return mockProducts.find(product => product.id === id);
};

export const getProductCategories = () => {
  const categories = new Set<string>();
  mockProducts.forEach(product => {
    product.categories.forEach(category => {
      categories.add(category);
    });
  });
  return Array.from(categories).map(name => ({ id: name.toLowerCase(), name }));
};

export const getFilterOptions = () => {
  return [
    {
      name: 'Price',
      options: [
        { id: 'under-25', name: 'Under $25' },
        { id: '25-50', name: '$25 to $50' },
        { id: '50-100', name: '$50 to $100' },
        { id: 'over-100', name: 'Over $100' }
      ]
    },
    {
      name: 'Color',
      options: [
        { id: 'black', name: 'Black' },
        { id: 'white', name: 'White' },
        { id: 'blue', name: 'Blue' },
        { id: 'green', name: 'Green' },
        { id: 'red', name: 'Red' },
        { id: 'purple', name: 'Purple' },
        { id: 'brown', name: 'Brown' },
        { id: 'silver', name: 'Silver' }
      ]
    }
  ];
};
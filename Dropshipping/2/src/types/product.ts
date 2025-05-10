export interface ProductVariant {
  id: string;
  size: string;
  color: string;
  SKU: string;
  price: number;
  cost: number;
  inventory: number;
}

export interface ProductRating {
  userId: string;
  rating: number;
  review: string;
}

export interface ProductType {
  id: string;
  title: string;
  description: string;
  images: string[];
  variants: ProductVariant[];
  categories: string[];
  tags: string[];
  ratings?: ProductRating[];
  supplierId?: string;
}
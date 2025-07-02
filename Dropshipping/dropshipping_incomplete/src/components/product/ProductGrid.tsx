// src/components/product/ProductGrid.tsx
import React from 'react';
import ProductCard from './ProductCard';
import { Product } from '@/types/product';

type ProductGridProps = {
  products: Product[];
  className?: string;
  columns?: 2 | 3 | 4;
};

const ProductGrid: React.FC<ProductGridProps> = ({ 
  products,
  className = '',
  columns = 4
}) => {
  if (!products || products.length === 0) {
    return (
      <div className="py-8 text-center text-gray-500">
        No products found.
      </div>
    );
  }

  const getGridCols = () => {
    switch (columns) {
      case 2:
        return 'grid-cols-1 sm:grid-cols-2';
      case 3:
        return 'grid-cols-1 sm:grid-cols-2 lg:grid-cols-3';
      case 4:
      default:
        return 'grid-cols-1 sm:grid-cols-2 lg:grid-cols-3 xl:grid-cols-4';
    }
  };

  return (
    <div className={`grid ${getGridCols()} gap-4 md:gap-6 ${className}`}>
      {products.map((product) => (
        <ProductCard key={product.id} product={product} />
      ))}
    </div>
  );
};

export default ProductGrid;
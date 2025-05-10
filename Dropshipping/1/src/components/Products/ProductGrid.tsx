import ProductCard from './ProductCard';
import { useEffect, useState } from 'react';
import { productData } from '../../data/products';

interface ProductGridProps {
  category?: string;
  searchQuery?: string;
  sortBy?: string;
}

const ProductGrid = ({ category, searchQuery, sortBy = 'newest' }: ProductGridProps) => {
  const [products, setProducts] = useState(productData);

  useEffect(() => {
    let filteredProducts = [...productData];

    // Filter by category
    if (category) {
      filteredProducts = filteredProducts.filter(product => product.category.toLowerCase() === category.toLowerCase());
    }

    // Filter by search query
    if (searchQuery) {
      const query = searchQuery.toLowerCase();
      filteredProducts = filteredProducts.filter(
        product => 
          product.name.toLowerCase().includes(query) || 
          product.category.toLowerCase().includes(query)
      );
    }

    // Sort products
    if (sortBy === 'price-asc') {
      filteredProducts.sort((a, b) => a.price - b.price);
    } else if (sortBy === 'price-desc') {
      filteredProducts.sort((a, b) => b.price - a.price);
    } else if (sortBy === 'rating') {
      filteredProducts.sort((a, b) => b.rating - a.rating);
    } else {
      // Default: newest
      filteredProducts.sort((a, b) => new Date(b.createdAt).getTime() - new Date(a.createdAt).getTime());
    }

    setProducts(filteredProducts);
  }, [category, searchQuery, sortBy]);

  if (products.length === 0) {
    return (
      <div className="flex h-64 items-center justify-center">
        <p className="text-lg text-gray-500">No products found. Try a different search or category.</p>
      </div>
    );
  }

  return (
    <div className="grid grid-cols-2 gap-4 sm:grid-cols-3 lg:grid-cols-4">
      {products.map((product) => (
        <ProductCard key={product.id} product={product} />
      ))}
    </div>
  );
};

export default ProductGrid;
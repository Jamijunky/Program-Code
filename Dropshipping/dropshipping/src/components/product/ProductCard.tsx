// src/components/product/ProductCard.tsx
import React from 'react';
import Link from 'next/link';
import Image from 'next/image';
import { useCart } from '@/hooks/useCart';
import { useWishlist } from '@/hooks/useWishlist';
import { formatCurrency } from '@/lib/formatters';
import { Product } from '@/types/product';
import { HeartIcon, ShoppingCartIcon, StarIcon } from '@heroicons/react/outline';
import { HeartIcon as HeartSolid } from '@heroicons/react/solid';

type ProductCardProps = {
  product: Product;
  className?: string;
};

const ProductCard: React.FC<ProductCardProps> = ({ product, className = '' }) => {
  const { addToCart } = useCart();
  const { isInWishlist, toggleWishlistItem } = useWishlist();
  
  const inWishlist = isInWishlist(product.id);
  
  const discount = product.compareAtPrice && product.compareAtPrice > product.price
    ? Math.round(((product.compareAtPrice - product.price) / product.compareAtPrice) * 100)
    : 0;
  
  const handleAddToCart = (e: React.MouseEvent) => {
    e.preventDefault();
    e.stopPropagation();
    addToCart(product, 1);
  };
  
  const handleToggleWishlist = (e: React.MouseEvent) => {
    e.preventDefault();
    e.stopPropagation();
    toggleWishlistItem(product);
  };
  
  return (
    <div className={`group relative ${className}`}>
      <Link href={`/shop/product/${product.slug}`} className="block">
        <div className="aspect-w-1 aspect-h-1 w-full overflow-hidden rounded-lg bg-gray-100">
          <div className="relative h-64 w-full">
            <Image 
              src={product.images[0]} 
              alt={product.title}
              fill
              style={{ objectFit: 'cover' }}
              className="group-hover:opacity-75 transition-opacity duration-300"
            />
          </div>
          
          {/* Discount badge */}
          {discount > 0 && (
            <div className="absolute top-2 left-2 bg-red-500 text-white px-2 py-1 text-xs font-bold rounded">
              {discount}% OFF
            </div>
          )}
          
          {/* Wishlist button */}
          <button 
            onClick={handleToggleWishlist}
            className="absolute top-2 right-2 p-2 rounded-full bg-white shadow-md hover:bg-gray-100 transition-colors"
          >
            {inWishlist ? (
              <HeartSolid className="w-5 h-5 text-red-500" />
            ) : (
              <HeartIcon className="w-5 h-5 text-gray-600" />
            )}
          </button>
          
          {/* Quick add to cart */}
          <div className="absolute bottom-4 left-0 right-0 mx-auto w-4/5 opacity-0 group-hover:opacity-100 transition-opacity duration-300">
            <button
              onClick={handleAddToCart}
              className="w-full bg-indigo-600 hover:bg-indigo-700 text-white py-2 px-4 rounded-lg flex items-center justify-center space-x-2 transition-colors"
            >
              <ShoppingCartIcon className="w-5 h-5" />
              <span>Add to Cart</span>
            </button>
          </div>
        </div>
        
        <div className="mt-4 px-1">
          {/* Product title */}
          <h3 className="text-sm font-medium text-gray-900 truncate">{product.title}</h3>
          
          {/* Rating */}
          <div className="flex items-center mt-1">
            <div className="flex items-center">
              {[...Array(5)].map((_, i) => (
                <StarIcon 
                  key={i} 
                  className={`w-4 h-4 ${
                    i < Math.floor(product.rating) ? 'text-yellow-400 fill-yellow-400' : 'text-gray-300'
                  }`} 
                />
              ))}
            </div>
            <span className="text-xs text-gray-500 ml-2">({product.reviewCount})</span>
          </div>
          
          {/* Price */}
          <div className="flex items-end mt-1">
            <span className="text-sm font-medium text-gray-900">{formatCurrency(product.price)}</span>
            {product.compareAtPrice && product.compareAtPrice > product.price && (
              <span className="ml-2 text-xs text-gray-500 line-through">
                {formatCurrency(product.compareAtPrice)}
              </span>
            )}
          </div>
          
          {/* Availability */}
          {product.inStock ? (
            <p className="mt-1 text-xs text-green-600">In Stock</p>
          ) : (
            <p className="mt-1 text-xs text-red-600">Out of Stock</p>
          )}
        </div>
      </Link>
    </div>
  );
};

export default ProductCard;
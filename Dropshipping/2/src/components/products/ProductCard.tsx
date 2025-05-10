import React from 'react';
import { Link } from 'react-router-dom';
import { Heart, ShoppingCart, Star } from 'lucide-react';
import { useCartStore } from '../../stores/cartStore';
import { useWishlistStore } from '../../stores/wishlistStore';
import { ProductType } from '../../types/product';
import Button from '../ui/Button';

interface ProductCardProps {
  product: ProductType;
}

const ProductCard: React.FC<ProductCardProps> = ({ product }) => {
  const { addItem } = useCartStore();
  const { addToWishlist, isInWishlist, removeFromWishlist } = useWishlistStore();
  
  const isWishlisted = isInWishlist(product.id);
  
  const handleAddToCart = (e: React.MouseEvent) => {
    e.preventDefault();
    e.stopPropagation();
    
    // Add first variant by default or handle accordingly
    const defaultVariant = product.variants[0];
    if (defaultVariant) {
      addItem({
        id: product.id,
        title: product.title,
        price: defaultVariant.price,
        image: product.images[0],
        variantId: defaultVariant.id,
        quantity: 1,
        size: defaultVariant.size,
        color: defaultVariant.color,
      });
    }
  };
  
  const handleWishlistToggle = (e: React.MouseEvent) => {
    e.preventDefault();
    e.stopPropagation();
    
    if (isWishlisted) {
      removeFromWishlist(product.id);
    } else {
      addToWishlist(product);
    }
  };
  
  // Get lowest price from variants
  const lowestPrice = Math.min(...product.variants.map(v => v.price));
  
  // Check if any variant has low inventory
  const lowInventory = product.variants.some(v => v.inventory < 5 && v.inventory > 0);
  
  // Get average rating
  const avgRating = product.ratings && product.ratings.length 
    ? product.ratings.reduce((sum, r) => sum + r.rating, 0) / product.ratings.length 
    : 0;
  
  return (
    <div className="group relative rounded-lg overflow-hidden bg-white shadow-sm hover:shadow-md transition-shadow duration-300">
      {/* Wishlist button */}
      <button
        onClick={handleWishlistToggle}
        className="absolute top-3 right-3 z-10 bg-white rounded-full p-1.5 shadow-sm opacity-90 hover:opacity-100 transition-opacity"
        aria-label={isWishlisted ? "Remove from wishlist" : "Add to wishlist"}
      >
        <Heart 
          size={18} 
          className={isWishlisted ? "fill-red-500 text-red-500" : "text-gray-400"} 
        />
      </button>
      
      {/* Product link */}
      <Link to={`/products/${product.id}`} className="block h-full">
        {/* Image container */}
        <div className="relative aspect-[3/4] overflow-hidden bg-gray-100">
          <img
            src={product.images[0]}
            alt={product.title}
            className="w-full h-full object-cover object-center transform group-hover:scale-105 transition-transform duration-300"
          />
          
          {/* Quick add to cart button - appears on hover */}
          <div className="absolute bottom-0 left-0 right-0 p-3 bg-gradient-to-t from-black/50 to-transparent opacity-0 group-hover:opacity-100 transition-opacity duration-300">
            <Button
              variant="primary"
              size="sm"
              fullWidth
              icon={<ShoppingCart size={16} />}
              onClick={handleAddToCart}
            >
              Quick Add
            </Button>
          </div>
          
          {/* Low inventory tag */}
          {lowInventory && (
            <span className="absolute top-3 left-0 bg-warning-500 text-white text-xs font-medium px-2 py-0.5">
              Low Stock
            </span>
          )}
        </div>
        
        {/* Product info */}
        <div className="p-4">
          <h3 className="text-gray-800 font-medium text-sm sm:text-base mb-1 line-clamp-1">
            {product.title}
          </h3>
          
          {/* Ratings */}
          {avgRating > 0 && (
            <div className="flex items-center mb-2">
              {[...Array(5)].map((_, i) => (
                <Star
                  key={i}
                  size={14}
                  className={`${
                    i < Math.floor(avgRating)
                      ? 'text-yellow-400 fill-yellow-400'
                      : i < avgRating
                      ? 'text-yellow-400 fill-yellow-400 opacity-50'
                      : 'text-gray-300'
                  }`}
                />
              ))}
              <span className="text-xs text-gray-500 ml-1">
                ({product.ratings?.length || 0})
              </span>
            </div>
          )}
          
          {/* Price */}
          <div className="mt-1">
            <span className="text-gray-900 font-medium">${lowestPrice.toFixed(2)}</span>
            {product.variants.length > 1 && (
              <span className="text-gray-500 text-sm ml-1">+</span>
            )}
          </div>
          
          {/* Categories/tags */}
          {product.categories && product.categories.length > 0 && (
            <div className="mt-2 flex flex-wrap gap-1">
              {product.categories.slice(0, 2).map((category, index) => (
                <span
                  key={index}
                  className="inline-block bg-gray-100 text-gray-600 text-xs px-2 py-0.5 rounded"
                >
                  {category}
                </span>
              ))}
            </div>
          )}
        </div>
      </Link>
    </div>
  );
};

export default ProductCard;
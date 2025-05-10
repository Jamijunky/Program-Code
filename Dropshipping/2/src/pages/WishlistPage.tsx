import React from 'react';
import { Link } from 'react-router-dom';
import { Heart, ShoppingCart } from 'lucide-react';
import { useWishlistStore } from '../stores/wishlistStore';
import ProductCard from '../components/products/ProductCard';
import Button from '../components/ui/Button';

const WishlistPage: React.FC = () => {
  const { items, clearWishlist } = useWishlistStore();

  if (items.length === 0) {
    return (
      <div className="container mx-auto px-4 py-16 text-center">
        <div className="mb-6 flex justify-center">
          <div className="bg-gray-100 rounded-full p-6">
            <Heart size={64} className="text-gray-400" />
          </div>
        </div>
        <h1 className="text-2xl font-bold text-gray-900 mb-4">Your Wishlist is Empty</h1>
        <p className="text-gray-600 mb-8 max-w-md mx-auto">
          Start adding items to your wishlist by browsing our products and clicking the heart icon.
        </p>
        <Link to="/products">
          <Button variant="primary">Browse Products</Button>
        </Link>
      </div>
    );
  }

  return (
    <div className="bg-gray-50 min-h-screen py-8 md:py-12">
      <div className="container mx-auto px-4">
        <div className="flex justify-between items-center mb-8">
          <h1 className="text-2xl md:text-3xl font-bold text-gray-900">
            My Wishlist ({items.length} {items.length === 1 ? 'item' : 'items'})
          </h1>
          <button
            onClick={clearWishlist}
            className="text-gray-600 hover:text-gray-800 text-sm font-medium"
          >
            Clear wishlist
          </button>
        </div>

        <div className="grid grid-cols-2 md:grid-cols-3 lg:grid-cols-4 gap-4 md:gap-6">
          {items.map(product => (
            <ProductCard key={product.id} product={product} />
          ))}
        </div>
      </div>
    </div>
  );
};

export default WishlistPage;
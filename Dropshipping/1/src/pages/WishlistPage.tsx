import { Link } from 'react-router-dom';
import { Heart, ShoppingBag, ArrowLeft } from 'lucide-react';
import { useWishlist } from '../contexts/WishlistContext';
import { useCart } from '../contexts/CartContext';
import toast from 'react-hot-toast';

const WishlistPage = () => {
  const { wishlistItems, removeFromWishlist } = useWishlist();
  const { addToCart } = useCart();

  const handleAddToCart = (item: any) => {
    addToCart({
      id: item.id,
      name: item.name,
      price: item.price,
      image: item.image,
      quantity: 1,
    });
    toast.success(`${item.name} added to cart`);
  };

  if (wishlistItems.length === 0) {
    return (
      <div className="container mx-auto px-4 py-16 text-center">
        <div className="mx-auto mb-6 flex h-24 w-24 items-center justify-center rounded-full bg-gray-100">
          <Heart className="h-12 w-12 text-gray-400" />
        </div>
        <h1 className="mb-4 text-2xl font-bold">Your wishlist is empty</h1>
        <p className="mb-6 text-gray-600">Browse our products and add your favorites to the wishlist!</p>
        <Link to="/shop" className="btn btn-primary inline-flex items-center">
          <ArrowLeft size={16} className="mr-2" />
          Continue Shopping
        </Link>
      </div>
    );
  }

  return (
    <div className="container mx-auto px-4 py-8">
      <h1 className="mb-8 text-3xl font-bold">My Wishlist</h1>

      <div className="grid grid-cols-1 gap-6 md:grid-cols-2 lg:grid-cols-3 xl:grid-cols-4">
        {wishlistItems.map((item) => (
          <div key={item.id} className="group relative overflow-hidden rounded-lg bg-white shadow-md transition-all hover:shadow-lg">
            <Link to={`/product/${item.id}`} className="block overflow-hidden">
              <div className="relative aspect-square overflow-hidden">
                <img
                  src={item.image}
                  alt={item.name}
                  className="h-full w-full object-cover transition-transform duration-300 group-hover:scale-105"
                />
                <button
                  onClick={(e) => {
                    e.preventDefault();
                    removeFromWishlist(item.id);
                    toast.success(`${item.name} removed from wishlist`);
                  }}
                  className="absolute right-2 top-2 flex h-9 w-9 items-center justify-center rounded-full bg-white shadow-md transition-colors hover:bg-gray-100"
                >
                  <Heart size={18} className="fill-red-500 text-red-500" />
                </button>
              </div>

              <div className="p-4">
                <h3 className="mb-1 text-sm font-medium text-gray-500">{item.category}</h3>
                <h2 className="mb-2 text-base font-semibold text-gray-900 group-hover:text-blue-600">
                  {item.name}
                </h2>
                <div className="mb-2 text-lg font-bold text-gray-900">
                  ${item.price.toFixed(2)}
                </div>

                <button
                  onClick={(e) => {
                    e.preventDefault();
                    handleAddToCart(item);
                  }}
                  className="flex w-full items-center justify-center space-x-2 rounded-full bg-blue-600 px-4 py-2 text-sm font-medium text-white transition-colors hover:bg-blue-700"
                >
                  <ShoppingBag size={16} />
                  <span>Add to Cart</span>
                </button>
              </div>
            </Link>
          </div>
        ))}
      </div>
    </div>
  );
};

export default WishlistPage;
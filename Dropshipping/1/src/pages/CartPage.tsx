import { useEffect } from 'react';
import { Link, useNavigate } from 'react-router-dom';
import { Trash2, ShoppingBag, ChevronRight, ArrowLeft } from 'lucide-react';
import { useCart } from '../contexts/CartContext';

const CartPage = () => {
  const { cartItems, removeFromCart, updateQuantity, getCartTotal } = useCart();
  const navigate = useNavigate();
  
  const totalPrice = getCartTotal();
  const shipping = totalPrice > 50 ? 0 : 5.99;
  const tax = totalPrice * 0.08; // 8% tax
  const orderTotal = totalPrice + shipping + tax;

  useEffect(() => {
    // Scroll to top on page load
    window.scrollTo(0, 0);
  }, []);

  const handleCheckout = () => {
    navigate('/checkout');
  };

  if (cartItems.length === 0) {
    return (
      <div className="container mx-auto px-4 py-16 text-center">
        <div className="mx-auto mb-6 flex h-24 w-24 items-center justify-center rounded-full bg-gray-100">
          <ShoppingBag className="h-12 w-12 text-gray-400" />
        </div>
        <h1 className="mb-4 text-2xl font-bold">Your cart is empty</h1>
        <p className="mb-6 text-gray-600">Looks like you haven't added any products to your cart yet.</p>
        <Link to="/shop" className="btn btn-primary inline-flex items-center">
          <ArrowLeft size={16} className="mr-2" />
          Continue Shopping
        </Link>
      </div>
    );
  }

  return (
    <div className="container mx-auto px-4 py-8">
      <h1 className="mb-8 text-3xl font-bold">Shopping Cart</h1>

      <div className="grid grid-cols-1 gap-8 lg:grid-cols-3">
        {/* Cart Items */}
        <div className="lg:col-span-2">
          <div className="mb-4 rounded-lg border border-gray-200 bg-white">
            {cartItems.map((item) => (
              <div
                key={`${item.id}-${item.variant || ''}`}
                className="flex flex-col border-b border-gray-200 p-4 last:border-b-0 sm:flex-row"
              >
                <div className="mb-4 sm:mb-0 sm:w-24">
                  <Link to={`/product/${item.id}`}>
                    <img
                      src={item.image}
                      alt={item.name}
                      className="h-24 w-24 rounded-md object-cover"
                    />
                  </Link>
                </div>
                <div className="flex-1 sm:ml-4">
                  <div className="flex flex-col justify-between sm:flex-row">
                    <div>
                      <Link
                        to={`/product/${item.id}`}
                        className="font-medium hover:text-blue-600"
                      >
                        {item.name}
                      </Link>
                      {item.variant && (
                        <p className="mt-1 text-sm text-gray-500">
                          Variant: {item.variant}
                        </p>
                      )}
                      <p className="mt-1 font-medium">${item.price.toFixed(2)}</p>
                    </div>
                    <div className="mt-4 flex items-center justify-between sm:mt-0">
                      <div className="flex w-24 items-center rounded-md border border-gray-300">
                        <button
                          onClick={() => updateQuantity(item.id, item.quantity - 1)}
                          className="flex h-8 w-8 items-center justify-center text-gray-600 hover:bg-gray-100"
                        >
                          -
                        </button>
                        <input
                          type="text"
                          value={item.quantity}
                          readOnly
                          className="h-8 w-full border-x border-gray-300 bg-white text-center text-sm text-gray-700 outline-none"
                        />
                        <button
                          onClick={() => updateQuantity(item.id, item.quantity + 1)}
                          className="flex h-8 w-8 items-center justify-center text-gray-600 hover:bg-gray-100"
                        >
                          +
                        </button>
                      </div>
                      <button
                        onClick={() => removeFromCart(item.id)}
                        className="ml-4 text-gray-400 hover:text-red-500"
                        aria-label="Remove item"
                      >
                        <Trash2 size={18} />
                      </button>
                    </div>
                  </div>
                </div>
              </div>
            ))}
          </div>

          <div className="mt-6">
            <Link
              to="/shop"
              className="inline-flex items-center text-blue-600 hover:text-blue-700"
            >
              <ArrowLeft size={16} className="mr-2" />
              Continue Shopping
            </Link>
          </div>
        </div>

        {/* Order Summary */}
        <div>
          <div className="rounded-lg border border-gray-200 bg-white p-6">
            <h2 className="mb-4 text-lg font-bold">Order Summary</h2>
            <div className="space-y-3">
              <div className="flex justify-between">
                <span className="text-gray-600">Subtotal ({cartItems.reduce((total, item) => total + item.quantity, 0)} items)</span>
                <span className="font-medium">${totalPrice.toFixed(2)}</span>
              </div>
              <div className="flex justify-between">
                <span className="text-gray-600">Shipping</span>
                <span className="font-medium">
                  {shipping === 0 ? 'Free' : `$${shipping.toFixed(2)}`}
                </span>
              </div>
              <div className="flex justify-between">
                <span className="text-gray-600">Tax (8%)</span>
                <span className="font-medium">${tax.toFixed(2)}</span>
              </div>
              <div className="border-t border-gray-200 pt-3">
                <div className="flex justify-between">
                  <span className="font-bold">Order Total</span>
                  <span className="font-bold">${orderTotal.toFixed(2)}</span>
                </div>
              </div>

              <button
                onClick={handleCheckout}
                className="mt-6 w-full rounded-md bg-blue-600 py-3 text-center font-medium text-white transition-colors hover:bg-blue-700"
              >
                Proceed to Checkout
              </button>

              <div className="mt-4 rounded-md bg-gray-50 p-3 text-sm text-gray-600">
                <p className="flex items-center">
                  <span className="mr-1">✓</span> Free shipping on orders over $50
                </p>
                <p className="flex items-center">
                  <span className="mr-1">✓</span> 30-day hassle-free returns
                </p>
                <p className="flex items-center">
                  <span className="mr-1">✓</span> Secure checkout
                </p>
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>
  );
};

export default CartPage;
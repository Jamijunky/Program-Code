import React from 'react';
import { Link, useNavigate } from 'react-router-dom';
import { Trash2, ShoppingBag, ChevronLeft, Plus, Minus } from 'lucide-react';
import Button from '../components/ui/Button';
import { useCartStore } from '../stores/cartStore';

const CartPage: React.FC = () => {
  const { items, updateQuantity, removeItem, getTotal } = useCartStore();
  const navigate = useNavigate();
  
  const subtotal = getTotal();
  const shippingEstimate = subtotal > 100 ? 0 : 10;
  const taxEstimate = subtotal * 0.08; // 8% tax rate
  const total = subtotal + shippingEstimate + taxEstimate;
  
  const handleCheckout = () => {
    navigate('/checkout');
  };
  
  if (items.length === 0) {
    return (
      <div className="container mx-auto px-4 py-16 text-center">
        <div className="mb-6 flex justify-center">
          <div className="bg-gray-100 rounded-full p-6">
            <ShoppingBag size={64} className="text-gray-400" />
          </div>
        </div>
        <h1 className="text-2xl font-bold text-gray-900 mb-4">Your Cart is Empty</h1>
        <p className="text-gray-600 mb-8 max-w-md mx-auto">
          Looks like you haven't added any products to your cart yet.
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
        <h1 className="text-2xl md:text-3xl font-bold text-gray-900 mb-8">Shopping Cart</h1>
        
        <div className="flex flex-col lg:flex-row gap-8">
          {/* Cart Items */}
          <div className="lg:w-2/3">
            <div className="bg-white rounded-lg shadow-sm overflow-hidden mb-6">
              <div className="p-6 border-b border-gray-200">
                <div className="flex justify-between items-center">
                  <h2 className="text-lg font-medium text-gray-900">
                    {items.length} {items.length === 1 ? 'Item' : 'Items'}
                  </h2>
                  <Link to="/products" className="text-primary-700 hover:text-primary-800 flex items-center text-sm">
                    <ChevronLeft size={16} className="mr-1" /> Continue Shopping
                  </Link>
                </div>
              </div>
              
              <ul className="divide-y divide-gray-200">
                {items.map((item) => (
                  <li key={item.variantId} className="p-6 flex flex-col sm:flex-row">
                    {/* Product Image */}
                    <div className="sm:w-24 h-24 bg-gray-100 rounded overflow-hidden mb-4 sm:mb-0 flex-shrink-0">
                      <img 
                        src={item.image} 
                        alt={item.title} 
                        className="w-full h-full object-cover object-center"
                      />
                    </div>
                    
                    {/* Product Info */}
                    <div className="sm:ml-6 flex-1">
                      <div className="flex flex-col sm:flex-row sm:justify-between">
                        <div>
                          <h3 className="text-base font-medium text-gray-900">
                            {item.title}
                          </h3>
                          <div className="mt-1 text-sm text-gray-500">
                            {item.size && <span className="mr-4">Size: {item.size}</span>}
                            {item.color && <span>Color: {item.color}</span>}
                          </div>
                        </div>
                        <div className="mt-2 sm:mt-0 text-base font-medium text-gray-900">
                          ${item.price.toFixed(2)}
                        </div>
                      </div>
                      
                      <div className="mt-4 flex justify-between items-center">
                        {/* Quantity Selector */}
                        <div className="flex items-center">
                          <button
                            className="p-1 border border-gray-300 rounded-l-md bg-gray-50 hover:bg-gray-100"
                            onClick={() => {
                              if (item.quantity > 1) {
                                updateQuantity(item.variantId, item.quantity - 1);
                              }
                            }}
                          >
                            <Minus size={16} />
                          </button>
                          <div className="w-10 h-8 border-t border-b border-gray-300 flex items-center justify-center text-gray-900">
                            {item.quantity}
                          </div>
                          <button
                            className="p-1 border border-gray-300 rounded-r-md bg-gray-50 hover:bg-gray-100"
                            onClick={() => {
                              updateQuantity(item.variantId, item.quantity + 1);
                            }}
                          >
                            <Plus size={16} />
                          </button>
                        </div>
                        
                        {/* Remove Button */}
                        <button
                          className="text-gray-500 hover:text-red-500 transition-colors flex items-center text-sm"
                          onClick={() => removeItem(item.variantId)}
                        >
                          <Trash2 size={16} className="mr-1" /> Remove
                        </button>
                      </div>
                    </div>
                  </li>
                ))}
              </ul>
            </div>
          </div>
          
          {/* Order Summary */}
          <div className="lg:w-1/3">
            <div className="bg-white rounded-lg shadow-sm overflow-hidden sticky top-20">
              <div className="p-6 border-b border-gray-200">
                <h2 className="text-lg font-medium text-gray-900">Order Summary</h2>
              </div>
              
              <div className="p-6 space-y-4">
                <div className="flex justify-between text-base">
                  <p className="text-gray-600">Subtotal</p>
                  <p className="text-gray-900 font-medium">${subtotal.toFixed(2)}</p>
                </div>
                <div className="flex justify-between text-base">
                  <p className="text-gray-600">Shipping estimate</p>
                  <p className="text-gray-900 font-medium">
                    {shippingEstimate === 0 ? 'Free' : `$${shippingEstimate.toFixed(2)}`}
                  </p>
                </div>
                <div className="flex justify-between text-base">
                  <p className="text-gray-600">Tax estimate</p>
                  <p className="text-gray-900 font-medium">${taxEstimate.toFixed(2)}</p>
                </div>
                <div className="border-t border-gray-200 pt-4 flex justify-between text-base font-medium">
                  <p className="text-gray-900">Order total</p>
                  <p className="text-primary-700">${total.toFixed(2)}</p>
                </div>
                
                <Button
                  variant="primary"
                  size="lg"
                  fullWidth
                  className="mt-4"
                  onClick={handleCheckout}
                >
                  Proceed to Checkout
                </Button>
                
                <div className="mt-4 text-center text-gray-500 text-sm">
                  <p>
                    By checking out, you agree to our <Link to="/terms" className="text-primary-700 hover:text-primary-800">terms and conditions</Link>
                  </p>
                </div>
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>
  );
};

export default CartPage;
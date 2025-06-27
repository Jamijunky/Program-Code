// src/components/cart/CartSidebar.tsx
import React from 'react';
import Link from 'next/link';
import { useCart } from '@/hooks/useCart';
import { useUI } from '@/hooks/useUI';
import { formatCurrency } from '@/lib/formatters';
import { XIcon, ShoppingBagIcon } from '@heroicons/react/outline';
import Button from '../ui/Button';
import CartItem from './CartItem';

const CartSidebar: React.FC = () => {
  const { cart, removeFromCart, updateQuantity, clearCart } = useCart();
  const { toggleCart, isCartOpen } = useUI();

  const itemCount = cart?.items?.reduce((total, item) => total + item.quantity, 0) || 0;
  const subtotal = cart?.items?.reduce((total, item) => total + (item.price * item.quantity), 0) || 0;

  if (!isCartOpen) return null;

  return (
    <>
      {/* Backdrop */}
      <div 
        className="fixed inset-0 bg-black bg-opacity-50 z-40"
        onClick={toggleCart}
      />
      
      {/* Sidebar */}
      <div className="fixed right-0 top-0 h-full w-full max-w-md bg-white shadow-xl z-50 flex flex-col">
        {/* Header */}
        <div className="flex items-center justify-between p-4 border-b">
          <h2 className="text-lg font-semibold text-gray-900">
            Shopping Cart ({itemCount})
          </h2>
          <button
            onClick={toggleCart}
            className="p-2 text-gray-400 hover:text-gray-600 transition-colors"
          >
            <XIcon className="w-6 h-6" />
          </button>
        </div>

        {/* Cart Items */}
        <div className="flex-1 overflow-y-auto p-4">
          {cart?.items?.length === 0 || !cart?.items ? (
            <div className="flex flex-col items-center justify-center h-full text-gray-500">
              <ShoppingBagIcon className="w-16 h-16 mb-4" />
              <p className="text-lg font-medium mb-2">Your cart is empty</p>
              <p className="text-sm text-center mb-4">
                Add some products to your cart to get started
              </p>
              <Button onClick={toggleCart} className="w-full">
                Continue Shopping
              </Button>
            </div>
          ) : (
            <div className="space-y-4">
              {cart.items.map((item) => (
                <CartItem
                  key={`${item.id}-${item.variant?.id || 'default'}`}
                  item={item}
                  onUpdateQuantity={(quantity) => updateQuantity(item.id, quantity, item.variant)}
                  onRemove={() => removeFromCart(item.id, item.variant)}
                />
              ))}
            </div>
          )}
        </div>

        {/* Footer */}
        {cart?.items && cart.items.length > 0 && (
          <div className="border-t p-4 space-y-4">
            {/* Subtotal */}
            <div className="flex justify-between items-center text-lg font-semibold">
              <span>Subtotal:</span>
              <span>{formatCurrency(subtotal)}</span>
            </div>

            {/* Shipping Notice */}
            <p className="text-sm text-gray-500">
              Shipping and taxes calculated at checkout
            </p>

            {/* Action Buttons */}
            <div className="space-y-2">
              <Link href="/checkout" onClick={toggleCart}>
                <Button fullWidth size="lg">
                  Checkout
                </Button>
              </Link>
              
              <Link href="/cart" onClick={toggleCart}>
                <Button variant="outline" fullWidth>
                  View Cart
                </Button>
              </Link>
            </div>

            {/* Clear Cart */}
            <button
              onClick={clearCart}
              className="w-full text-sm text-red-600 hover:text-red-800 transition-colors"
            >
              Clear Cart
            </button>
          </div>
        )}
      </div>
    </>
  );
};

export default CartSidebar;
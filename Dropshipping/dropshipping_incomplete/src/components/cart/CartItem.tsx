// src/components/cart/CartItem.tsx
import React from 'react';
import Image from 'next/image';
import Link from 'next/link';
import { formatCurrency } from '@/lib/formatters';
import { CartItem as CartItemType } from '@/types/cart';
import { TrashIcon, MinusIcon, PlusIcon } from '@heroicons/react/outline';

interface CartItemProps {
  item: CartItemType;
  onUpdateQuantity: (quantity: number) => void;
  onRemove: () => void;
  showRemoveButton?: boolean;
}

const CartItem: React.FC<CartItemProps> = ({
  item,
  onUpdateQuantity,
  onRemove,
  showRemoveButton = true
}) => {
  const handleQuantityChange = (change: number) => {
    const newQuantity = item.quantity + change;
    if (newQuantity > 0) {
      onUpdateQuantity(newQuantity);
    }
  };

  const itemTotal = item.price * item.quantity;

  return (
    <div className="flex items-start space-x-4 py-4 border-b border-gray-200 last:border-b-0">
      {/* Product Image */}
      <div className="flex-shrink-0 w-16 h-16 relative">
        <Image
          src={item.image}
          alt={item.title}
          fill
          style={{ objectFit: 'cover' }}
          className="rounded-lg"
        />
      </div>

      {/* Product Details */}
      <div className="flex-1 min-w-0">
        <Link 
          href={`/shop/product/${item.slug}`}
          className="text-sm font-medium text-gray-900 hover:text-indigo-600 transition-colors"
        >
          {item.title}
        </Link>

        {/* Variant Info */}
        {item.variant && (
          <div className="mt-1 text-xs text-gray-500 space-x-2">
            {item.variant.size && <span>Size: {item.variant.size}</span>}
            {item.variant.color && <span>Color: {item.variant.color}</span>}
          </div>
        )}

        {/* Price */}
        <div className="mt-1 flex items-center space-x-2">
          <span className="text-sm font-medium text-gray-900">
            {formatCurrency(item.price)}
          </span>
          {item.compareAtPrice && item.compareAtPrice > item.price && (
            <span className="text-xs text-gray-500 line-through">
              {formatCurrency(item.compareAtPrice)}
            </span>
          )}
        </div>

        {/* Quantity Controls */}
        <div className="mt-2 flex items-center justify-between">
          <div className="flex items-center border border-gray-300 rounded-lg">
            <button
              onClick={() => handleQuantityChange(-1)}
              className="p-1 text-gray-500 hover:text-gray-700 transition-colors"
              disabled={item.quantity <= 1}
            >
              <MinusIcon className="w-4 h-4" />
            </button>
            
            <span className="px-3 py-1 text-sm font-medium text-gray-900 min-w-[3rem] text-center">
              {item.quantity}
            </span>
            
            <button
              onClick={() => handleQuantityChange(1)}
              className="p-1 text-gray-500 hover:text-gray-700 transition-colors"
            >
              <PlusIcon className="w-4 h-4" />
            </button>
          </div>

          {/* Item Total */}
          <div className="text-sm font-medium text-gray-900">
            {formatCurrency(itemTotal)}
          </div>
        </div>
      </div>

      {/* Remove Button */}
      {showRemoveButton && (
        <button
          onClick={onRemove}
          className="p-1 text-gray-400 hover:text-red-600 transition-colors"
        >
          <TrashIcon className="w-5 h-5" />
        </button>
      )}
    </div>
  );
};

export default CartItem;
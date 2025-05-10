import { create } from 'zustand';
import { persist } from 'zustand/middleware';
import { ProductType } from '../types/product';

interface WishlistStore {
  items: ProductType[];
  addToWishlist: (product: ProductType) => void;
  removeFromWishlist: (productId: string) => void;
  clearWishlist: () => void;
  isInWishlist: (productId: string) => boolean;
}

export const useWishlistStore = create<WishlistStore>()(
  persist(
    (set, get) => ({
      items: [],
      
      addToWishlist: (product) => {
        set((state) => {
          // Check if product already exists in wishlist
          if (state.items.some(item => item.id === product.id)) {
            return state;
          }
          
          return { items: [...state.items, product] };
        });
      },
      
      removeFromWishlist: (productId) => {
        set((state) => ({
          items: state.items.filter((item) => item.id !== productId),
        }));
      },
      
      clearWishlist: () => {
        set({ items: [] });
      },
      
      isInWishlist: (productId) => {
        return get().items.some(item => item.id === productId);
      },
    }),
    {
      name: 'wishlist-storage',
    }
  )
);
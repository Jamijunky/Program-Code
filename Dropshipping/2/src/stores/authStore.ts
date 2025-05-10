import { create } from 'zustand';
import { persist } from 'zustand/middleware';

export interface User {
  id: string;
  email: string;
  name?: string;
  role: 'customer' | 'admin' | 'staff';
}

interface AuthStore {
  user: User | null;
  isAuthenticated: boolean;
  token: string | null;
  login: (email: string, password: string) => Promise<void>;
  signup: (email: string, password: string, name: string) => Promise<void>;
  logout: () => void;
  updateUser: (userData: Partial<User>) => void;
}

export const useAuthStore = create<AuthStore>()(
  persist(
    (set) => ({
      user: null,
      isAuthenticated: false,
      token: null,
      
      login: async (email, password) => {
        // In a real app, this would make an API call to authenticate
        // For demo purposes, we'll simulate a successful login
        const mockUser: User = {
          id: '1',
          email,
          name: 'Demo User',
          role: 'customer',
        };
        
        const mockToken = 'mock-jwt-token';
        
        // Simulate API delay
        await new Promise(resolve => setTimeout(resolve, 500));
        
        set({
          user: mockUser,
          isAuthenticated: true,
          token: mockToken,
        });
      },
      
      signup: async (email, password, name) => {
        // In a real app, this would make an API call to register
        // For demo purposes, we'll simulate a successful signup
        const mockUser: User = {
          id: '1',
          email,
          name,
          role: 'customer',
        };
        
        const mockToken = 'mock-jwt-token';
        
        // Simulate API delay
        await new Promise(resolve => setTimeout(resolve, 800));
        
        set({
          user: mockUser,
          isAuthenticated: true,
          token: mockToken,
        });
      },
      
      logout: () => {
        set({
          user: null,
          isAuthenticated: false,
          token: null,
        });
      },
      
      updateUser: (userData) => {
        set((state) => ({
          user: state.user ? { ...state.user, ...userData } : null,
        }));
      },
    }),
    {
      name: 'auth-storage',
    }
  )
);
// src/components/layout/Header.tsx
import React, { useState, useEffect } from 'react';
import Link from 'next/link';
import Image from 'next/image';
import { useRouter } from 'next/router';
import { useAuth } from '@/hooks/useAuth';
import { useCart } from '@/hooks/useCart';
import { useUI } from '@/hooks/useUI';
import Button from '../ui/Button';
import Dropdown from '../ui/Dropdown';
import { SearchIcon, ShoppingCartIcon, UserIcon, HeartIcon, MenuIcon, BellIcon } from '@heroicons/react/outline';

type HeaderProps = {
  isAdmin?: boolean;
};

const Header: React.FC<HeaderProps> = ({ isAdmin = false }) => {
  const router = useRouter();
  const { user, logout } = useAuth();
  const { cart } = useCart();
  const { toggleCart, toggleSidebar } = useUI();
  const [isScrolled, setIsScrolled] = useState(false);
  const [searchTerm, setSearchTerm] = useState('');
  
  // Number of items in cart
  const cartItemsCount = cart?.items?.reduce((total, item) => total + item.quantity, 0) || 0;
  
  // Handle scroll events for sticky header
  useEffect(() => {
    const handleScroll = () => {
      setIsScrolled(window.scrollY > 10);
    };
    
    window.addEventListener('scroll', handleScroll);
    return () => window.removeEventListener('scroll', handleScroll);
  }, []);
  
  // Handle search form submission
  const handleSearch = (e: React.FormEvent) => {
    e.preventDefault();
    if (searchTerm.trim()) {
      router.push(`/shop?search=${encodeURIComponent(searchTerm)}`);
    }
  };
  
  if (isAdmin) {
    return (
      <header className="bg-white border-b border-gray-200 sticky top-0 z-30">
        <div className="px-4 py-3 flex items-center justify-between">
          <div className="flex items-center">
            <button 
              onClick={toggleSidebar} 
              className="p-2 mr-4 text-gray-500 hover:text-gray-700"
            >
              <MenuIcon className="w-6 h-6" />
            </button>
            <Link href="/admin" className="font-bold text-xl text-gray-800">Admin Dashboard</Link>
          </div>
          
          <div className="flex items-center space-x-4">
            <button className="p-2 text-gray-500 hover:text-gray-700 relative">
              <BellIcon className="w-6 h-6" />
              <span className="absolute top-1 right-1 bg-red-500 rounded-full w-2 h-2"></span>
            </button>
            
            <Dropdown 
              trigger={
                <div className="flex items-center cursor-pointer">
                  <div className="w-8 h-8 rounded-full bg-gray-200 flex items-center justify-center text-gray-700">
                    {user?.name?.charAt(0) || 'A'}
                  </div>
                </div>
              }
              items={[
                { label: 'Profile', onClick: () => router.push('/admin/profile') },
                { label: 'Settings', onClick: () => router.push('/admin/settings') },
                { label: 'Visit Store', onClick: () => router.push('/') },
                { label: 'Logout', onClick: logout }
              ]}
            />
          </div>
        </div>
      </header>
    );
  }
  
  return (
    <header 
      className={`w-full transition-all duration-300 z-30 ${
        isScrolled ? 'sticky top-0 bg-white shadow-md' : 'bg-white'
      }`}
    >
      {/* Top bar with announcement */}
      <div className="bg-indigo-600 text-white text-center py-2 text-xs md:text-sm">
        Free shipping on all orders over $50! Limited time offer.
      </div>
      
      {/* Main header */}
      <div className="container mx-auto px-4 py-4">
        <div className="flex flex-col md:flex-row items-center justify-between space-y-4 md:space-y-0">
          {/* Left - Logo */}
          <div className="flex-shrink-0">
            <Link href="/" className="flex items-center">
              <Image src="/logo.svg" alt="Dropship Store" width={40} height={40} />
              <span className="ml-2 text-2xl font-bold text-gray-800">DropShip</span>
            </Link>
          </div>
          
          {/* Middle - Search */}
          <div className="w-full md:w-1/2 lg:w-2/5">
            <form onSubmit={handleSearch} className="relative">
              <input
                type="text"
                placeholder="Search for products..."
                className="w-full py-2 pl-4 pr-10 border rounded-lg focus:outline-none focus:ring-2 focus:ring-indigo-500"
                value={searchTerm}
                onChange={(e) => setSearchTerm(e.target.value)}
              />
              <button 
                type="submit" 
                className="absolute right-0 top-0 h-full px-3 text-gray-500 hover:text-indigo-600"
              >
                <SearchIcon className="w-5 h-5" />
              </button>
            </form>
          </div>
          
          {/* Right - Nav Links & Cart */}
          <div className="flex items-center space-x-4">
            <Link href="/shop" className="hidden md:block text-gray-700 hover:text-indigo-600">
              Shop
            </Link>
            <Link href="/about" className="hidden md:block text-gray-700 hover:text-indigo-600">
              About
            </Link>
            <Link href="/contact" className="hidden md:block text-gray-700 hover:text-indigo-600">
              Contact
            </Link>
            
            {/* Wishlist Button */}
            <Link href="/account/wishlist" className="p-2 text-gray-700 hover:text-indigo-600">
              <HeartIcon className="w-6 h-6" />
            </Link>
            
            {/* Cart Button */}
            <button 
              onClick={toggleCart} 
              className="p-2 text-gray-700 hover:text-indigo-600 relative"
            >
              <ShoppingCartIcon className="w-6 h-6" />
              {cartItemsCount > 0 && (
                <span className="absolute -top-1 -right-1 bg-indigo-600 text-white text-xs w-5 h-5 flex items-center justify-center rounded-full">
                  {cartItemsCount > 9 ? '9+' : cartItemsCount}
                </span>
              )}
            </button>
            
            {/* User Menu */}
            {user ? (
              <Dropdown
                trigger={
                  <button className="p-2 text-gray-700 hover:text-indigo-600">
                    <UserIcon className="w-6 h-6" />
                  </button>
                }
                items={[
                  { label: 'My Account', onClick: () => router.push('/account') },
                  { label: 'My Orders', onClick: () => router.push('/account/orders') },
                  { label: 'Wishlist', onClick: () => router.push('/account/wishlist') },
                  { label: 'Logout', onClick: logout }
                ]}
              />
            ) : (
              <Link href="/auth/login" className="p-2 text-gray-700 hover:text-indigo-600">
                <UserIcon className="w-6 h-6" />
              </Link>
            )}
          </div>
        </div>
      </div>
      
      {/* Categories navigation bar */}
      <nav className="bg-gray-100 py-3 hidden md:block">
        <div className="container mx-auto px-4">
          <ul className="flex flex-wrap items-center justify-center space-x-8">
            <li><Link href="/shop/category/electronics" className="text-gray-700 hover:text-indigo-600">Electronics</Link></li>
            <li><Link href="/shop/category/fashion" className="text-gray-700 hover:text-indigo-600">Fashion</Link></li>
            <li><Link href="/shop/category/home" className="text-gray-700 hover:text-indigo-600">Home & Decor</Link></li>
            <li><Link href="/shop/category/beauty" className="text-gray-700 hover:text-indigo-600">Beauty</Link></li>
            <li><Link href="/shop/category/toys" className="text-gray-700 hover:text-indigo-600">Toys</Link></li>
            <li><Link href="/shop/category/sports" className="text-gray-700 hover:text-indigo-600">Sports</Link></li>
            <li><Link href="/shop" className="text-gray-700 hover:text-indigo-600">All Categories</Link></li>
          </ul>
        </div>
      </nav>
    </header>
  );
};

export default Header;
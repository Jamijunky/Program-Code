import React, { useState, useEffect } from 'react';
import { Link, useLocation } from 'react-router-dom';
import { Search, ShoppingCart, User, Heart, Menu, X } from 'lucide-react';
import { useCartStore } from '../../stores/cartStore';
import { useAuthStore } from '../../stores/authStore';
import { useWishlistStore } from '../../stores/wishlistStore';

type HeaderProps = {
  simplified?: boolean;
};

const Header: React.FC<HeaderProps> = ({ simplified = false }) => {
  const [isScrolled, setIsScrolled] = useState(false);
  const [mobileMenuOpen, setMobileMenuOpen] = useState(false);
  const [searchOpen, setSearchOpen] = useState(false);
  const location = useLocation();
  const { items } = useCartStore();
  const { isAuthenticated } = useAuthStore();
  const { items: wishlistItems } = useWishlistStore();
  
  const cartItemCount = items.reduce((total, item) => total + item.quantity, 0);
  const wishlistItemCount = wishlistItems.length;

  useEffect(() => {
    const handleScroll = () => {
      setIsScrolled(window.scrollY > 10);
    };

    window.addEventListener('scroll', handleScroll);
    return () => {
      window.removeEventListener('scroll', handleScroll);
    };
  }, []);

  useEffect(() => {
    // Close mobile menu when route changes
    setMobileMenuOpen(false);
    setSearchOpen(false);
  }, [location.pathname]);

  const headerClasses = `
    sticky top-0 z-50 w-full transition-all duration-300
    ${isScrolled ? 'bg-white shadow-md' : 'bg-white/80 backdrop-blur-sm'}
  `;

  return (
    <header className={headerClasses}>
      <div className="container mx-auto px-4">
        <div className="flex items-center justify-between h-16 md:h-20">
          {/* Logo */}
          <Link 
            to="/" 
            className="flex items-center space-x-2 text-primary-700 font-bold text-xl md:text-2xl"
          >
            <span className="hidden sm:inline">ShipSmart</span>
            <span className="sm:hidden">SS</span>
          </Link>

          {/* Desktop Navigation - hide on simplified header */}
          {!simplified && (
            <nav className="hidden md:flex items-center space-x-8">
              <Link 
                to="/products" 
                className="text-gray-700 hover:text-primary-700 transition-colors"
              >
                Products
              </Link>
              <Link 
                to="/products?category=trending" 
                className="text-gray-700 hover:text-primary-700 transition-colors"
              >
                Trending
              </Link>
              <Link 
                to="/products?category=new" 
                className="text-gray-700 hover:text-primary-700 transition-colors"
              >
                New Arrivals
              </Link>
              <Link 
                to="/products?category=sale" 
                className="text-gray-700 hover:text-primary-700 transition-colors"
              >
                Sale
              </Link>
            </nav>
          )}

          {/* Right Section: Search, Wishlist, Cart, User */}
          <div className="flex items-center space-x-4">
            {!simplified && (
              <>
                <button 
                  className="text-gray-600 hover:text-primary-700 transition-colors hidden md:block"
                  onClick={() => setSearchOpen(!searchOpen)}
                  aria-label="Search"
                >
                  <Search size={20} />
                </button>
                
                <Link 
                  to="/wishlist" 
                  className="text-gray-600 hover:text-primary-700 transition-colors relative hidden md:block"
                  aria-label="Wishlist"
                >
                  <Heart size={20} />
                  {wishlistItemCount > 0 && (
                    <span className="absolute -top-2 -right-2 bg-primary-700 text-white text-xs rounded-full h-5 w-5 flex items-center justify-center">
                      {wishlistItemCount}
                    </span>
                  )}
                </Link>
              </>
            )}
            
            <Link 
              to="/cart" 
              className="text-gray-600 hover:text-primary-700 transition-colors relative"
              aria-label="Cart"
            >
              <ShoppingCart size={20} />
              {cartItemCount > 0 && (
                <span className="absolute -top-2 -right-2 bg-cta-600 text-white text-xs rounded-full h-5 w-5 flex items-center justify-center animate-pulse-slow">
                  {cartItemCount}
                </span>
              )}
            </Link>
            
            {isAuthenticated ? (
              <Link 
                to="/profile" 
                className="text-gray-600 hover:text-primary-700 transition-colors"
                aria-label="User Profile"
              >
                <User size={20} />
              </Link>
            ) : (
              <Link 
                to="/login" 
                className="text-gray-700 hover:text-primary-700 transition-colors hidden md:block"
              >
                Login
              </Link>
            )}
            
            {/* Mobile menu button - hide on simplified header */}
            {!simplified && (
              <button 
                className="text-gray-600 hover:text-primary-700 transition-colors md:hidden"
                onClick={() => setMobileMenuOpen(!mobileMenuOpen)}
                aria-label={mobileMenuOpen ? "Close menu" : "Open menu"}
              >
                {mobileMenuOpen ? <X size={24} /> : <Menu size={24} />}
              </button>
            )}
          </div>
        </div>

        {/* Search Bar - Desktop */}
        {searchOpen && !simplified && (
          <div className="hidden md:block border-t border-gray-100 py-4 animate-fade-in">
            <div className="max-w-2xl mx-auto">
              <div className="relative">
                <input
                  type="text"
                  placeholder="Search products..."
                  className="w-full pl-10 pr-4 py-2 rounded-lg border border-gray-200 focus:outline-none focus:ring-2 focus:ring-primary-500"
                />
                <Search className="absolute left-3 top-2.5 text-gray-400" size={18} />
              </div>
            </div>
          </div>
        )}
      </div>

      {/* Mobile Menu */}
      {mobileMenuOpen && !simplified && (
        <div className="md:hidden bg-white border-t border-gray-100 animate-fade-in">
          <div className="container mx-auto px-4 py-3 space-y-3">
            <div className="relative mb-4">
              <input
                type="text"
                placeholder="Search products..."
                className="w-full pl-10 pr-4 py-2 rounded-lg border border-gray-200 focus:outline-none focus:ring-2 focus:ring-primary-500"
              />
              <Search className="absolute left-3 top-2.5 text-gray-400" size={18} />
            </div>
            <Link 
              to="/products" 
              className="block py-2 text-gray-700 hover:text-primary-700"
            >
              Products
            </Link>
            <Link 
              to="/products?category=trending" 
              className="block py-2 text-gray-700 hover:text-primary-700"
            >
              Trending
            </Link>
            <Link 
              to="/products?category=new" 
              className="block py-2 text-gray-700 hover:text-primary-700"
            >
              New Arrivals
            </Link>
            <Link 
              to="/products?category=sale" 
              className="block py-2 text-gray-700 hover:text-primary-700"
            >
              Sale
            </Link>
            {isAuthenticated && (
              <Link 
                to="/wishlist" 
                className="block py-2 text-gray-700 hover:text-primary-700"
              >
                Wishlist
              </Link>
            )}
            {!isAuthenticated && (
              <div className="pt-2 border-t border-gray-100">
                <Link 
                  to="/login" 
                  className="block py-2 text-primary-700 font-medium"
                >
                  Login
                </Link>
                <Link 
                  to="/signup" 
                  className="block py-2 text-primary-700 font-medium"
                >
                  Sign Up
                </Link>
              </div>
            )}
          </div>
        </div>
      )}
    </header>
  );
};

export default Header;
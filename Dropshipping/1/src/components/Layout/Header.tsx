import { useState } from 'react';
import { Link, useNavigate } from 'react-router-dom';
import { Menu, X, Search, ShoppingCart, User, ChevronDown, Package, Heart } from 'lucide-react';
import { useCart } from '../../contexts/CartContext';
import NavMenu from './NavMenu';

interface HeaderProps {
  isAuthenticated: boolean;
}

const Header = ({ isAuthenticated }: HeaderProps) => {
  const [isMenuOpen, setIsMenuOpen] = useState(false);
  const [searchQuery, setSearchQuery] = useState('');
  const { cartItems } = useCart();
  const navigate = useNavigate();

  const toggleMenu = () => setIsMenuOpen(!isMenuOpen);
  const closeMenu = () => setIsMenuOpen(false);

  const handleSearch = (e: React.FormEvent) => {
    e.preventDefault();
    if (searchQuery.trim()) {
      navigate(`/shop?q=${encodeURIComponent(searchQuery.trim())}`);
      setSearchQuery('');
      closeMenu();
    }
  };

  const totalItems = cartItems.reduce((total, item) => total + item.quantity, 0);

  return (
    <header className="sticky top-0 z-50 w-full bg-white shadow-sm">
      <div className="bg-blue-600 py-2">
        <div className="container mx-auto px-4">
          <p className="text-center text-sm text-white">Free shipping on orders over $50 | 30-day returns</p>
        </div>
      </div>

      <div className="container mx-auto px-4">
        <div className="flex h-16 items-center justify-between">
          {/* Logo */}
          <Link to="/" className="flex items-center space-x-2">
            <Package className="h-6 w-6 text-blue-600" />
            <span className="text-xl font-bold">DropMarket</span>
          </Link>

          {/* Desktop Navigation */}
          <nav className="hidden md:flex md:items-center md:space-x-8">
            <NavMenu />
          </nav>

          {/* Search Bar - Desktop */}
          <div className="hidden flex-1 max-w-md px-6 lg:block">
            <form onSubmit={handleSearch} className="relative">
              <input
                type="text"
                value={searchQuery}
                onChange={(e) => setSearchQuery(e.target.value)}
                placeholder="Search products..."
                className="input w-full pr-10"
              />
              <button type="submit" className="absolute right-0 top-0 mr-3 flex h-10 items-center">
                <Search size={18} />
              </button>
            </form>
          </div>

          {/* Right Icons */}
          <div className="flex items-center space-x-4">
            <Link to="/wishlist" className="hidden md:flex items-center text-gray-700 hover:text-blue-600">
              <Heart size={20} />
            </Link>
            <Link to="/cart" className="relative flex items-center text-gray-700 hover:text-blue-600">
              <ShoppingCart size={20} />
              {totalItems > 0 && (
                <span className="absolute -right-2 -top-2 flex h-5 w-5 items-center justify-center rounded-full bg-accent-500 text-xs font-bold text-white">
                  {totalItems}
                </span>
              )}
            </Link>
            {isAuthenticated ? (
              <Link to="/account" className="flex items-center text-gray-700 hover:text-blue-600">
                <User size={20} />
              </Link>
            ) : (
              <Link to="/login" className="hidden md:block btn btn-primary">
                Sign In
              </Link>
            )}

            {/* Mobile menu button */}
            <button onClick={toggleMenu} className="md:hidden">
              {isMenuOpen ? <X size={24} /> : <Menu size={24} />}
            </button>
          </div>
        </div>
      </div>

      {/* Mobile menu */}
      {isMenuOpen && (
        <div className="animate-fade-in md:hidden">
          <div className="container mx-auto px-4 py-4">
            <form onSubmit={handleSearch} className="mb-4 relative">
              <input
                type="text"
                value={searchQuery}
                onChange={(e) => setSearchQuery(e.target.value)}
                placeholder="Search products..."
                className="input w-full pr-10"
              />
              <button type="submit" className="absolute right-0 top-0 mr-3 flex h-10 items-center">
                <Search size={18} />
              </button>
            </form>

            <nav className="flex flex-col space-y-4">
              <Link to="/" className="py-2 text-lg" onClick={closeMenu}>
                Home
              </Link>
              <div className="relative py-2">
                <div className="flex items-center justify-between text-lg">
                  <Link to="/shop" onClick={closeMenu}>
                    Shop
                  </Link>
                  <ChevronDown size={16} />
                </div>
              </div>
              <Link to="/about" className="py-2 text-lg" onClick={closeMenu}>
                About
              </Link>
              <Link to="/contact" className="py-2 text-lg" onClick={closeMenu}>
                Contact
              </Link>
              {!isAuthenticated && (
                <>
                  <hr className="border-gray-200" />
                  <Link to="/login" className="py-2 text-lg" onClick={closeMenu}>
                    Sign In
                  </Link>
                  <Link to="/register" className="py-2 text-lg" onClick={closeMenu}>
                    Create Account
                  </Link>
                </>
              )}
            </nav>
          </div>
        </div>
      )}
    </header>
  );
};

export default Header;
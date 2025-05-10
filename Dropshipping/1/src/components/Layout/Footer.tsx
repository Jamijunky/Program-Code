import { Link } from 'react-router-dom';
import { Package, Mail, Phone, MapPin, Facebook, Twitter, Instagram, Youtube } from 'lucide-react';

const Footer = () => {
  const year = new Date().getFullYear();

  return (
    <footer className="bg-gray-900 text-gray-300">
      <div className="container mx-auto px-4 py-12">
        <div className="grid grid-cols-1 gap-8 md:grid-cols-2 lg:grid-cols-4">
          {/* Company Info */}
          <div>
            <Link to="/" className="flex items-center space-x-2">
              <Package className="h-6 w-6 text-blue-500" />
              <span className="text-xl font-bold text-white">DropMarket</span>
            </Link>
            <p className="mt-4 text-sm">Premium dropshipping store with high-quality products and worldwide shipping.</p>
            <div className="mt-6 flex space-x-4">
              <a href="#" className="text-gray-400 hover:text-white">
                <Facebook size={20} />
              </a>
              <a href="#" className="text-gray-400 hover:text-white">
                <Twitter size={20} />
              </a>
              <a href="#" className="text-gray-400 hover:text-white">
                <Instagram size={20} />
              </a>
              <a href="#" className="text-gray-400 hover:text-white">
                <Youtube size={20} />
              </a>
            </div>
          </div>

          {/* Shop Links */}
          <div>
            <h3 className="mb-4 text-lg font-semibold text-white">Shop</h3>
            <ul className="space-y-2 text-sm">
              <li>
                <Link to="/shop?category=electronics" className="hover:text-white">Electronics</Link>
              </li>
              <li>
                <Link to="/shop?category=clothing" className="hover:text-white">Clothing</Link>
              </li>
              <li>
                <Link to="/shop?category=home" className="hover:text-white">Home & Kitchen</Link>
              </li>
              <li>
                <Link to="/shop?category=beauty" className="hover:text-white">Beauty</Link>
              </li>
              <li>
                <Link to="/shop?onSale=true" className="hover:text-white">Sale Items</Link>
              </li>
            </ul>
          </div>

          {/* Customer Service */}
          <div>
            <h3 className="mb-4 text-lg font-semibold text-white">Customer Service</h3>
            <ul className="space-y-2 text-sm">
              <li>
                <Link to="/contact" className="hover:text-white">Contact Us</Link>
              </li>
              <li>
                <Link to="/shipping" className="hover:text-white">Shipping Policy</Link>
              </li>
              <li>
                <Link to="/returns" className="hover:text-white">Returns & Refunds</Link>
              </li>
              <li>
                <Link to="/faq" className="hover:text-white">FAQs</Link>
              </li>
              <li>
                <Link to="/privacy" className="hover:text-white">Privacy Policy</Link>
              </li>
              <li>
                <Link to="/terms" className="hover:text-white">Terms of Service</Link>
              </li>
            </ul>
          </div>

          {/* Contact Info */}
          <div>
            <h3 className="mb-4 text-lg font-semibold text-white">Contact Us</h3>
            <ul className="space-y-3 text-sm">
              <li className="flex items-start space-x-3">
                <MapPin size={18} className="mt-0.5 flex-shrink-0" />
                <span>123 Commerce St, City, Country</span>
              </li>
              <li className="flex items-center space-x-3">
                <Phone size={18} className="flex-shrink-0" />
                <span>+1 (234) 567-8901</span>
              </li>
              <li className="flex items-center space-x-3">
                <Mail size={18} className="flex-shrink-0" />
                <span>support@dropmarket.com</span>
              </li>
            </ul>
            <div className="mt-6">
              <h4 className="mb-2 text-sm font-semibold">Newsletter</h4>
              <form className="flex">
                <input
                  type="email"
                  placeholder="Your email"
                  className="w-full rounded-l-md border-gray-700 bg-gray-800 px-3 py-2 text-sm focus:border-blue-500 focus:ring-blue-500"
                />
                <button type="submit" className="rounded-r-md bg-blue-600 px-4 py-2 text-sm font-medium text-white hover:bg-blue-700">
                  Subscribe
                </button>
              </form>
            </div>
          </div>
        </div>
        <div className="mt-12 border-t border-gray-800 pt-6 text-center text-sm">
          <p>&copy; {year} DropMarket. All rights reserved.</p>
        </div>
      </div>
    </footer>
  );
};

export default Footer;
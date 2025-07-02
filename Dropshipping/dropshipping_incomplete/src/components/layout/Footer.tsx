// src/components/layout/Footer.tsx
import React from 'react';
import Link from 'next/link';
import Image from 'next/image';
import { 
  FacebookIcon, 
  TwitterIcon, 
  InstagramIcon, 
  YoutubeIcon,
  MailIcon,
  PhoneIcon,
  LocationMarkerIcon
} from '@heroicons/react/outline';

const Footer: React.FC = () => {
  const currentYear = new Date().getFullYear();

  return (
    <footer className="bg-gray-900 text-white">
      {/* Newsletter Section */}
      <div className="bg-indigo-600 py-12">
        <div className="container mx-auto px-4 text-center">
          <h3 className="text-2xl font-bold mb-4">Stay Updated</h3>
          <p className="text-indigo-100 mb-6 max-w-2xl mx-auto">
            Subscribe to our newsletter and get the latest deals, new arrivals, and exclusive offers.
          </p>
          <div className="flex flex-col sm:flex-row max-w-md mx-auto gap-4">
            <input
              type="email"
              placeholder="Enter your email"
              className="flex-1 px-4 py-3 rounded-lg text-gray-900 focus:outline-none focus:ring-2 focus:ring-white"
            />
            <button className="bg-white text-indigo-600 px-6 py-3 rounded-lg font-medium hover:bg-gray-100 transition-colors">
              Subscribe
            </button>
          </div>
        </div>
      </div>

      {/* Main Footer Content */}
      <div className="container mx-auto px-4 py-12">
        <div className="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-4 gap-8">
          {/* Company Info */}
          <div className="col-span-1 lg:col-span-1">
            <div className="flex items-center mb-4">
              <Image src="/logo-white.svg" alt="DropShip" width={32} height={32} />
              <span className="ml-2 text-xl font-bold">DropShip</span>
            </div>
            <p className="text-gray-300 mb-6">
              Your trusted online marketplace for quality products at unbeatable prices. 
              Fast shipping, excellent customer service, and satisfaction guaranteed.
            </p>
            
            {/* Social Links */}
            <div className="flex space-x-4">
              <a href="#" className="text-gray-400 hover:text-white transition-colors">
                <FacebookIcon className="w-6 h-6" />
              </a>
              <a href="#" className="text-gray-400 hover:text-white transition-colors">
                <TwitterIcon className="w-6 h-6" />
              </a>
              <a href="#" className="text-gray-400 hover:text-white transition-colors">
                <InstagramIcon className="w-6 h-6" />
              </a>
              <a href="#" className="text-gray-400 hover:text-white transition-colors">
                <YoutubeIcon className="w-6 h-6" />
              </a>
            </div>
          </div>

          {/* Quick Links */}
          <div>
            <h4 className="text-lg font-semibold mb-4">Quick Links</h4>
            <ul className="space-y-2">
              <li><Link href="/shop" className="text-gray-300 hover:text-white transition-colors">Shop All</Link></li>
              <li><Link href="/shop/category/electronics" className="text-gray-300 hover:text-white transition-colors">Electronics</Link></li>
              <li><Link href="/shop/category/fashion" className="text-gray-300 hover:text-white transition-colors">Fashion</Link></li>
              <li><Link href="/shop/category/home" className="text-gray-300 hover:text-white transition-colors">Home & Decor</Link></li>
              <li><Link href="/shop/category/beauty" className="text-gray-300 hover:text-white transition-colors">Beauty</Link></li>
              <li><Link href="/deals" className="text-gray-300 hover:text-white transition-colors">Special Deals</Link></li>
            </ul>
          </div>

          {/* Customer Service */}
          <div>
            <h4 className="text-lg font-semibold mb-4">Customer Service</h4>
            <ul className="space-y-2">
              <li><Link href="/contact" className="text-gray-300 hover:text-white transition-colors">Contact Us</Link></li>
              <li><Link href="/help/faq" className="text-gray-300 hover:text-white transition-colors">FAQ</Link></li>
              <li><Link href="/help/shipping" className="text-gray-300 hover:text-white transition-colors">Shipping Info</Link></li>
              <li><Link href="/help/returns" className="text-gray-300 hover:text-white transition-colors">Returns & Exchanges</Link></li>
              <li><Link href="/help/size-guide" className="text-gray-300 hover:text-white transition-colors">Size Guide</Link></li>
              <li><Link href="/track-order" className="text-gray-300 hover:text-white transition-colors">Track Your Order</Link></li>
            </ul>
          </div>

          {/* Contact Info */}
          <div>
            <h4 className="text-lg font-semibold mb-4">Contact Info</h4>
            <div className="space-y-3">
              <div className="flex items-start space-x-3">
                <LocationMarkerIcon className="w-5 h-5 text-gray-400 mt-0.5" />
                <div className="text-gray-300">
                  <p>123 Commerce Street</p>
                  <p>Business District, City 12345</p>
                </div>
              </div>
              
              <div className="flex items-center space-x-3">
                <PhoneIcon className="w-5 h-5 text-gray-400" />
                <a href="tel:+1234567890" className="text-gray-300 hover:text-white transition-colors">
                  +1 (234) 567-8900
                </a>
              </div>
              
              <div className="flex items-center space-x-3">
                <MailIcon className="w-5 h-5 text-gray-400" />
                <a href="mailto:support@dropship.com" className="text-gray-300 hover:text-white transition-colors">
                  support@dropship.com
                </a>
              </div>
            </div>

            {/* Business Hours */}
            <div className="mt-6">
              <h5 className="font-medium mb-2">Business Hours</h5>
              <div className="text-sm text-gray-300 space-y-1">
                <p>Mon - Fri: 9:00 AM - 6:00 PM</p>
                <p>Sat: 10:00 AM - 4:00 PM</p>
                <p>Sun: Closed</p>
              </div>
            </div>
          </div>
        </div>
      </div>

      {/* Payment Methods & Trust Signals */}
      <div className="border-t border-gray-800 py-8">
        <div className="container mx-auto px-4">
          <div className="flex flex-col md:flex-row items-center justify-between space-y-4 md:space-y-0">
            <div className="flex items-center space-x-6">
              <div className="text-sm text-gray-300">
                <span className="font-medium">We Accept:</span>
              </div>
              <div className="flex items-center space-x-3">
                <div className="bg-white rounded p-1">
                  <Image src="/payments/visa.svg" alt="Visa" width={32} height={20} />
                </div>
                <div className="bg-white rounded p-1">
                  <Image src="/payments/mastercard.svg" alt="Mastercard" width={32} height={20} />
                </div>
                <div className="bg-white rounded p-1">
                  <Image src="/payments/paypal.svg" alt="PayPal" width={32} height={20} />
                </div>
                <div className="bg-white rounded p-1">
                  <Image src="/payments/apple-pay.svg" alt="Apple Pay" width={32} height={20} />
                </div>
              </div>
            </div>

            <div className="flex items-center space-x-6">
              <div className="text-sm text-gray-300">
                <span className="font-medium">Secured by:</span>
              </div>
              <div className="flex items-center space-x-3">
                <Image src="/security/ssl.svg" alt="SSL Secured" width={60} height={30} />
                <Image src="/security/trust.svg" alt="Trusted Store" width={60} height={30} />
              </div>
            </div>
          </div>
        </div>
      </div>

      {/* Bottom Bar */}
      <div className="border-t border-gray-800 py-6">
        <div className="container mx-auto px-4">
          <div className="flex flex-col md:flex-row items-center justify-between space-y-4 md:space-y-0">
            <div className="text-sm text-gray-400">
              © {currentYear} DropShip. All rights reserved.
            </div>
            
            <div className="flex items-center space-x-6 text-sm">
              <Link href="/legal/privacy" className="text-gray-400 hover:text-white transition-colors">
                Privacy Policy
              </Link>
              <Link href="/legal/terms" className="text-gray-
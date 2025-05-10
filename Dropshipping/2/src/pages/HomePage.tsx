import React from 'react';
import { Link } from 'react-router-dom';
import { ChevronRight, Star, Truck, ShieldCheck, RefreshCw } from 'lucide-react';
import ProductGrid from '../components/products/ProductGrid';
import Button from '../components/ui/Button';
import { mockProducts } from '../data/mockProducts';

const HomePage: React.FC = () => {
  // Get featured products (first 4)
  const featuredProducts = mockProducts.slice(0, 4);
  
  // Get trending products (different selection)
  const trendingProducts = mockProducts.slice(2, 6);

  return (
    <div className="flex flex-col min-h-screen">
      {/* Hero Section */}
      <section className="bg-gradient-to-r from-primary-700 to-primary-900 text-white py-12 md:py-24">
        <div className="container mx-auto px-4">
          <div className="flex flex-col md:flex-row items-center">
            <div className="md:w-1/2 mb-8 md:mb-0">
              <h1 className="text-3xl md:text-4xl lg:text-5xl font-bold mb-4 leading-tight animate-fade-in">
                Start Your Dropshipping Business Today
              </h1>
              <p className="text-lg md:text-xl opacity-90 mb-8 animate-fade-in">
                Premium products, seamless integration, and powerful tools to help you succeed in e-commerce.
              </p>
              <div className="flex flex-col sm:flex-row gap-4 animate-slide-up">
                <Button 
                  variant="secondary" 
                  size="lg"
                  onClick={() => {}}
                >
                  Browse Products
                </Button>
                <Button 
                  variant="outline" 
                  size="lg"
                  className="text-white border-white hover:bg-white/10"
                  onClick={() => {}}
                >
                  Learn More
                </Button>
              </div>
            </div>
            <div className="md:w-1/2 flex justify-center md:justify-end">
              <img 
                src="https://images.pexels.com/photos/4481259/pexels-photo-4481259.jpeg?auto=compress&cs=tinysrgb&w=1260&h=750&dpr=1" 
                alt="Dropshipping Business" 
                className="rounded-lg w-full max-w-md shadow-xl" 
              />
            </div>
          </div>
        </div>
      </section>

      {/* Features Section */}
      <section className="py-16 bg-gray-50">
        <div className="container mx-auto px-4">
          <div className="text-center mb-12">
            <h2 className="text-2xl md:text-3xl font-bold text-gray-900">Why Choose ShipSmart?</h2>
            <p className="text-gray-600 mt-2 max-w-2xl mx-auto">We offer everything you need to build a successful dropshipping business</p>
          </div>
          
          <div className="grid grid-cols-1 md:grid-cols-3 gap-8">
            <div className="bg-white p-6 rounded-lg shadow-sm hover:shadow-md transition-shadow duration-300 flex flex-col items-center text-center">
              <div className="bg-primary-100 p-3 rounded-full mb-4">
                <Truck className="text-primary-700" size={28} />
              </div>
              <h3 className="text-xl font-semibold mb-2">Fast Shipping</h3>
              <p className="text-gray-600">Reliable suppliers with quick processing times and global shipping options.</p>
            </div>
            
            <div className="bg-white p-6 rounded-lg shadow-sm hover:shadow-md transition-shadow duration-300 flex flex-col items-center text-center">
              <div className="bg-primary-100 p-3 rounded-full mb-4">
                <ShieldCheck className="text-primary-700" size={28} />
              </div>
              <h3 className="text-xl font-semibold mb-2">Quality Products</h3>
              <p className="text-gray-600">Curated selection of high-quality products to ensure customer satisfaction.</p>
            </div>
            
            <div className="bg-white p-6 rounded-lg shadow-sm hover:shadow-md transition-shadow duration-300 flex flex-col items-center text-center">
              <div className="bg-primary-100 p-3 rounded-full mb-4">
                <RefreshCw className="text-primary-700" size={28} />
              </div>
              <h3 className="text-xl font-semibold mb-2">Seamless Integration</h3>
              <p className="text-gray-600">Easily integrate with your store and automate order fulfillment.</p>
            </div>
          </div>
        </div>
      </section>

      {/* Featured Products Section */}
      <section className="py-16">
        <div className="container mx-auto px-4">
          <div className="flex justify-between items-center mb-8">
            <h2 className="text-2xl md:text-3xl font-bold text-gray-900">Featured Products</h2>
            <Link to="/products" className="text-primary-700 hover:text-primary-800 font-medium flex items-center">
              View all <ChevronRight size={16} />
            </Link>
          </div>
          
          <ProductGrid products={featuredProducts} />
        </div>
      </section>

      {/* Testimonials Section */}
      <section className="py-16 bg-gray-50">
        <div className="container mx-auto px-4">
          <div className="text-center mb-12">
            <h2 className="text-2xl md:text-3xl font-bold text-gray-900">What Our Customers Say</h2>
            <p className="text-gray-600 mt-2 max-w-2xl mx-auto">Trusted by thousands of entrepreneurs worldwide</p>
          </div>
          
          <div className="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-3 gap-8">
            <div className="bg-white p-6 rounded-lg shadow-sm">
              <div className="flex mb-4">
                {[...Array(5)].map((_, index) => (
                  <Star key={index} size={18} className="text-yellow-400 fill-yellow-400" />
                ))}
              </div>
              <p className="text-gray-700 mb-4">
                "ShipSmart has transformed my business. The quality of products and ease of use are unmatched in the industry."
              </p>
              <div className="flex items-center">
                <div className="w-10 h-10 bg-gray-200 rounded-full flex-shrink-0"></div>
                <div className="ml-3">
                  <h4 className="font-medium text-gray-900">Sarah Johnson</h4>
                  <p className="text-sm text-gray-500">Fashion Boutique Owner</p>
                </div>
              </div>
            </div>
            
            <div className="bg-white p-6 rounded-lg shadow-sm">
              <div className="flex mb-4">
                {[...Array(5)].map((_, index) => (
                  <Star key={index} size={18} className="text-yellow-400 fill-yellow-400" />
                ))}
              </div>
              <p className="text-gray-700 mb-4">
                "I've tried multiple dropshipping platforms, but ShipSmart stands out with its reliable suppliers and excellent customer support."
              </p>
              <div className="flex items-center">
                <div className="w-10 h-10 bg-gray-200 rounded-full flex-shrink-0"></div>
                <div className="ml-3">
                  <h4 className="font-medium text-gray-900">Michael Chen</h4>
                  <p className="text-sm text-gray-500">E-commerce Entrepreneur</p>
                </div>
              </div>
            </div>
            
            <div className="bg-white p-6 rounded-lg shadow-sm">
              <div className="flex mb-4">
                {[...Array(5)].map((_, index) => (
                  <Star key={index} size={18} className="text-yellow-400 fill-yellow-400" />
                ))}
              </div>
              <p className="text-gray-700 mb-4">
                "The automation tools have saved me countless hours. I can now focus on marketing while ShipSmart handles the rest."
              </p>
              <div className="flex items-center">
                <div className="w-10 h-10 bg-gray-200 rounded-full flex-shrink-0"></div>
                <div className="ml-3">
                  <h4 className="font-medium text-gray-900">Emily Rodriguez</h4>
                  <p className="text-sm text-gray-500">Online Store Owner</p>
                </div>
              </div>
            </div>
          </div>
        </div>
      </section>

      {/* Trending Products Section */}
      <section className="py-16">
        <div className="container mx-auto px-4">
          <div className="flex justify-between items-center mb-8">
            <h2 className="text-2xl md:text-3xl font-bold text-gray-900">Trending Now</h2>
            <Link to="/products?category=trending" className="text-primary-700 hover:text-primary-800 font-medium flex items-center">
              View all <ChevronRight size={16} />
            </Link>
          </div>
          
          <ProductGrid products={trendingProducts} />
        </div>
      </section>

      {/* CTA Section */}
      <section className="bg-cta-600 py-16 text-white">
        <div className="container mx-auto px-4 text-center">
          <h2 className="text-2xl md:text-3xl font-bold mb-4">Ready to Start Your Dropshipping Journey?</h2>
          <p className="max-w-2xl mx-auto mb-8 text-cta-50">
            Join thousands of successful entrepreneurs who have built their businesses with ShipSmart.
          </p>
          <div className="flex flex-col sm:flex-row justify-center gap-4">
            <Button 
              variant="primary" 
              size="lg"
              className="bg-white text-cta-700 hover:bg-cta-50"
              onClick={() => {}}
            >
              Get Started Now
            </Button>
            <Button 
              variant="outline" 
              size="lg"
              className="text-white border-white hover:bg-white/10"
              onClick={() => {}}
            >
              Schedule a Demo
            </Button>
          </div>
        </div>
      </section>
    </div>
  );
};

export default HomePage;
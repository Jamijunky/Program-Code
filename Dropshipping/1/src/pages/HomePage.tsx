import { useState, useEffect } from 'react';
import { Link } from 'react-router-dom';
import { ChevronRight, TrendingUp, Star, Clock, Truck } from 'lucide-react';
import ProductCard from '../components/Products/ProductCard';
import { productData } from '../data/products';

const FeaturedCategories = () => {
  return (
    <div className="container mx-auto px-4 py-16">
      <h2 className="mb-10 text-center text-3xl font-bold">Shop by Category</h2>
      <div className="grid grid-cols-2 gap-4 md:grid-cols-4">
        {[
          { id: 'electronics', name: 'Electronics', image: 'https://images.pexels.com/photos/1440504/pexels-photo-1440504.jpeg?auto=compress&cs=tinysrgb&w=1260&h=750&dpr=1' },
          { id: 'clothing', name: 'Clothing', image: 'https://images.pexels.com/photos/934063/pexels-photo-934063.jpeg?auto=compress&cs=tinysrgb&w=1260&h=750&dpr=1' },
          { id: 'home', name: 'Home & Kitchen', image: 'https://images.pexels.com/photos/276583/pexels-photo-276583.jpeg?auto=compress&cs=tinysrgb&w=1260&h=750&dpr=1' },
          { id: 'beauty', name: 'Beauty', image: 'https://images.pexels.com/photos/3321416/pexels-photo-3321416.jpeg?auto=compress&cs=tinysrgb&w=1260&h=750&dpr=1' },
        ].map((category) => (
          <Link
            key={category.id}
            to={`/shop?category=${category.id}`}
            className="group relative overflow-hidden rounded-lg"
          >
            <div className="aspect-square w-full">
              <img
                src={category.image}
                alt={category.name}
                className="h-full w-full object-cover transition-transform duration-500 group-hover:scale-110"
              />
              <div className="absolute inset-0 bg-gradient-to-t from-black/70 to-transparent">
                <div className="absolute bottom-0 p-4">
                  <h3 className="text-xl font-bold text-white">{category.name}</h3>
                  <span className="mt-1 inline-flex items-center text-sm font-medium text-white">
                    Shop Now <ChevronRight size={16} className="ml-1" />
                  </span>
                </div>
              </div>
            </div>
          </Link>
        ))}
      </div>
    </div>
  );
};

const FeaturedProducts = () => {
  const bestSellers = productData.filter((product) => product.rating >= 4.5).slice(0, 4);

  return (
    <div className="bg-gray-50 py-16">
      <div className="container mx-auto px-4">
        <div className="mb-10 flex items-center justify-between">
          <h2 className="text-3xl font-bold">Bestsellers</h2>
          <Link
            to="/shop"
            className="flex items-center text-blue-600 hover:text-blue-700"
          >
            View All <ChevronRight size={16} className="ml-1" />
          </Link>
        </div>
        <div className="grid grid-cols-2 gap-6 sm:grid-cols-2 md:grid-cols-3 lg:grid-cols-4">
          {bestSellers.map((product) => (
            <ProductCard key={product.id} product={product} />
          ))}
        </div>
      </div>
    </div>
  );
};

const DealsSection = () => {
  const dealsProducts = productData.filter((product) => product.originalPrice && product.originalPrice > product.price).slice(0, 4);

  return (
    <div className="container mx-auto px-4 py-16">
      <div className="mb-10 flex items-center justify-between">
        <h2 className="text-3xl font-bold">Flash Deals</h2>
        <Link
          to="/shop?onSale=true"
          className="flex items-center text-blue-600 hover:text-blue-700"
        >
          View All <ChevronRight size={16} className="ml-1" />
        </Link>
      </div>
      <div className="grid grid-cols-2 gap-6 sm:grid-cols-2 md:grid-cols-3 lg:grid-cols-4">
        {dealsProducts.map((product) => (
          <ProductCard key={product.id} product={product} />
        ))}
      </div>
    </div>
  );
};

const Hero = () => {
  const [currentSlide, setCurrentSlide] = useState(0);

  const slides = [
    {
      title: "Summer Sale",
      subtitle: "Up to 50% off on selected items",
      cta: "Shop Now",
      image: "https://images.pexels.com/photos/934070/pexels-photo-934070.jpeg?auto=compress&cs=tinysrgb&w=1260&h=750&dpr=1",
      link: "/shop?onSale=true"
    },
    {
      title: "New Arrivals",
      subtitle: "Check out our latest products",
      cta: "Discover",
      image: "https://images.pexels.com/photos/4195342/pexels-photo-4195342.jpeg?auto=compress&cs=tinysrgb&w=1260&h=750&dpr=1",
      link: "/shop"
    }
  ];

  useEffect(() => {
    const interval = setInterval(() => {
      setCurrentSlide((prev) => (prev === slides.length - 1 ? 0 : prev + 1));
    }, 5000);
    return () => clearInterval(interval);
  }, [slides.length]);

  return (
    <div className="relative h-[70vh] w-full overflow-hidden">
      {slides.map((slide, idx) => (
        <div
          key={idx}
          className={`absolute inset-0 transition-opacity duration-1000 ${
            idx === currentSlide ? 'opacity-100' : 'opacity-0'
          }`}
        >
          <img
            src={slide.image}
            alt={slide.title}
            className="h-full w-full object-cover"
          />
          <div className="absolute inset-0 bg-black bg-opacity-40">
            <div className="container mx-auto flex h-full items-center px-4">
              <div className="max-w-2xl text-white">
                <h1 className="mb-4 text-4xl font-bold md:text-5xl lg:text-6xl">
                  {slide.title}
                </h1>
                <p className="mb-6 text-xl md:text-2xl">{slide.subtitle}</p>
                <Link
                  to={slide.link}
                  className="inline-flex items-center rounded-md bg-accent-500 px-6 py-3 text-lg font-medium text-white transition-colors hover:bg-accent-600"
                >
                  {slide.cta}
                  <ChevronRight size={20} className="ml-2" />
                </Link>
              </div>
            </div>
          </div>
        </div>
      ))}

      <div className="absolute bottom-4 left-1/2 flex -translate-x-1/2 space-x-2">
        {slides.map((_, idx) => (
          <button
            key={idx}
            onClick={() => setCurrentSlide(idx)}
            className={`h-2 w-8 rounded-full ${
              idx === currentSlide ? 'bg-white' : 'bg-white/50'
            }`}
            aria-label={`Go to slide ${idx + 1}`}
          />
        ))}
      </div>
    </div>
  );
};

const FeaturesBanner = () => {
  return (
    <div className="bg-white py-12">
      <div className="container mx-auto px-4">
        <div className="grid grid-cols-1 gap-6 md:grid-cols-2 lg:grid-cols-4">
          {[
            { icon: <Truck className="h-8 w-8 text-blue-600" />, title: "Free Shipping", desc: "On orders over $50" },
            { icon: <Clock className="h-8 w-8 text-blue-600" />, title: "30-Day Returns", desc: "Hassle-free returns" },
            { icon: <TrendingUp className="h-8 w-8 text-blue-600" />, title: "Trending Products", desc: "From top suppliers" },
            { icon: <Star className="h-8 w-8 text-blue-600" />, title: "Premium Quality", desc: "Curated products" },
          ].map((feature, i) => (
            <div key={i} className="flex items-center justify-center space-x-4 rounded-lg border border-gray-100 bg-white p-6 shadow-sm">
              {feature.icon}
              <div>
                <h3 className="font-semibold">{feature.title}</h3>
                <p className="text-sm text-gray-600">{feature.desc}</p>
              </div>
            </div>
          ))}
        </div>
      </div>
    </div>
  );
};

const HomePage = () => {
  return (
    <div>
      <Hero />
      <FeaturesBanner />
      <FeaturedCategories />
      <FeaturedProducts />
      <DealsSection />
    </div>
  );
};

export default HomePage;
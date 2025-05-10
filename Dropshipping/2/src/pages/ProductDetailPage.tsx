import React, { useState, useEffect } from 'react';
import { useParams, Link } from 'react-router-dom';
import { Star, Truck, ShieldCheck, ArrowLeft, Heart, ShoppingCart, Minus, Plus } from 'lucide-react';
import Button from '../components/ui/Button';
import { useCartStore } from '../stores/cartStore';
import { useWishlistStore } from '../stores/wishlistStore';
import { getProductById } from '../data/mockProducts';
import { ProductType, ProductVariant } from '../types/product';
import LoadingSpinner from '../components/ui/LoadingSpinner';

const ProductDetailPage: React.FC = () => {
  const { productId } = useParams<{ productId: string }>();
  const [product, setProduct] = useState<ProductType | null>(null);
  const [loading, setLoading] = useState(true);
  const [selectedVariant, setSelectedVariant] = useState<ProductVariant | null>(null);
  const [quantity, setQuantity] = useState(1);
  const [activeImage, setActiveImage] = useState(0);
  
  const { addItem } = useCartStore();
  const { addToWishlist, isInWishlist, removeFromWishlist } = useWishlistStore();
  
  // Fetch product data
  useEffect(() => {
    setLoading(true);
    
    // Simulate API call
    setTimeout(() => {
      if (productId) {
        const foundProduct = getProductById(productId);
        if (foundProduct) {
          setProduct(foundProduct);
          // Set first variant as default
          setSelectedVariant(foundProduct.variants[0]);
        }
      }
      setLoading(false);
    }, 500);
  }, [productId]);
  
  if (loading) {
    return <LoadingSpinner />;
  }
  
  if (!product) {
    return (
      <div className="container mx-auto px-4 py-16 text-center">
        <h1 className="text-2xl font-bold text-gray-900 mb-4">Product Not Found</h1>
        <p className="text-gray-600 mb-8">The product you're looking for doesn't exist or has been removed.</p>
        <Link to="/products">
          <Button variant="primary">Browse Products</Button>
        </Link>
      </div>
    );
  }
  
  const isWishlisted = isInWishlist(product.id);
  
  // Get unique sizes and colors from variants
  const sizes = Array.from(new Set(product.variants.map(v => v.size)));
  const colors = Array.from(new Set(product.variants.map(v => v.color)));
  
  // Handle variant selection
  const handleVariantChange = (variantId: string) => {
    const variant = product.variants.find(v => v.id === variantId);
    if (variant) {
      setSelectedVariant(variant);
    }
  };
  
  // Handle size selection
  const handleSizeChange = (size: string) => {
    // Find first variant with the selected size and current color (if any)
    const currentColor = selectedVariant?.color;
    const variant = product.variants.find(
      v => v.size === size && (!currentColor || v.color === currentColor)
    );
    if (variant) {
      setSelectedVariant(variant);
    }
  };
  
  // Handle color selection
  const handleColorChange = (color: string) => {
    // Find first variant with the selected color and current size (if any)
    const currentSize = selectedVariant?.size;
    const variant = product.variants.find(
      v => v.color === color && (!currentSize || v.size === currentSize)
    );
    if (variant) {
      setSelectedVariant(variant);
    }
  };
  
  // Handle quantity change
  const increaseQuantity = () => {
    if (selectedVariant && quantity < selectedVariant.inventory) {
      setQuantity(prev => prev + 1);
    }
  };
  
  const decreaseQuantity = () => {
    if (quantity > 1) {
      setQuantity(prev => prev - 1);
    }
  };
  
  // Handle add to cart
  const handleAddToCart = () => {
    if (selectedVariant) {
      addItem({
        id: product.id,
        title: product.title,
        price: selectedVariant.price,
        image: product.images[0],
        variantId: selectedVariant.id,
        quantity,
        size: selectedVariant.size,
        color: selectedVariant.color,
      });
    }
  };
  
  // Handle wishlist toggle
  const handleWishlistToggle = () => {
    if (isWishlisted) {
      removeFromWishlist(product.id);
    } else {
      addToWishlist(product);
    }
  };
  
  // Calculate average rating
  const avgRating = product.ratings && product.ratings.length 
    ? product.ratings.reduce((sum, r) => sum + r.rating, 0) / product.ratings.length 
    : 0;
  
  return (
    <div className="bg-white">
      <div className="container mx-auto px-4 py-8">
        {/* Breadcrumb */}
        <div className="mb-6">
          <Link to="/products" className="flex items-center text-primary-700 hover:text-primary-800 transition-colors">
            <ArrowLeft size={16} className="mr-2" /> Back to Products
          </Link>
        </div>
        
        <div className="grid grid-cols-1 md:grid-cols-2 gap-8 lg:gap-12">
          {/* Product Images */}
          <div className="space-y-4">
            <div className="bg-gray-100 rounded-lg overflow-hidden aspect-square">
              <img 
                src={product.images[activeImage]} 
                alt={product.title} 
                className="w-full h-full object-cover object-center"
              />
            </div>
            
            {/* Thumbnail Gallery */}
            {product.images.length > 1 && (
              <div className="flex space-x-2 overflow-x-auto pb-2">
                {product.images.map((image, index) => (
                  <button
                    key={index}
                    className={`w-16 h-16 rounded overflow-hidden flex-shrink-0 border-2 ${
                      activeImage === index ? 'border-primary-700' : 'border-transparent'
                    }`}
                    onClick={() => setActiveImage(index)}
                  >
                    <img 
                      src={image} 
                      alt={`${product.title} - View ${index + 1}`} 
                      className="w-full h-full object-cover object-center"
                    />
                  </button>
                ))}
              </div>
            )}
          </div>
          
          {/* Product Info */}
          <div>
            <h1 className="text-2xl md:text-3xl font-bold text-gray-900 mb-2">{product.title}</h1>
            
            {/* Ratings */}
            {product.ratings && product.ratings.length > 0 && (
              <div className="flex items-center mb-4">
                <div className="flex mr-2">
                  {[...Array(5)].map((_, i) => (
                    <Star
                      key={i}
                      size={16}
                      className={`${
                        i < Math.floor(avgRating)
                          ? 'text-yellow-400 fill-yellow-400'
                          : i < avgRating
                          ? 'text-yellow-400 fill-yellow-400 opacity-50'
                          : 'text-gray-300'
                      }`}
                    />
                  ))}
                </div>
                <span className="text-sm text-gray-500">
                  {avgRating.toFixed(1)} ({product.ratings.length} reviews)
                </span>
              </div>
            )}
            
            {/* Price */}
            {selectedVariant && (
              <div className="text-2xl font-bold text-gray-900 mb-6">
                ${selectedVariant.price.toFixed(2)}
              </div>
            )}
            
            {/* Description */}
            <div className="prose prose-sm text-gray-700 mb-6">
              <p>{product.description}</p>
            </div>
            
            {/* Variant Selection */}
            <div className="space-y-6 mb-6">
              {/* Size Selection */}
              {sizes.length > 1 && (
                <div>
                  <label className="block text-sm font-medium text-gray-700 mb-2">
                    Size
                  </label>
                  <div className="flex flex-wrap gap-2">
                    {sizes.map((size) => (
                      <button
                        key={size}
                        className={`px-4 py-2 border rounded-md text-sm font-medium ${
                          selectedVariant?.size === size
                            ? 'bg-primary-700 text-white border-primary-700'
                            : 'bg-white text-gray-900 border-gray-300 hover:bg-gray-50'
                        }`}
                        onClick={() => handleSizeChange(size)}
                      >
                        {size}
                      </button>
                    ))}
                  </div>
                </div>
              )}
              
              {/* Color Selection */}
              {colors.length > 1 && (
                <div>
                  <label className="block text-sm font-medium text-gray-700 mb-2">
                    Color: <span className="font-normal">{selectedVariant?.color}</span>
                  </label>
                  <div className="flex flex-wrap gap-2">
                    {colors.map((color) => (
                      <button
                        key={color}
                        className={`w-8 h-8 rounded-full border-2 ${
                          selectedVariant?.color === color
                            ? 'border-primary-700 ring-2 ring-primary-500 ring-opacity-50'
                            : 'border-gray-300'
                        }`}
                        style={{ 
                          backgroundColor: color.toLowerCase(),
                          // Override for specific colors that need different visual treatment 
                          ...(color.toLowerCase() === 'white' ? { backgroundColor: '#FFFFFF' } : {}),
                          ...(color.toLowerCase() === 'black' ? { backgroundColor: '#000000' } : {})
                        }}
                        onClick={() => handleColorChange(color)}
                        aria-label={`Color: ${color}`}
                      />
                    ))}
                  </div>
                </div>
              )}
              
              {/* Quantity */}
              <div>
                <label className="block text-sm font-medium text-gray-700 mb-2">
                  Quantity
                </label>
                <div className="flex items-center">
                  <button
                    className="p-2 border border-gray-300 rounded-l-md bg-gray-50 hover:bg-gray-100"
                    onClick={decreaseQuantity}
                    disabled={quantity <= 1}
                  >
                    <Minus size={16} />
                  </button>
                  <div className="w-12 h-10 border-t border-b border-gray-300 flex items-center justify-center text-gray-900">
                    {quantity}
                  </div>
                  <button
                    className="p-2 border border-gray-300 rounded-r-md bg-gray-50 hover:bg-gray-100"
                    onClick={increaseQuantity}
                    disabled={selectedVariant ? quantity >= selectedVariant.inventory : true}
                  >
                    <Plus size={16} />
                  </button>
                  
                  {selectedVariant && selectedVariant.inventory < 10 && (
                    <span className="ml-3 text-sm text-warning-600">
                      Only {selectedVariant.inventory} left in stock
                    </span>
                  )}
                </div>
              </div>
            </div>
            
            {/* Add to Cart and Wishlist */}
            <div className="flex flex-col sm:flex-row gap-4 mb-8">
              <Button
                variant="primary"
                size="lg"
                fullWidth
                icon={<ShoppingCart size={20} />}
                onClick={handleAddToCart}
                disabled={!selectedVariant || selectedVariant.inventory === 0}
              >
                Add to Cart
              </Button>
              
              <Button
                variant={isWishlisted ? 'outline' : 'outline'}
                size="lg"
                className={isWishlisted ? 'text-red-600 border-red-500' : ''}
                icon={<Heart size={20} className={isWishlisted ? 'fill-red-500 text-red-500' : ''} />}
                onClick={handleWishlistToggle}
              >
                {isWishlisted ? 'Wishlisted' : 'Add to Wishlist'}
              </Button>
            </div>
            
            {/* Product Features */}
            <div className="border-t border-gray-200 pt-6 space-y-4">
              <div className="flex items-start">
                <Truck size={20} className="text-primary-700 mr-3 flex-shrink-0 mt-1" />
                <div>
                  <h4 className="font-medium text-gray-900">Fast Shipping</h4>
                  <p className="text-sm text-gray-600">2-5 business days delivery</p>
                </div>
              </div>
              
              <div className="flex items-start">
                <ShieldCheck size={20} className="text-primary-700 mr-3 flex-shrink-0 mt-1" />
                <div>
                  <h4 className="font-medium text-gray-900">Quality Guarantee</h4>
                  <p className="text-sm text-gray-600">30-day money back guarantee</p>
                </div>
              </div>
            </div>
          </div>
        </div>
        
        {/* Product Details Tabs */}
        <div className="mt-16 border-t border-gray-200 pt-8">
          <div className="border-b border-gray-200">
            <div className="flex space-x-8">
              <button className="border-b-2 border-primary-700 text-primary-700 py-4 px-1 font-medium">
                Product Details
              </button>
              <button className="text-gray-500 hover:text-gray-700 py-4 px-1">
                Reviews ({product.ratings?.length || 0})
              </button>
              <button className="text-gray-500 hover:text-gray-700 py-4 px-1">
                Shipping & Returns
              </button>
            </div>
          </div>
          
          <div className="py-6">
            <h3 className="text-lg font-medium text-gray-900 mb-4">Product Information</h3>
            
            <div className="prose max-w-none text-gray-700">
              <p>{product.description}</p>
              <p>
                Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.
              </p>
              <ul>
                <li>High-quality materials</li>
                <li>Designed for durability and performance</li>
                <li>Versatile usage for various activities</li>
                <li>Easy maintenance and care</li>
              </ul>
            </div>
          </div>
        </div>
      </div>
    </div>
  );
};

export default ProductDetailPage;
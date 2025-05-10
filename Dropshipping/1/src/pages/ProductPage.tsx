import { useState, useEffect } from 'react';
import { useParams, Link } from 'react-router-dom';
import { ShoppingCart, Heart, Share2, Star, ChevronRight, Check, Truck, RotateCcw, ShieldCheck } from 'lucide-react';
import { productData } from '../data/products';
import { useCart } from '../contexts/CartContext';
import toast from 'react-hot-toast';
import ProductCard from '../components/Products/ProductCard';

const ProductPage = () => {
  const { id } = useParams<{ id: string }>();
  const [product, setProduct] = useState<any>(null);
  const [loading, setLoading] = useState(true);
  const [selectedVariant, setSelectedVariant] = useState<string>('');
  const [quantity, setQuantity] = useState(1);
  const [activeTab, setActiveTab] = useState<'description' | 'details' | 'reviews'>('description');
  const [relatedProducts, setRelatedProducts] = useState<any[]>([]);
  
  const { addToCart } = useCart();

  useEffect(() => {
    setLoading(true);
    // Simulate API fetch
    setTimeout(() => {
      const foundProduct = productData.find(p => p.id === id);
      setProduct(foundProduct);
      
      if (foundProduct && foundProduct.variants && foundProduct.variants.length > 0) {
        const inStockVariant = foundProduct.variants.find(v => v.inStock);
        if (inStockVariant) {
          setSelectedVariant(inStockVariant.id);
        }
      }
      
      // Get related products from same category
      if (foundProduct) {
        const related = productData
          .filter(p => p.category === foundProduct.category && p.id !== foundProduct.id)
          .slice(0, 4);
        setRelatedProducts(related);
      }
      
      setLoading(false);
    }, 300);
  }, [id]);

  const handleAddToCart = () => {
    if (!product) return;
    
    const selectedVariantObj = product.variants?.find(v => v.id === selectedVariant);
    
    addToCart({
      id: product.id,
      name: product.name,
      price: product.price,
      image: product.image,
      quantity: quantity,
      variant: selectedVariantObj ? selectedVariantObj.name : undefined,
    });
    
    toast.success('Added to cart successfully!');
  };

  const incrementQuantity = () => setQuantity(prev => prev + 1);
  const decrementQuantity = () => setQuantity(prev => (prev > 1 ? prev - 1 : 1));

  if (loading) {
    return (
      <div className="container mx-auto flex h-96 items-center justify-center">
        <div className="h-10 w-10 animate-spin rounded-full border-4 border-blue-600 border-t-transparent"></div>
      </div>
    );
  }

  if (!product) {
    return (
      <div className="container mx-auto px-4 py-16 text-center">
        <h1 className="mb-4 text-2xl font-bold">Product Not Found</h1>
        <p className="mb-6 text-gray-600">The product you are looking for does not exist or has been removed.</p>
        <Link to="/shop" className="btn btn-primary">
          Continue Shopping
        </Link>
      </div>
    );
  }

  const discountPercentage = product.originalPrice
    ? Math.round(((product.originalPrice - product.price) / product.originalPrice) * 100)
    : 0;

  return (
    <div className="container mx-auto px-4 py-8">
      {/* Breadcrumbs */}
      <div className="mb-6 flex text-sm">
        <Link to="/" className="text-gray-500 hover:text-blue-600">Home</Link>
        <ChevronRight className="mx-2 h-4 w-4 text-gray-400" />
        <Link to="/shop" className="text-gray-500 hover:text-blue-600">Shop</Link>
        <ChevronRight className="mx-2 h-4 w-4 text-gray-400" />
        <Link to={`/shop?category=${product.category.toLowerCase()}`} className="text-gray-500 hover:text-blue-600">
          {product.category}
        </Link>
        <ChevronRight className="mx-2 h-4 w-4 text-gray-400" />
        <span className="text-gray-800">{product.name}</span>
      </div>

      {/* Product Details */}
      <div className="mb-16 grid grid-cols-1 gap-8 md:grid-cols-2">
        {/* Product Image */}
        <div className="relative">
          <div className="sticky top-24 overflow-hidden rounded-lg bg-white">
            <img
              src={product.image}
              alt={product.name}
              className="h-full w-full object-contain"
            />
            {discountPercentage > 0 && (
              <div className="absolute left-4 top-4 z-10 bg-accent-500 px-2 py-1 text-sm font-bold text-white">
                {discountPercentage}% OFF
              </div>
            )}
          </div>
        </div>

        {/* Product Info */}
        <div>
          <h1 className="mb-2 text-3xl font-bold">{product.name}</h1>
          
          <div className="mb-4 flex items-center">
            <div className="flex">
              {[...Array(5)].map((_, i) => (
                <Star
                  key={i}
                  className={`h-5 w-5 ${i < product.rating ? 'fill-yellow-400 text-yellow-400' : 'text-gray-300'}`}
                />
              ))}
            </div>
            <span className="ml-2 text-gray-600">{product.rating.toFixed(1)}</span>
            <span className="mx-2 text-gray-400">•</span>
            <span className="text-gray-600">{product.reviews} reviews</span>
          </div>

          <div className="mb-6 flex items-end space-x-3">
            <span className="text-3xl font-bold">${product.price.toFixed(2)}</span>
            {product.originalPrice && (
              <span className="text-xl text-gray-500 line-through">${product.originalPrice.toFixed(2)}</span>
            )}
          </div>

          <p className="mb-6 text-gray-700">{product.description}</p>

          {/* Variants Selection */}
          {product.variants && product.variants.length > 0 && (
            <div className="mb-6">
              <h3 className="mb-3 text-sm font-semibold text-gray-600">
                Variants:
              </h3>
              <div className="flex flex-wrap gap-2">
                {product.variants.map((variant) => (
                  <button
                    key={variant.id}
                    onClick={() => setSelectedVariant(variant.id)}
                    disabled={!variant.inStock}
                    className={`rounded-md border px-4 py-2 text-sm font-medium transition-colors ${
                      selectedVariant === variant.id
                        ? 'border-blue-600 bg-blue-50 text-blue-600'
                        : variant.inStock
                        ? 'border-gray-300 bg-white hover:border-gray-400'
                        : 'cursor-not-allowed border-gray-200 bg-gray-100 text-gray-400'
                    }`}
                  >
                    {variant.name}
                    {!variant.inStock && ' (Out of Stock)'}
                  </button>
                ))}
              </div>
            </div>
          )}

          {/* Quantity */}
          <div className="mb-6">
            <h3 className="mb-3 text-sm font-semibold text-gray-600">
              Quantity:
            </h3>
            <div className="flex w-32 items-center rounded-md border border-gray-300">
              <button
                onClick={decrementQuantity}
                className="flex h-10 w-10 items-center justify-center text-gray-600 hover:bg-gray-100"
              >
                -
              </button>
              <input
                type="text"
                value={quantity}
                readOnly
                className="h-10 w-full border-x border-gray-300 bg-white text-center text-gray-700 outline-none"
              />
              <button
                onClick={incrementQuantity}
                className="flex h-10 w-10 items-center justify-center text-gray-600 hover:bg-gray-100"
              >
                +
              </button>
            </div>
          </div>

          {/* Action Buttons */}
          <div className="mb-8 flex flex-wrap gap-3">
            <button
              onClick={handleAddToCart}
              disabled={!product.inStock}
              className={`flex flex-1 items-center justify-center space-x-2 rounded-md px-6 py-3 font-medium ${
                product.inStock
                  ? 'bg-blue-600 text-white hover:bg-blue-700'
                  : 'cursor-not-allowed bg-gray-300 text-gray-500'
              }`}
            >
              <ShoppingCart size={20} />
              <span>{product.inStock ? 'Add to Cart' : 'Out of Stock'}</span>
            </button>
            <button className="flex items-center justify-center rounded-md border border-gray-300 px-4 py-3 hover:bg-gray-100">
              <Heart size={20} />
            </button>
            <button className="flex items-center justify-center rounded-md border border-gray-300 px-4 py-3 hover:bg-gray-100">
              <Share2 size={20} />
            </button>
          </div>

          {/* Product Highlights */}
          <div className="mb-8 space-y-3 rounded-lg border border-gray-200 bg-gray-50 p-4">
            <div className="flex items-start space-x-3">
              <Truck className="mt-0.5 h-5 w-5 flex-shrink-0 text-green-600" />
              <div>
                <p className="font-medium">Free Shipping</p>
                <p className="text-sm text-gray-600">On orders over $50</p>
              </div>
            </div>
            <div className="flex items-start space-x-3">
              <RotateCcw className="mt-0.5 h-5 w-5 flex-shrink-0 text-green-600" />
              <div>
                <p className="font-medium">30-Day Returns</p>
                <p className="text-sm text-gray-600">Hassle-free returns</p>
              </div>
            </div>
            <div className="flex items-start space-x-3">
              <ShieldCheck className="mt-0.5 h-5 w-5 flex-shrink-0 text-green-600" />
              <div>
                <p className="font-medium">Secure Checkout</p>
                <p className="text-sm text-gray-600">SSL encrypted payment</p>
              </div>
            </div>
          </div>
          
          {/* Stock Status */}
          <div className="mb-6 flex items-center space-x-2">
            {product.inStock ? (
              <>
                <Check className="h-5 w-5 text-green-500" />
                <span className="text-green-500">In Stock</span>
              </>
            ) : (
              <span className="text-red-500">Out of Stock</span>
            )}
          </div>
        </div>
      </div>

      {/* Tabs */}
      <div className="mb-12">
        <div className="mb-6 flex space-x-8 border-b border-gray-200">
          {[
            { id: 'description', label: 'Description' },
            { id: 'details', label: 'Details' },
            { id: 'reviews', label: 'Reviews' },
          ].map((tab) => (
            <button
              key={tab.id}
              onClick={() => setActiveTab(tab.id as any)}
              className={`relative pb-4 text-sm font-medium ${
                activeTab === tab.id
                  ? 'text-blue-600'
                  : 'text-gray-600 hover:text-gray-900'
              }`}
            >
              {tab.label}
              {activeTab === tab.id && (
                <span className="absolute bottom-0 left-0 h-1 w-full bg-blue-600"></span>
              )}
            </button>
          ))}
        </div>

        <div className="min-h-[200px]">
          {activeTab === 'description' && (
            <div>
              <p className="text-gray-700">{product.description}</p>
              <p className="mt-4 text-gray-700">
                Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.
              </p>
              <p className="mt-4 text-gray-700">
                Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.
              </p>
            </div>
          )}

          {activeTab === 'details' && (
            <div className="space-y-4">
              <div>
                <h3 className="font-semibold">Product Specifications</h3>
                <ul className="mt-2 list-inside list-disc space-y-1 text-gray-700">
                  <li>Material: Premium quality</li>
                  <li>Dimensions: 10" x 8" x 2"</li>
                  <li>Weight: 1.2 lbs</li>
                  <li>Country of Origin: United States</li>
                  <li>Warranty: 1 year</li>
                </ul>
              </div>
              <div>
                <h3 className="font-semibold">Package Contents</h3>
                <ul className="mt-2 list-inside list-disc space-y-1 text-gray-700">
                  <li>1 x {product.name}</li>
                  <li>1 x User Manual</li>
                  <li>1 x Warranty Card</li>
                </ul>
              </div>
            </div>
          )}

          {activeTab === 'reviews' && (
            <div>
              <div className="mb-6 flex items-center justify-between">
                <div>
                  <h3 className="text-lg font-semibold">Customer Reviews</h3>
                  <div className="mt-1 flex items-center">
                    <div className="flex">
                      {[...Array(5)].map((_, i) => (
                        <Star
                          key={i}
                          className={`h-5 w-5 ${i < product.rating ? 'fill-yellow-400 text-yellow-400' : 'text-gray-300'}`}
                        />
                      ))}
                    </div>
                    <span className="ml-2 text-gray-600">Based on {product.reviews} reviews</span>
                  </div>
                </div>
                <button className="rounded-md bg-blue-600 px-4 py-2 text-sm font-medium text-white hover:bg-blue-700">
                  Write a Review
                </button>
              </div>

              <div className="space-y-6">
                {/* Sample reviews */}
                <div className="border-b border-gray-200 pb-6">
                  <div className="mb-2 flex items-center justify-between">
                    <h4 className="font-medium">John D.</h4>
                    <span className="text-sm text-gray-500">2 weeks ago</span>
                  </div>
                  <div className="mb-2 flex">
                    {[...Array(5)].map((_, i) => (
                      <Star
                        key={i}
                        className={`h-4 w-4 ${i < 5 ? 'fill-yellow-400 text-yellow-400' : 'text-gray-300'}`}
                      />
                    ))}
                  </div>
                  <p className="text-gray-700">
                    Excellent product! Exceeded my expectations in terms of quality and functionality. Would definitely recommend it to others.
                  </p>
                </div>

                <div className="border-b border-gray-200 pb-6">
                  <div className="mb-2 flex items-center justify-between">
                    <h4 className="font-medium">Sarah M.</h4>
                    <span className="text-sm text-gray-500">1 month ago</span>
                  </div>
                  <div className="mb-2 flex">
                    {[...Array(5)].map((_, i) => (
                      <Star
                        key={i}
                        className={`h-4 w-4 ${i < 4 ? 'fill-yellow-400 text-yellow-400' : 'text-gray-300'}`}
                      />
                    ))}
                  </div>
                  <p className="text-gray-700">
                    Great product for the price. Shipping was quick and the item arrived in perfect condition. Would buy from this store again.
                  </p>
                </div>
              </div>
            </div>
          )}
        </div>
      </div>

      {/* Related Products */}
      <div>
        <h2 className="mb-6 text-2xl font-bold">You Might Also Like</h2>
        <div className="grid grid-cols-2 gap-6 sm:grid-cols-2 md:grid-cols-3 lg:grid-cols-4">
          {relatedProducts.map((product) => (
            <ProductCard key={product.id} product={product} />
          ))}
        </div>
      </div>
    </div>
  );
};

export default ProductPage;
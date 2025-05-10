import React, { useState, useEffect } from 'react';
import { useSearchParams } from 'react-router-dom';
import { SlidersHorizontal } from 'lucide-react';
import ProductGrid from '../components/products/ProductGrid';
import ProductFilters from '../components/products/ProductFilters';
import { mockProducts, getProductCategories, getFilterOptions } from '../data/mockProducts';
import { ProductType } from '../types/product';

const ProductsPage: React.FC = () => {
  const [searchParams, setSearchParams] = useSearchParams();
  const [products, setProducts] = useState<ProductType[]>([]);
  const [loading, setLoading] = useState(true);
  const [showFilters, setShowFilters] = useState(false);
  
  // Get category from URL
  const categoryParam = searchParams.get('category');
  
  // Get filter options
  const categories = getProductCategories();
  const filterSections = getFilterOptions();
  
  // Track active filters
  const [activeFilters, setActiveFilters] = useState<Record<string, string[]>>({});
  
  // Filter products based on criteria
  useEffect(() => {
    setLoading(true);
    
    // Simulate API call delay
    setTimeout(() => {
      let filteredProducts = [...mockProducts];
      
      // Filter by category if set
      if (categoryParam) {
        filteredProducts = filteredProducts.filter(product => 
          product.categories.some(cat => cat.toLowerCase() === categoryParam.toLowerCase())
        );
      }
      
      // Apply price filters if any
      if (activeFilters['Price']?.length > 0) {
        filteredProducts = filteredProducts.filter(product => {
          const minPrice = Math.min(...product.variants.map(v => v.price));
          
          return activeFilters['Price'].some(priceRange => {
            switch (priceRange) {
              case 'under-25':
                return minPrice < 25;
              case '25-50':
                return minPrice >= 25 && minPrice < 50;
              case '50-100':
                return minPrice >= 50 && minPrice < 100;
              case 'over-100':
                return minPrice >= 100;
              default:
                return true;
            }
          });
        });
      }
      
      // Apply color filters if any
      if (activeFilters['Color']?.length > 0) {
        filteredProducts = filteredProducts.filter(product => 
          product.variants.some(variant => 
            activeFilters['Color'].includes(variant.color.toLowerCase())
          )
        );
      }
      
      setProducts(filteredProducts);
      setLoading(false);
    }, 500);
  }, [categoryParam, activeFilters]);
  
  // Handle filter changes
  const handleFilterChange = (filterName: string, value: string) => {
    setActiveFilters(prev => {
      const current = prev[filterName] || [];
      
      // Toggle the filter value
      const updated = current.includes(value)
        ? current.filter(v => v !== value)
        : [...current, value];
      
      return {
        ...prev,
        [filterName]: updated.length > 0 ? updated : [] // Remove empty arrays
      };
    });
  };
  
  // Handle category changes
  const handleCategoryChange = (categoryId: string) => {
    if (categoryParam === categoryId) {
      // Clear category if it's already selected
      searchParams.delete('category');
    } else {
      // Set new category
      searchParams.set('category', categoryId);
    }
    setSearchParams(searchParams);
  };
  
  // Clear all filters
  const clearFilters = () => {
    setActiveFilters({});
    searchParams.delete('category');
    setSearchParams(searchParams);
  };
  
  // Get active category name for display
  const activeCategoryName = categoryParam 
    ? categories.find(c => c.id === categoryParam)?.name 
    : null;

  return (
    <div className="bg-gray-50 min-h-screen py-8 md:py-12">
      <div className="container mx-auto px-4">
        {/* Page Header */}
        <div className="mb-8">
          <h1 className="text-2xl md:text-3xl font-bold text-gray-900">
            {activeCategoryName || 'All Products'}
          </h1>
          <p className="text-gray-600 mt-2">
            {loading ? 'Loading products...' : `${products.length} products available`}
          </p>
        </div>
        
        {/* Mobile Filter Toggle */}
        <div className="md:hidden mb-6">
          <button
            className="flex items-center text-sm text-gray-700 font-medium gap-x-2 p-2 border border-gray-300 rounded-md bg-white"
            onClick={() => setShowFilters(!showFilters)}
          >
            <SlidersHorizontal size={16} />
            {showFilters ? 'Hide Filters' : 'Show Filters'}
          </button>
        </div>
        
        <div className="flex flex-col md:flex-row gap-8">
          {/* Filters - Mobile Collapsible, Desktop Always Visible */}
          <div className={`md:w-1/4 transition-all ${showFilters || 'hidden md:block'}`}>
            <ProductFilters
              categories={categories}
              filters={filterSections}
              activeFilters={activeFilters}
              onFilterChange={handleFilterChange}
              onClearFilters={clearFilters}
              onCategoryChange={handleCategoryChange}
              activeCategory={categoryParam || undefined}
            />
          </div>
          
          {/* Product Grid */}
          <div className="flex-1">
            <ProductGrid products={products} loading={loading} />
          </div>
        </div>
      </div>
    </div>
  );
};

export default ProductsPage;
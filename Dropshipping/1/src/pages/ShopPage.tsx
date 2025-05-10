import { useState, useEffect } from 'react';
import { useSearchParams } from 'react-router-dom';
import ProductGrid from '../components/Products/ProductGrid';
import ProductFilter from '../components/Products/ProductFilter';

const ShopPage = () => {
  const [searchParams, setSearchParams] = useSearchParams();
  const [category, setCategory] = useState<string | undefined>(
    searchParams.get('category') || undefined
  );
  const [searchQuery, setSearchQuery] = useState<string | undefined>(
    searchParams.get('q') || undefined
  );
  const [sortBy, setSortBy] = useState<string>(
    searchParams.get('sort') || 'newest'
  );

  useEffect(() => {
    // Update search params when filters change
    const params = new URLSearchParams();
    if (category) params.set('category', category);
    if (searchQuery) params.set('q', searchQuery);
    if (sortBy !== 'newest') params.set('sort', sortBy);
    setSearchParams(params);
  }, [category, searchQuery, sortBy, setSearchParams]);

  const handleFilterChange = (filters: {
    category?: string;
    priceRange?: [number, number];
    rating?: number;
    onSale?: boolean;
  }) => {
    setCategory(filters.category);
    // Add more filter handling as needed
  };

  const handleSortChange = (sortValue: string) => {
    setSortBy(sortValue);
  };

  return (
    <div className="container mx-auto px-4 py-8">
      <div className="mb-8">
        <h1 className="text-3xl font-bold">
          {category
            ? `${category.charAt(0).toUpperCase() + category.slice(1)} Products`
            : searchQuery
            ? `Search results for "${searchQuery}"`
            : 'All Products'}
        </h1>
      </div>

      <ProductFilter
        onFilterChange={handleFilterChange}
        onSortChange={handleSortChange}
      />

      <ProductGrid
        category={category}
        searchQuery={searchQuery}
        sortBy={sortBy}
      />
    </div>
  );
};

export default ShopPage;
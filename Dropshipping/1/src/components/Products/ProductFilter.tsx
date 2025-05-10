import { useState } from 'react';
import { Filter, ChevronDown } from 'lucide-react';

interface ProductFilterProps {
  onFilterChange: (filters: {
    category?: string;
    priceRange?: [number, number];
    rating?: number;
    onSale?: boolean;
  }) => void;
  onSortChange: (sortBy: string) => void;
}

const categories = [
  { id: '', name: 'All Categories' },
  { id: 'electronics', name: 'Electronics' },
  { id: 'clothing', name: 'Clothing' },
  { id: 'home', name: 'Home & Kitchen' },
  { id: 'beauty', name: 'Beauty' },
];

const sortOptions = [
  { id: 'newest', name: 'Newest' },
  { id: 'price-asc', name: 'Price: Low to High' },
  { id: 'price-desc', name: 'Price: High to Low' },
  { id: 'rating', name: 'Highest Rated' },
];

const priceRanges = [
  { id: '0-25', name: 'Under $25', range: [0, 25] },
  { id: '25-50', name: '$25 to $50', range: [25, 50] },
  { id: '50-100', name: '$50 to $100', range: [50, 100] },
  { id: '100-200', name: '$100 to $200', range: [100, 200] },
  { id: '200-99999', name: '$200 & Above', range: [200, 99999] },
];

const ProductFilter = ({ onFilterChange, onSortChange }: ProductFilterProps) => {
  const [filters, setFilters] = useState({
    category: '',
    priceRange: [0, 99999] as [number, number],
    rating: 0,
    onSale: false,
  });

  const [sortBy, setSortBy] = useState('newest');
  const [isMobileFilterOpen, setIsMobileFilterOpen] = useState(false);

  const handleFilterChange = (
    name: string,
    value: string | number | boolean | [number, number]
  ) => {
    const newFilters = { ...filters, [name]: value };
    setFilters(newFilters);
    onFilterChange(newFilters);
  };

  const handleSortChange = (value: string) => {
    setSortBy(value);
    onSortChange(value);
  };

  const handleRatingChange = (rating: number) => {
    const newRating = filters.rating === rating ? 0 : rating;
    handleFilterChange('rating', newRating);
  };

  const toggleMobileFilter = () => {
    setIsMobileFilterOpen(!isMobileFilterOpen);
  };

  return (
    <div className="mb-6">
      <div className="flex flex-wrap items-center justify-between gap-4">
        <button
          onClick={toggleMobileFilter}
          className="flex items-center space-x-2 rounded-md border border-gray-300 px-4 py-2 text-sm font-medium lg:hidden"
        >
          <Filter size={16} />
          <span>Filter</span>
        </button>

        <div className="ml-auto flex flex-wrap items-center space-x-4">
          <div className="flex items-center space-x-2">
            <span className="text-sm text-gray-600">Sort by:</span>
            <select
              value={sortBy}
              onChange={(e) => handleSortChange(e.target.value)}
              className="rounded-md border border-gray-300 bg-white py-1.5 pl-3 pr-8 text-sm font-medium focus:outline-none focus:ring-2 focus:ring-blue-500 focus:border-blue-500"
            >
              {sortOptions.map((option) => (
                <option key={option.id} value={option.id}>
                  {option.name}
                </option>
              ))}
            </select>
          </div>
        </div>
      </div>

      {/* Mobile Filters */}
      <div
        className={`mt-4 transform overflow-hidden transition-all duration-300 lg:hidden ${
          isMobileFilterOpen ? 'max-h-[2000px]' : 'max-h-0'
        }`}
      >
        <div className="rounded-md border border-gray-200 bg-white p-4">
          <div className="mb-4">
            <h3 className="mb-2 font-medium">Categories</h3>
            <div className="space-y-2">
              {categories.map((category) => (
                <label key={category.id} className="flex items-center space-x-2">
                  <input
                    type="radio"
                    name="category"
                    value={category.id}
                    checked={filters.category === category.id}
                    onChange={(e) => handleFilterChange('category', e.target.value)}
                    className="h-4 w-4 rounded-full border-gray-300 text-blue-600 focus:ring-blue-500"
                  />
                  <span className="text-sm">{category.name}</span>
                </label>
              ))}
            </div>
          </div>

          <div className="mb-4">
            <h3 className="mb-2 font-medium">Price Range</h3>
            <div className="space-y-2">
              {priceRanges.map((priceRange) => (
                <label key={priceRange.id} className="flex items-center space-x-2">
                  <input
                    type="radio"
                    name="priceRange"
                    checked={
                      filters.priceRange[0] === priceRange.range[0] &&
                      filters.priceRange[1] === priceRange.range[1]
                    }
                    onChange={() => handleFilterChange('priceRange', priceRange.range as [number, number])}
                    className="h-4 w-4 rounded-full border-gray-300 text-blue-600 focus:ring-blue-500"
                  />
                  <span className="text-sm">{priceRange.name}</span>
                </label>
              ))}
            </div>
          </div>

          <div className="mb-4">
            <h3 className="mb-2 font-medium">Rating</h3>
            <div className="space-y-2">
              {[5, 4, 3, 2, 1].map((rating) => (
                <label key={rating} className="flex items-center space-x-2">
                  <input
                    type="radio"
                    name="rating"
                    checked={filters.rating === rating}
                    onChange={() => handleRatingChange(rating)}
                    className="h-4 w-4 rounded-full border-gray-300 text-blue-600 focus:ring-blue-500"
                  />
                  <div className="flex items-center">
                    {[...Array(5)].map((_, i) => (
                      <svg
                        key={i}
                        className={`h-4 w-4 ${i < rating ? 'text-yellow-400' : 'text-gray-300'}`}
                        fill="currentColor"
                        viewBox="0 0 20 20"
                      >
                        <path d="M9.049 2.927c.3-.921 1.603-.921 1.902 0l1.07 3.292a1 1 0 00.95.69h3.462c.969 0 1.371 1.24.588 1.81l-2.8 2.034a1 1 0 00-.364 1.118l1.07 3.292c.3.921-.755 1.688-1.54 1.118l-2.8-2.034a1 1 0 00-1.175 0l-2.8 2.034c-.784.57-1.838-.197-1.539-1.118l1.07-3.292a1 1 0 00-.364-1.118L2.98 8.72c-.783-.57-.38-1.81.588-1.81h3.461a1 1 0 00.951-.69l1.07-3.292z" />
                      </svg>
                    ))}
                    <span className="ml-1 text-xs">& up</span>
                  </div>
                </label>
              ))}
            </div>
          </div>

          <div>
            <label className="flex items-center space-x-2">
              <input
                type="checkbox"
                checked={filters.onSale}
                onChange={(e) => handleFilterChange('onSale', e.target.checked)}
                className="h-4 w-4 rounded border-gray-300 text-blue-600 focus:ring-blue-500"
              />
              <span className="text-sm">On Sale</span>
            </label>
          </div>
        </div>
      </div>

      {/* Desktop Filters */}
      <div className="mt-6 hidden lg:block">
        <div className="grid grid-cols-4 gap-4">
          <div>
            <div className="mb-2 flex items-center justify-between">
              <h3 className="font-medium">Categories</h3>
              <ChevronDown size={16} />
            </div>
            <div className="space-y-2">
              {categories.map((category) => (
                <label key={category.id} className="flex items-center space-x-2">
                  <input
                    type="radio"
                    name="category"
                    value={category.id}
                    checked={filters.category === category.id}
                    onChange={(e) => handleFilterChange('category', e.target.value)}
                    className="h-4 w-4 rounded-full border-gray-300 text-blue-600 focus:ring-blue-500"
                  />
                  <span className="text-sm">{category.name}</span>
                </label>
              ))}
            </div>
          </div>

          <div>
            <div className="mb-2 flex items-center justify-between">
              <h3 className="font-medium">Price Range</h3>
              <ChevronDown size={16} />
            </div>
            <div className="space-y-2">
              {priceRanges.map((priceRange) => (
                <label key={priceRange.id} className="flex items-center space-x-2">
                  <input
                    type="radio"
                    name="priceRange"
                    checked={
                      filters.priceRange[0] === priceRange.range[0] &&
                      filters.priceRange[1] === priceRange.range[1]
                    }
                    onChange={() => handleFilterChange('priceRange', priceRange.range as [number, number])}
                    className="h-4 w-4 rounded-full border-gray-300 text-blue-600 focus:ring-blue-500"
                  />
                  <span className="text-sm">{priceRange.name}</span>
                </label>
              ))}
            </div>
          </div>

          <div>
            <div className="mb-2 flex items-center justify-between">
              <h3 className="font-medium">Rating</h3>
              <ChevronDown size={16} />
            </div>
            <div className="space-y-2">
              {[5, 4, 3, 2, 1].map((rating) => (
                <label key={rating} className="flex items-center space-x-2">
                  <input
                    type="radio"
                    name="rating"
                    checked={filters.rating === rating}
                    onChange={() => handleRatingChange(rating)}
                    className="h-4 w-4 rounded-full border-gray-300 text-blue-600 focus:ring-blue-500"
                  />
                  <div className="flex items-center">
                    {[...Array(5)].map((_, i) => (
                      <svg
                        key={i}
                        className={`h-4 w-4 ${i < rating ? 'text-yellow-400' : 'text-gray-300'}`}
                        fill="currentColor"
                        viewBox="0 0 20 20"
                      >
                        <path d="M9.049 2.927c.3-.921 1.603-.921 1.902 0l1.07 3.292a1 1 0 00.95.69h3.462c.969 0 1.371 1.24.588 1.81l-2.8 2.034a1 1 0 00-.364 1.118l1.07 3.292c.3.921-.755 1.688-1.54 1.118l-2.8-2.034a1 1 0 00-1.175 0l-2.8 2.034c-.784.57-1.838-.197-1.539-1.118l1.07-3.292a1 1 0 00-.364-1.118L2.98 8.72c-.783-.57-.38-1.81.588-1.81h3.461a1 1 0 00.951-.69l1.07-3.292z" />
                      </svg>
                    ))}
                    <span className="ml-1 text-xs">& up</span>
                  </div>
                </label>
              ))}
            </div>
          </div>

          <div>
            <div className="mb-2 flex items-center justify-between">
              <h3 className="font-medium">Other Filters</h3>
              <ChevronDown size={16} />
            </div>
            <div>
              <label className="flex items-center space-x-2">
                <input
                  type="checkbox"
                  checked={filters.onSale}
                  onChange={(e) => handleFilterChange('onSale', e.target.checked)}
                  className="h-4 w-4 rounded border-gray-300 text-blue-600 focus:ring-blue-500"
                />
                <span className="text-sm">On Sale</span>
              </label>
            </div>
          </div>
        </div>
      </div>
    </div>
  );
};

export default ProductFilter;
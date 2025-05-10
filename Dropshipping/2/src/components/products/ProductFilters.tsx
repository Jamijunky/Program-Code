import React, { useState } from 'react';
import { Filter, X, ChevronDown, ChevronUp } from 'lucide-react';

interface Category {
  id: string;
  name: string;
}

interface FilterOption {
  id: string;
  name: string;
}

interface FilterSection {
  name: string;
  options: FilterOption[];
}

interface ProductFiltersProps {
  categories: Category[];
  filters: FilterSection[];
  activeFilters: Record<string, string[]>;
  onFilterChange: (name: string, value: string) => void;
  onClearFilters: () => void;
  onCategoryChange: (categoryId: string) => void;
  activeCategory?: string;
}

const ProductFilters: React.FC<ProductFiltersProps> = ({
  categories,
  filters,
  activeFilters,
  onFilterChange,
  onClearFilters,
  onCategoryChange,
  activeCategory,
}) => {
  const [mobileFiltersOpen, setMobileFiltersOpen] = useState(false);
  const [expandedSections, setExpandedSections] = useState<Record<string, boolean>>(
    // Initialize all sections as expanded
    filters.reduce((acc, filter) => ({ ...acc, [filter.name]: true }), {})
  );

  const toggleSection = (name: string) => {
    setExpandedSections(prev => ({
      ...prev,
      [name]: !prev[name],
    }));
  };

  const activeFilterCount = Object.values(activeFilters).flat().length + (activeCategory ? 1 : 0);

  return (
    <div className="relative">
      {/* Mobile filter dialog */}
      <div className="md:hidden">
        <button
          type="button"
          className="flex items-center text-sm text-gray-700 font-medium gap-x-2"
          onClick={() => setMobileFiltersOpen(true)}
        >
          <Filter size={16} />
          Filters
          {activeFilterCount > 0 && (
            <span className="bg-primary-700 text-white rounded-full px-2 py-0.5 text-xs">
              {activeFilterCount}
            </span>
          )}
        </button>
      </div>

      {/* Mobile filter overlay */}
      {mobileFiltersOpen && (
        <div className="fixed inset-0 z-40 bg-black bg-opacity-25" onClick={() => setMobileFiltersOpen(false)} />
      )}

      {/* Mobile filter panel */}
      <div
        className={`fixed inset-0 z-50 transform transition-transform duration-300 md:hidden ${
          mobileFiltersOpen ? 'translate-x-0' : 'translate-x-full'
        }`}
      >
        <div className="ml-auto w-full max-w-xs h-full bg-white shadow-xl flex flex-col">
          <div className="flex items-center justify-between px-4 py-3 border-b">
            <h2 className="text-lg font-medium text-gray-900">Filters</h2>
            <button
              type="button"
              className="text-gray-400 hover:text-gray-500"
              onClick={() => setMobileFiltersOpen(false)}
            >
              <X size={20} />
            </button>
          </div>

          <div className="flex-1 overflow-y-auto p-4">
            {/* Categories */}
            <div className="mb-6">
              <h3 className="text-sm font-medium text-gray-900 mb-3">Categories</h3>
              <div className="space-y-2">
                {categories.map((category) => (
                  <div key={category.id} className="flex items-center">
                    <button
                      className={`text-sm ${
                        activeCategory === category.id
                          ? 'text-primary-700 font-medium'
                          : 'text-gray-600 hover:text-gray-800'
                      }`}
                      onClick={() => onCategoryChange(category.id)}
                    >
                      {category.name}
                    </button>
                  </div>
                ))}
              </div>
            </div>

            {/* Filter sections */}
            {filters.map((section) => (
              <div key={section.name} className="mb-6 border-t border-gray-200 pt-6">
                <div className="flex items-center justify-between mb-3">
                  <h3 className="text-sm font-medium text-gray-900">{section.name}</h3>
                  <button onClick={() => toggleSection(section.name)}>
                    {expandedSections[section.name] ? (
                      <ChevronUp size={16} className="text-gray-500" />
                    ) : (
                      <ChevronDown size={16} className="text-gray-500" />
                    )}
                  </button>
                </div>

                {expandedSections[section.name] && (
                  <div className="space-y-2">
                    {section.options.map((option) => (
                      <div key={option.id} className="flex items-center">
                        <input
                          id={`mobile-${section.name}-${option.id}`}
                          name={`${section.name}[]`}
                          type="checkbox"
                          className="h-4 w-4 rounded border-gray-300 text-primary-700 focus:ring-primary-500"
                          checked={activeFilters[section.name]?.includes(option.id) || false}
                          onChange={() => onFilterChange(section.name, option.id)}
                        />
                        <label
                          htmlFor={`mobile-${section.name}-${option.id}`}
                          className="ml-3 text-sm text-gray-600"
                        >
                          {option.name}
                        </label>
                      </div>
                    ))}
                  </div>
                )}
              </div>
            ))}

            {activeFilterCount > 0 && (
              <button
                type="button"
                className="mt-4 text-sm text-primary-700 hover:text-primary-800"
                onClick={onClearFilters}
              >
                Clear all filters
              </button>
            )}
          </div>
        </div>
      </div>

      {/* Desktop filters */}
      <div className="hidden md:block bg-white rounded-lg shadow-sm p-6">
        <h3 className="text-lg font-medium text-gray-900 mb-4">Filters</h3>

        {/* Categories */}
        <div className="mb-6">
          <h4 className="text-sm font-medium text-gray-900 mb-3">Categories</h4>
          <div className="space-y-2">
            {categories.map((category) => (
              <div key={category.id} className="flex items-center">
                <button
                  className={`text-sm ${
                    activeCategory === category.id
                      ? 'text-primary-700 font-medium'
                      : 'text-gray-600 hover:text-gray-800'
                  }`}
                  onClick={() => onCategoryChange(category.id)}
                >
                  {category.name}
                </button>
              </div>
            ))}
          </div>
        </div>

        {/* Filter sections */}
        {filters.map((section) => (
          <div key={section.name} className="mb-6 border-t border-gray-200 pt-6">
            <div className="flex items-center justify-between mb-3">
              <h4 className="text-sm font-medium text-gray-900">{section.name}</h4>
              <button onClick={() => toggleSection(section.name)}>
                {expandedSections[section.name] ? (
                  <ChevronUp size={16} className="text-gray-500" />
                ) : (
                  <ChevronDown size={16} className="text-gray-500" />
                )}
              </button>
            </div>

            {expandedSections[section.name] && (
              <div className="space-y-2">
                {section.options.map((option) => (
                  <div key={option.id} className="flex items-center">
                    <input
                      id={`desktop-${section.name}-${option.id}`}
                      name={`${section.name}[]`}
                      type="checkbox"
                      className="h-4 w-4 rounded border-gray-300 text-primary-700 focus:ring-primary-500"
                      checked={activeFilters[section.name]?.includes(option.id) || false}
                      onChange={() => onFilterChange(section.name, option.id)}
                    />
                    <label
                      htmlFor={`desktop-${section.name}-${option.id}`}
                      className="ml-3 text-sm text-gray-600"
                    >
                      {option.name}
                    </label>
                  </div>
                ))}
              </div>
            )}
          </div>
        ))}

        {activeFilterCount > 0 && (
          <button
            type="button"
            className="text-sm text-primary-700 hover:text-primary-800"
            onClick={onClearFilters}
          >
            Clear all filters
          </button>
        )}
      </div>
    </div>
  );
};

export default ProductFilters;
import React, { useEffect, useState } from 'react';
import axios from 'axios';
import Link from 'next/link';
import { professionBanners } from '../utils/professionBanners';

const professionOptions = [
  'doctor', 'engineer', 'lawyer', 'politician', 'developer', 'teacher', 'artist', 'accountant', 'nurse', 'architect', 'other'
];

export default function Home() {
  const [products, setProducts] = useState([]);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState('');

  useEffect(() => {
    axios.get(`${process.env.NEXT_PUBLIC_API_URL}/products`)
      .then(res => { setProducts(res.data); setLoading(false); })
      .catch(() => { setError('Failed to load products'); setLoading(false); });
  }, []);

  function productsForProfession(prof) {
    return products.filter(p => (p.professions || []).includes(prof));
  }

  function featuredForProfession(prof) {
    return products.filter(p => (p.professions || []).includes(prof) && p.featured);
  }

  // Sorting for all products section
  const [sort, setSort] = useState('default');
  let sortedProducts = [...products];
  if (sort === 'price-asc') sortedProducts.sort((a, b) => (a.variants?.[0]?.price ?? 0) - (b.variants?.[0]?.price ?? 0));
  if (sort === 'price-desc') sortedProducts.sort((a, b) => (b.variants?.[0]?.price ?? 0) - (a.variants?.[0]?.price ?? 0));
  if (sort === 'popularity') sortedProducts.sort((a, b) => (b.popularity ?? 0) - (a.popularity ?? 0));

  return (
    <main className="max-w-7xl mx-auto px-4 py-8">
      <h1 className="text-4xl font-bold mb-8 text-center">Welcome to PFM</h1>
      <p className="text-lg text-gray-600 mb-10 text-center">Modern Dropshipping eCommerce Platform for Every Profession</p>
      {loading ? (
        <p>Loading...</p>
      ) : error ? (
        <p className="text-red-500">{error}</p>
      ) : (
        <>
          {professionOptions.map(prof => {
            const profProducts = productsForProfession(prof);
            const featured = featuredForProfession(prof);
            if (!profProducts.length) return null;
            const banner = professionBanners[prof];
            return (
              <section key={prof} className="mb-10">
                {/* Profession Banner */}
                {banner && (
                  <div className="flex items-center gap-4 mb-4">
                    <img src={banner.img} alt={prof + ' banner'} className="h-20 w-32 object-cover rounded shadow" />
                    <div>
                      <div className="text-2xl font-bold capitalize">For {prof}s</div>
                      <div className="text-sm text-gray-700 italic">{banner.slogan}</div>
                    </div>
                    {featured.length > 0 && <span className="ml-4 bg-yellow-200 text-yellow-900 px-2 py-0.5 rounded-full text-xs font-semibold">Featured</span>}
                  </div>
                )}
                {/* Featured Carousel */}
                {featured.length > 0 && (
                  <div className="overflow-x-auto flex gap-4 pb-2 mb-2">
                    {featured.map(product => (
                      <Link key={product._id} href={`/product/${product._id}`} className="bg-gradient-to-br from-yellow-100 to-yellow-50 border border-yellow-300 min-w-[220px] max-w-xs p-4 rounded shadow hover:shadow-lg transition flex-shrink-0">
                        <div className="font-bold text-lg mb-2">{product.name}</div>
                        <div className="text-gray-700 mb-2">${product.variants?.[0]?.price?.toFixed(2)}</div>
                        <div className="text-xs text-yellow-700 mt-1 font-semibold">Featured</div>
                      </Link>
                    ))}
                  </div>
                )}
                {/* All Profession Products */}
                <div className="overflow-x-auto flex gap-4 pb-2">
                  {profProducts.map(product => (
                    <Link key={product._id} href={`/product/${product._id}`} className="bg-white min-w-[220px] max-w-xs p-4 rounded shadow hover:shadow-lg transition flex-shrink-0">
                      <div className="font-bold text-lg mb-2">{product.name}</div>
                      <div className="text-gray-500 mb-2">${product.variants?.[0]?.price?.toFixed(2)}</div>
                      <div className="text-xs text-blue-600 mt-1">
                        {(product.professions || []).map(prof => (
                          <span key={prof} className="inline-block mr-1 px-2 py-0.5 bg-blue-100 rounded-full">{prof.charAt(0).toUpperCase() + prof.slice(1)}</span>
                        ))}
                      </div>
                    </Link>
                  ))}
                </div>
              </section>
            );
          })}
          {/* Most Popular Section */}
          <section className="mb-10">
            <div className="flex items-center gap-4 mb-2">
              <h2 className="text-2xl font-bold">Most Popular</h2>
            </div>
            <div className="grid grid-cols-1 md:grid-cols-3 gap-6">
              {[...products].sort((a, b) => (b.popularity ?? 0) - (a.popularity ?? 0)).slice(0, 6).map(product => (
                <Link key={product._id} href={`/product/${product._id}`} className="bg-white p-4 rounded shadow hover:shadow-lg transition">
                  <div className="font-bold text-lg mb-2">{product.name}</div>
                  <div className="text-gray-500 mb-2">${product.variants?.[0]?.price?.toFixed(2)}</div>
                  <div className="text-xs text-blue-600 mt-1">
                    {(product.professions || []).map(prof => (
                      <span key={prof} className="inline-block mr-1 px-2 py-0.5 bg-blue-100 rounded-full">{prof.charAt(0).toUpperCase() + prof.slice(1)}</span>
                    ))}
                  </div>
                  {product.featured && <div className="text-xs text-yellow-700 font-semibold mt-2">Featured</div>}
                </Link>
              ))}
            </div>
          </section>

          {/* All Products Section */}
          <section className="mb-10">
            <div className="flex items-center gap-4 mb-2">
              <h2 className="text-2xl font-bold">All Products</h2>
              <label className="text-sm font-medium">Sort by:</label>
              <select value={sort} onChange={e => setSort(e.target.value)} className="border p-1 rounded">
                <option value="default">Default</option>
                <option value="price-asc">Price: Low to High</option>
                <option value="price-desc">Price: High to Low</option>
                <option value="popularity">Popularity</option>
              </select>
            </div>
            <div className="grid grid-cols-1 md:grid-cols-3 gap-6">
              {sortedProducts.map(product => (
                <Link key={product._id} href={`/product/${product._id}`} className="bg-white p-4 rounded shadow hover:shadow-lg transition">
                  <div className="font-bold text-lg mb-2">{product.name}</div>
                  <div className="text-gray-500 mb-2">${product.variants?.[0]?.price?.toFixed(2)}</div>
                  <div className="text-xs text-blue-600 mt-1">
                    {(product.professions || []).map(prof => (
                      <span key={prof} className="inline-block mr-1 px-2 py-0.5 bg-blue-100 rounded-full">{prof.charAt(0).toUpperCase() + prof.slice(1)}</span>
                    ))}
                  </div>
                  {product.featured && <div className="text-xs text-yellow-700 font-semibold mt-2">Featured</div>}
                </Link>
              ))}
            </div>
          </section>
        </>
      )}
    </main>
  );
}

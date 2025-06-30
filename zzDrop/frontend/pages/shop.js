import { useEffect, useState } from 'react';
import axios from 'axios';
import Link from 'next/link';

export default function Shop() {
  const [products, setProducts] = useState([]);
  const [loading, setLoading] = useState(true);
  const [search, setSearch] = useState('');
  const [category, setCategory] = useState('');
  const [categories, setCategories] = useState([]);
  const [page, setPage] = useState(1);
  const [hasMore, setHasMore] = useState(true);

  useEffect(() => {
    axios.get(`${process.env.NEXT_PUBLIC_API_URL}/categories`).then(res => setCategories(res.data));
  }, []);

  useEffect(() => {
    setLoading(true);
    axios.get(`${process.env.NEXT_PUBLIC_API_URL}/products`, {
      params: { search, category, page, limit: 20 }
    }).then(res => {
      setProducts(res.data);
      setHasMore(res.data.length === 20);
      setLoading(false);
    });
  }, [search, category, page]);

  return (
    <main className="max-w-7xl mx-auto px-4 py-8">
      <h1 className="text-3xl font-bold mb-6">Shop</h1>
      <div className="flex flex-col md:flex-row md:items-center mb-6 gap-4">
        <input
          type="text"
          placeholder="Search products..."
          className="border p-2 rounded w-full md:w-1/3"
          value={search}
          onChange={e => { setSearch(e.target.value); setPage(1); }}
        />
        <select
          className="border p-2 rounded w-full md:w-1/4"
          value={category}
          onChange={e => { setCategory(e.target.value); setPage(1); }}
        >
          <option value="">All Categories</option>
          {categories.map(cat => (
            <option key={cat._id} value={cat.name}>{cat.name}</option>
          ))}
        </select>
      </div>
      {loading ? (
        <p>Loading...</p>
      ) : (
        <div className="grid grid-cols-2 md:grid-cols-4 gap-6">
          {products.map(product => (
            <Link key={product._id} href={`/product/${product._id}`}>
              <div className="border rounded-lg p-4 bg-white hover:shadow-lg transition cursor-pointer">
                <img src={product.images?.[0] || '/placeholder.png'} alt={product.name} className="w-full h-40 object-cover mb-2 rounded" />
                <h2 className="font-semibold text-lg mb-1">{product.name}</h2>
                <p className="text-gray-600 mb-1">{product.categories?.join(', ')}</p>
                <p className="font-bold text-blue-600">${product.variants?.[0]?.price || 'N/A'}</p>
              </div>
            </Link>
          ))}
        </div>
      )}
      <div className="flex justify-center mt-8 gap-2">
        <button
          className="px-4 py-2 bg-gray-200 rounded disabled:opacity-50"
          onClick={() => setPage(page - 1)}
          disabled={page === 1}
        >Prev</button>
        <button
          className="px-4 py-2 bg-gray-200 rounded disabled:opacity-50"
          onClick={() => setPage(page + 1)}
          disabled={!hasMore}
        >Next</button>
      </div>
    </main>
  );
}

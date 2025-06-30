import { useEffect, useState } from 'react';
import axios from 'axios';
import { useRouter } from 'next/router';

export default function AdminInventory() {
  const router = useRouter();
  const [products, setProducts] = useState([]);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState('');

  useEffect(() => {
    const token = localStorage.getItem('token');
    if (!token) return router.push('/login');
    axios.get(`${process.env.NEXT_PUBLIC_API_URL}/products`, {
      headers: { Authorization: `Bearer ${token}` }
    })
      .then(res => { setProducts(res.data); setLoading(false); })
      .catch(() => setLoading(false));
  }, [router]);

  async function handleStockUpdate(id, variantIdx, newStock) {
    const token = localStorage.getItem('token');
    const product = products.find(p => p._id === id);
    const variants = [...product.variants];
    variants[variantIdx].stock = newStock;
    await axios.put(`${process.env.NEXT_PUBLIC_API_URL}/products/${id}`, { variants }, {
      headers: { Authorization: `Bearer ${token}` }
    });
    setProducts(products.map(p => p._id === id ? { ...p, variants } : p));
  }

  if (loading) return <p>Loading...</p>;

  return (
    <main className="max-w-5xl mx-auto px-4 py-8">
      <h1 className="text-3xl font-bold mb-6">Inventory Management</h1>
      <div className="grid grid-cols-1 gap-6">
        {products.map(product => (
          <div key={product._id} className="border rounded-lg p-4 bg-white flex flex-col gap-2">
            <h2 className="font-semibold text-lg">{product.name}</h2>
            {product.variants?.map((variant, idx) => (
              <div key={variant.sku} className="flex items-center gap-4 mt-2">
                <span className="text-gray-600">SKU: {variant.sku}</span>
                <span className="text-gray-600">Stock:</span>
                <input
                  type="number"
                  className="border p-2 rounded w-24"
                  value={variant.stock}
                  min="0"
                  onChange={e => handleStockUpdate(product._id, idx, Number(e.target.value))}
                />
                <span className="text-gray-600">Price: ${variant.price}</span>
              </div>
            ))}
          </div>
        ))}
      </div>
    </main>
  );
}

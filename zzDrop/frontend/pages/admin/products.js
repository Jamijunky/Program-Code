import { useEffect, useState } from 'react';
import axios from 'axios';
import { useRouter } from 'next/router';

export default function AdminProducts() {
  const router = useRouter();
  const [products, setProducts] = useState([]);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState('');
  const professionOptions = [
    'doctor', 'engineer', 'lawyer', 'politician', 'developer', 'teacher', 'artist', 'accountant', 'nurse', 'architect', 'other'
  ];
  const [form, setForm] = useState({ name: '', description: '', price: '', stock: '', image: '', professions: [], featured: false, popularity: 0 });
  const [success, setSuccess] = useState('');

  useEffect(() => {
    const token = localStorage.getItem('token');
    if (!token) return router.push('/login');
    axios.get(`${process.env.NEXT_PUBLIC_API_URL}/products`, {
      headers: { Authorization: `Bearer ${token}` }
    })
      .then(res => { setProducts(res.data); setLoading(false); })
      .catch(() => setLoading(false));
  }, [router]);

  async function handleCreate(e) {
    e.preventDefault();
    setError(''); setSuccess('');
    const token = localStorage.getItem('token');
    try {
      await axios.post(`${process.env.NEXT_PUBLIC_API_URL}/products`, {
        ...form, variants: [{ sku: Date.now().toString(), price: Number(form.price) }]
      }, { headers: { Authorization: `Bearer ${token}` } });
      setSuccess('Product created');
      setForm({ name: '', description: '', price: '', stock: '', image: '', professions: [] });
      // Refresh products
      const res = await axios.get(`${process.env.NEXT_PUBLIC_API_URL}/products`, {
        headers: { Authorization: `Bearer ${token}` }
      });
      setProducts(res.data);
    } catch (err) {
      setError('Failed to create product');
    }
  }

  function handleChange(e) {
    setForm(f => ({ ...f, [e.target.name]: e.target.value }));
  }

  async function handleDelete(id) {
    const token = localStorage.getItem('token');
    await axios.delete(`${process.env.NEXT_PUBLIC_API_URL}/products/${id}`, {
      headers: { Authorization: `Bearer ${token}` }
    });
    setProducts(products.filter(p => p._id !== id));
  }

  if (loading) return <p>Loading...</p>;

  return (
    <main className="max-w-5xl mx-auto px-4 py-8">
      <h1 className="text-3xl font-bold mb-6">Manage Products</h1>
      <form onSubmit={handleCreate} className="bg-white p-6 rounded shadow mb-8 flex flex-col md:flex-row gap-4">
        <input
          type="text"
          name="name"
          value={form.name}
          onChange={handleChange}
          className="border p-2 rounded w-full"
          required
        />
        <label className="block mt-2 font-medium">Professions</label>
        <select
          name="professions"
          multiple
          value={form.professions}
          onChange={e => {
            const options = Array.from(e.target.selectedOptions).map(o => o.value);
            setForm(f => ({ ...f, professions: options }));
          }}
          className="border p-2 rounded w-full h-32"
        >
          {professionOptions.map(opt => (
            <option key={opt} value={opt}>{opt.charAt(0).toUpperCase() + opt.slice(1)}</option>
          ))}
        </select>
        <input type="text" name="description" value={form.description} onChange={handleChange} className="border p-2 rounded flex-1" required />
        <input type="number" name="price" value={form.price} onChange={handleChange} className="border p-2 rounded w-32" required />
        <label className="block mt-2 font-medium">Featured</label>
        <input type="checkbox" name="featured" checked={form.featured} onChange={e => setForm(f => ({ ...f, featured: e.target.checked }))} />
        <label className="block mt-2 font-medium">Popularity</label>
        <input type="number" name="popularity" value={form.popularity} onChange={e => setForm(f => ({ ...f, popularity: Number(e.target.value) }))} className="border p-2 rounded w-32" min="0" />
        <button type="submit" className="bg-blue-600 text-white px-4 py-2 rounded hover:bg-blue-700">Add Product</button>
      </form>
      {success && <p className="text-green-600 mb-4">{success}</p>}
      {error && <p className="text-red-500 mb-4">{error}</p>}
      <div className="grid grid-cols-1 md:grid-cols-2 gap-6">
        {products.map(product => (
          <div key={product._id} className="border rounded-lg p-4 bg-white flex flex-col gap-2">
            <h2 className="font-semibold text-lg">{product.name}</h2>
            <p className="text-gray-600">{product.description}</p>
            <p className="font-bold text-blue-600">${product.variants?.[0]?.price || 'N/A'}</p>
            <button onClick={() => handleDelete(product._id)} className="text-red-600 hover:underline self-end">Delete</button>
          </div>
        ))}
      </div>
    </main>
  );
}

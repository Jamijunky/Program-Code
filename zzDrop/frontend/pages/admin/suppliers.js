import { useEffect, useState } from 'react';
import axios from 'axios';
import { useRouter } from 'next/router';

export default function AdminSuppliers() {
  const router = useRouter();
  const [suppliers, setSuppliers] = useState([]);
  const [loading, setLoading] = useState(true);
  const [name, setName] = useState('');
  const [apiType, setApiType] = useState('AliExpress');
  const [success, setSuccess] = useState('');
  const [error, setError] = useState('');

  useEffect(() => {
    const token = localStorage.getItem('token');
    if (!token) return router.push('/login');
    axios.get(`${process.env.NEXT_PUBLIC_API_URL}/suppliers`, {
      headers: { Authorization: `Bearer ${token}` }
    })
      .then(res => { setSuppliers(res.data); setLoading(false); })
      .catch(() => setLoading(false));
  }, [router]);

  async function handleCreate(e) {
    e.preventDefault();
    setError(''); setSuccess('');
    const token = localStorage.getItem('token');
    try {
      await axios.post(`${process.env.NEXT_PUBLIC_API_URL}/suppliers`, { name, apiType }, {
        headers: { Authorization: `Bearer ${token}` }
      });
      setSuccess('Supplier created');
      setName(''); setApiType('AliExpress');
      // Refresh suppliers
      const res = await axios.get(`${process.env.NEXT_PUBLIC_API_URL}/suppliers`, {
        headers: { Authorization: `Bearer ${token}` }
      });
      setSuppliers(res.data);
    } catch (err) {
      setError('Failed to create supplier');
    }
  }

  async function handleDelete(id) {
    const token = localStorage.getItem('token');
    await axios.delete(`${process.env.NEXT_PUBLIC_API_URL}/suppliers/${id}`, {
      headers: { Authorization: `Bearer ${token}` }
    });
    setSuppliers(suppliers.filter(s => s._id !== id));
  }

  if (loading) return <p>Loading...</p>;

  return (
    <main className="max-w-4xl mx-auto px-4 py-8">
      <h1 className="text-3xl font-bold mb-6">Supplier Management</h1>
      <form onSubmit={handleCreate} className="bg-white p-6 rounded shadow mb-8 flex flex-col md:flex-row gap-4">
        <input type="text" placeholder="Name" className="border p-2 rounded flex-1" value={name} onChange={e => setName(e.target.value)} required />
        <select className="border p-2 rounded flex-1" value={apiType} onChange={e => setApiType(e.target.value)}>
          <option value="AliExpress">AliExpress</option>
          <option value="Spocket">Spocket</option>
          <option value="Zendrop">Zendrop</option>
          <option value="Oberlo">Oberlo</option>
          <option value="Custom">Custom</option>
        </select>
        <button type="submit" className="bg-blue-600 text-white px-4 py-2 rounded hover:bg-blue-700">Add Supplier</button>
      </form>
      {success && <p className="text-green-600 mb-4">{success}</p>}
      {error && <p className="text-red-500 mb-4">{error}</p>}
      <div className="grid grid-cols-1 gap-6">
        {suppliers.map(supplier => (
          <div key={supplier._id} className="border rounded-lg p-4 bg-white flex flex-col gap-2">
            <h2 className="font-semibold text-lg">{supplier.name}</h2>
            <p className="text-gray-600">API Type: {supplier.apiType}</p>
            <button onClick={() => handleDelete(supplier._id)} className="text-red-600 hover:underline self-end">Delete</button>
          </div>
        ))}
      </div>
    </main>
  );
}

import { useEffect, useState } from 'react';
import axios from 'axios';
import { useRouter } from 'next/router';

export default function AdminCoupons() {
  const router = useRouter();
  const [coupons, setCoupons] = useState([]);
  const [loading, setLoading] = useState(true);
  const [form, setForm] = useState({ code: '', discountType: 'percent', discountValue: '', minOrder: '', expiresAt: '', usageLimit: '', active: true });
  const [editing, setEditing] = useState(null);
  const [error, setError] = useState('');
  const [success, setSuccess] = useState('');

  useEffect(() => {
    fetchCoupons();
    // eslint-disable-next-line
  }, []);

  async function fetchCoupons() {
    const token = localStorage.getItem('token');
    if (!token) return router.push('/login');
    const res = await axios.get(`${process.env.NEXT_PUBLIC_API_URL}/coupons`, {
      headers: { Authorization: `Bearer ${token}` }
    });
    setCoupons(res.data);
    setLoading(false);
  }

  function handleEdit(coupon) {
    setEditing(coupon._id);
    setForm({
      code: coupon.code,
      discountType: coupon.discountType,
      discountValue: coupon.discountValue,
      minOrder: coupon.minOrder,
      expiresAt: coupon.expiresAt ? coupon.expiresAt.slice(0, 10) : '',
      usageLimit: coupon.usageLimit || '',
      active: coupon.active
    });
  }

  function handleCancel() {
    setEditing(null);
    setForm({ code: '', discountType: 'percent', discountValue: '', minOrder: '', expiresAt: '', usageLimit: '', active: true });
    setError(''); setSuccess('');
  }

  async function handleSubmit(e) {
    e.preventDefault();
    setError(''); setSuccess('');
    const token = localStorage.getItem('token');
    try {
      if (editing) {
        await axios.put(`${process.env.NEXT_PUBLIC_API_URL}/coupons/${editing}`, form, {
          headers: { Authorization: `Bearer ${token}` }
        });
        setSuccess('Coupon updated');
      } else {
        await axios.post(`${process.env.NEXT_PUBLIC_API_URL}/coupons`, form, {
          headers: { Authorization: `Bearer ${token}` }
        });
        setSuccess('Coupon created');
      }
      handleCancel();
      fetchCoupons();
    } catch {
      setError('Failed to save coupon');
    }
  }

  async function handleDelete(id) {
    const token = localStorage.getItem('token');
    await axios.delete(`${process.env.NEXT_PUBLIC_API_URL}/coupons/${id}`, {
      headers: { Authorization: `Bearer ${token}` }
    });
    fetchCoupons();
  }

  if (loading) return <p>Loading...</p>;

  return (
    <main className="max-w-4xl mx-auto px-4 py-8">
      <h1 className="text-3xl font-bold mb-6">Coupon Management</h1>
      <form onSubmit={handleSubmit} className="bg-white p-6 rounded shadow mb-8 flex flex-col gap-4">
        <input type="text" placeholder="Code" className="border p-2 rounded" value={form.code} onChange={e => setForm({ ...form, code: e.target.value.toUpperCase() })} required disabled={!!editing} />
        <div className="flex gap-4">
          <select className="border p-2 rounded flex-1" value={form.discountType} onChange={e => setForm({ ...form, discountType: e.target.value })}>
            <option value="percent">Percent</option>
            <option value="fixed">Fixed</option>
          </select>
          <input type="number" placeholder="Discount Value" className="border p-2 rounded flex-1" value={form.discountValue} onChange={e => setForm({ ...form, discountValue: e.target.value })} required />
        </div>
        <input type="number" placeholder="Minimum Order" className="border p-2 rounded" value={form.minOrder} onChange={e => setForm({ ...form, minOrder: e.target.value })} />
        <input type="date" className="border p-2 rounded" value={form.expiresAt} onChange={e => setForm({ ...form, expiresAt: e.target.value })} />
        <input type="number" placeholder="Usage Limit" className="border p-2 rounded" value={form.usageLimit} onChange={e => setForm({ ...form, usageLimit: e.target.value })} />
        <label className="flex items-center gap-2">
          <input type="checkbox" checked={form.active} onChange={e => setForm({ ...form, active: e.target.checked })} /> Active
        </label>
        <div className="flex gap-2">
          <button type="submit" className="bg-blue-600 text-white px-4 py-2 rounded hover:bg-blue-700">{editing ? 'Update' : 'Create'} Coupon</button>
          {editing && <button type="button" onClick={handleCancel} className="bg-gray-300 px-4 py-2 rounded">Cancel</button>}
        </div>
        {success && <p className="text-green-600">{success}</p>}
        {error && <p className="text-red-500">{error}</p>}
      </form>
      <div className="grid grid-cols-1 gap-6">
        {coupons.map(coupon => (
          <div key={coupon._id} className="border rounded-lg p-4 bg-white flex flex-col gap-2">
            <div className="flex justify-between">
              <span className="font-semibold">{coupon.code}</span>
              <span className="text-gray-500">{coupon.discountType === 'percent' ? `${coupon.discountValue}%` : `$${coupon.discountValue}`}</span>
            </div>
            <div className="text-gray-600">Min Order: {coupon.minOrder || 0} | Expires: {coupon.expiresAt ? coupon.expiresAt.slice(0,10) : 'N/A'}</div>
            <div className="text-gray-600">Usage: {coupon.usedCount || 0}/{coupon.usageLimit || '∞'} | Active: {coupon.active ? 'Yes' : 'No'}</div>
            <div className="flex gap-2 mt-2">
              <button onClick={() => handleEdit(coupon)} className="text-blue-600 hover:underline">Edit</button>
              <button onClick={() => handleDelete(coupon._id)} className="text-red-600 hover:underline">Delete</button>
            </div>
          </div>
        ))}
      </div>
    </main>
  );
}

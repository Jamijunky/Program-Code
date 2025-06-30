import { useEffect, useState } from 'react';
import axios from 'axios';
import { useRouter } from 'next/router';

export default function AdminOrders() {
  const router = useRouter();
  const [orders, setOrders] = useState([]);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState('');

  useEffect(() => {
    const token = localStorage.getItem('token');
    if (!token) return router.push('/login');
    axios.get(`${process.env.NEXT_PUBLIC_API_URL}/orders`, {
      headers: { Authorization: `Bearer ${token}` }
    })
      .then(res => { setOrders(res.data); setLoading(false); })
      .catch(() => setLoading(false));
  }, [router]);

  async function handleStatus(id, status) {
    const token = localStorage.getItem('token');
    await axios.put(`${process.env.NEXT_PUBLIC_API_URL}/orders/${id}`, { status }, {
      headers: { Authorization: `Bearer ${token}` }
    });
    setOrders(orders.map(o => o._id === id ? { ...o, status } : o));
  }

  if (loading) return <p>Loading...</p>;

  return (
    <main className="max-w-5xl mx-auto px-4 py-8">
      <h1 className="text-3xl font-bold mb-6">Manage Orders</h1>
      <div className="grid grid-cols-1 gap-6">
        {orders.map(order => (
          <div key={order._id} className="border rounded-lg p-4 bg-white flex flex-col gap-2">
            <div className="flex justify-between">
              <span className="font-semibold">Order #{order._id}</span>
              <span className="text-blue-600 font-bold">${order.total}</span>
            </div>
            <div>Status: <span className="font-bold">{order.status}</span></div>
            <div>Placed: {new Date(order.createdAt).toLocaleString()}</div>
            <div className="flex gap-2 mt-2">
              {['pending', 'processing', 'shipped', 'delivered', 'cancelled'].map(s => (
                <button
                  key={s}
                  onClick={() => handleStatus(order._id, s)}
                  className={`px-2 py-1 rounded ${order.status === s ? 'bg-blue-600 text-white' : 'bg-gray-200'}`}
                >{s}</button>
              ))}
            </div>
          </div>
        ))}
      </div>
    </main>
  );
}

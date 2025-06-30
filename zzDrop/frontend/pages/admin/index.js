import { useEffect, useState } from 'react';
import axios from 'axios';
import Link from 'next/link';
import { useRouter } from 'next/router';
import { getSocket } from '../../utils/socket';

export default function AdminDashboard() {
  const router = useRouter();
  const [stats, setStats] = useState({ sales: 0, orders: 0, revenue: 0, abandonedCarts: 0 });
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);
  const [newOrderAlert, setNewOrderAlert] = useState(null);

  useEffect(() => {
    const token = localStorage.getItem('token');
    if (!token) return router.push('/login');
    axios.get(`${process.env.NEXT_PUBLIC_API_URL}/admin/stats`, {
      headers: { Authorization: `Bearer ${token}` }
    })
      .then(res => { setStats(res.data); setLoading(false); })
      .catch(err => { setError('Access denied'); setLoading(false); });

    // Real-time new order notifications
    const socket = getSocket();
    socket.emit('joinAdmin');
    socket.on('newOrder', (data) => {
      setNewOrderAlert(`New order received! Order ID: ${data.orderId}`);
      setTimeout(() => setNewOrderAlert(null), 7000);
    });
    return () => {
      socket.off('newOrder');
    };
  }, [router]);

  if (loading) return <p>Loading...</p>;
  if (error) return <p className="text-red-500">{error}</p>;

  return (
    <main className="max-w-5xl mx-auto px-4 py-8">
      <h1 className="text-3xl font-bold mb-6">Admin Dashboard</h1>
      {newOrderAlert && (
        <div className="bg-green-100 border border-green-400 text-green-700 px-4 py-2 rounded mb-4">
          {newOrderAlert}
        </div>
      )}
      <div className="grid grid-cols-2 md:grid-cols-4 gap-6 mb-8">
        <div className="bg-white p-6 rounded shadow text-center">
          <div className="text-2xl font-bold">{stats.sales}</div>
          <div className="text-gray-600">Sales</div>
        </div>
        <div className="bg-white p-6 rounded shadow text-center">
          <div className="text-2xl font-bold">{stats.orders}</div>
          <div className="text-gray-600">Orders</div>
        </div>
        <div className="bg-white p-6 rounded shadow text-center">
          <div className="text-2xl font-bold">{stats.revenue}</div>
          <div className="text-gray-600">Revenue</div>
        </div>
        <div className="bg-white p-6 rounded shadow text-center">
          <div className="text-2xl font-bold">{stats.abandonedCarts}</div>
          <div className="text-gray-600">Abandoned Carts</div>
        </div>
      </div>
      <div className="grid grid-cols-1 md:grid-cols-2 gap-6">
        <Link href="/admin/products">
          <div className="bg-blue-100 p-6 rounded shadow hover:bg-blue-200 cursor-pointer text-center font-semibold">Manage Products</div>
        </Link>
        <Link href="/admin/orders">
          <div className="bg-green-100 p-6 rounded shadow hover:bg-green-200 cursor-pointer text-center font-semibold">Manage Orders</div>
        </Link>
        <Link href="/admin/users">
          <div className="bg-yellow-100 p-6 rounded shadow hover:bg-yellow-200 cursor-pointer text-center font-semibold">Manage Users</div>
        </Link>
        <Link href="/admin/reviews">
          <div className="bg-purple-100 p-6 rounded shadow hover:bg-purple-200 cursor-pointer text-center font-semibold">Manage Reviews</div>
        </Link>
      </div>
    </main>
  );
}

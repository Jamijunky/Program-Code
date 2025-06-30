import { useEffect, useState } from 'react';
import axios from 'axios';
import Link from 'next/link';
import { useRouter } from 'next/router';

export default function Orders() {
  const router = useRouter();
  const [orders, setOrders] = useState([]);
  const [loading, setLoading] = useState(true);

  useEffect(() => {
    const token = localStorage.getItem('token');
    if (!token) return router.push('/login');
    axios.get(`${process.env.NEXT_PUBLIC_API_URL}/orders/me`, {
      headers: { Authorization: `Bearer ${token}` }
    })
      .then(res => { setOrders(res.data); setLoading(false); })
      .catch(() => setLoading(false));
  }, [router]);

  if (loading) return <p>Loading...</p>;
  if (!orders.length) return <p>No orders found.</p>;

  return (
    <main className="max-w-3xl mx-auto px-4 py-8">
      <h1 className="text-3xl font-bold mb-6">My Orders</h1>
      <div className="space-y-4">
        {orders.map(order => (
          <Link key={order._id} href={`/order/${order._id}`}>
            <div className="border p-4 rounded hover:shadow cursor-pointer">
              <div className="flex justify-between mb-2">
                <span className="font-semibold">Order #{order._id}</span>
                <span className="text-blue-600 font-bold">${order.total}</span>
              </div>
              <div className="text-gray-600">Status: {order.status}</div>
              <div className="text-gray-500 text-sm">Placed: {new Date(order.createdAt).toLocaleString()}</div>
            </div>
          </Link>
        ))}
      </div>
    </main>
  );
}

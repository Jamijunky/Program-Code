import { useRouter } from 'next/router';
import { useEffect, useState } from 'react';
import axios from 'axios';

export default function OrderPage() {
  const router = useRouter();
  const { id } = router.query;
  const [order, setOrder] = useState(null);
  const [loading, setLoading] = useState(true);

  useEffect(() => {
    if (!id) return;
    const token = localStorage.getItem('token');
    if (!token) return router.push('/login');
    axios.get(`${process.env.NEXT_PUBLIC_API_URL}/orders/${id}`, {
      headers: { Authorization: `Bearer ${token}` }
    })
      .then(res => { setOrder(res.data); setLoading(false); })
      .catch(() => setLoading(false));
  }, [id, router]);

  if (loading) return <p>Loading...</p>;
  if (!order) return <p>Order not found.</p>;

  return (
    <main className="max-w-2xl mx-auto px-4 py-8">
      <h1 className="text-3xl font-bold mb-6">Order Confirmation</h1>
      <div className="bg-white p-6 rounded shadow mb-4">
        <h2 className="text-xl font-semibold mb-2">Order #{order._id}</h2>
        <p>Status: <span className="font-bold">{order.status}</span></p>
        <p>Total: <span className="font-bold text-blue-600">${order.total}</span></p>
        <p>Placed: {new Date(order.createdAt).toLocaleString()}</p>
        <h3 className="mt-4 font-semibold">Shipping Address</h3>
        <div className="text-gray-700 mb-2">
          {order.shippingAddress?.street}, {order.shippingAddress?.city}, {order.shippingAddress?.state}, {order.shippingAddress?.zip}, {order.shippingAddress?.country}
        </div>
        <h3 className="mt-4 font-semibold">Items</h3>
        <ul className="divide-y">
          {order.items.map(item => (
            <li key={item.product + item.variantId} className="py-2 flex justify-between">
              <span>{item.product}</span>
              <span>Variant: {item.variantId}</span>
              <span>Qty: {item.quantity}</span>
              <span>${item.price}</span>
            </li>
          ))}
        </ul>
      </div>
      <a href="/shop" className="text-blue-600 hover:underline">Back to Shop</a>
    </main>
  );
}

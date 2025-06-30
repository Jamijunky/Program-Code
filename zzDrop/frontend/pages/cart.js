import { useEffect, useState } from 'react';
import axios from 'axios';
import Link from 'next/link';
import { useRouter } from 'next/router';

export default function Cart() {
  const router = useRouter();
  const [cart, setCart] = useState(null);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState('');

  useEffect(() => {
    const token = localStorage.getItem('token');
    if (!token) return router.push('/login');
    axios.get(`${process.env.NEXT_PUBLIC_API_URL}/carts/me`, {
      headers: { Authorization: `Bearer ${token}` }
    })
      .then(res => { setCart(res.data); setLoading(false); })
      .catch(() => setLoading(false));
  }, [router]);

  async function handleRemove(product, variantId) {
    const token = localStorage.getItem('token');
    await axios.delete(`${process.env.NEXT_PUBLIC_API_URL}/carts/me/item`, {
      headers: { Authorization: `Bearer ${token}` },
      data: { product, variantId }
    });
    setCart({ ...cart, items: cart.items.filter(i => !(i.product._id === product && i.variantId === variantId)) });
  }

  if (loading) return <p>Loading...</p>;
  if (!cart || !cart.items.length) return <p>Your cart is empty.</p>;

  return (
    <main className="max-w-3xl mx-auto px-4 py-8">
      <h1 className="text-3xl font-bold mb-6">Your Cart</h1>
      <div className="space-y-4 mb-8">
        {cart.items.map(item => (
          <div key={item.product._id + item.variantId} className="flex items-center gap-4 border-b pb-4">
            <img src={item.product.images?.[0] || '/placeholder.png'} alt={item.product.name} className="w-24 h-24 object-cover rounded" />
            <div className="flex-1">
              <h2 className="font-semibold text-lg">{item.product.name}</h2>
              <p className="text-gray-600">Variant: {item.variantId}</p>
              <p className="text-gray-600">Quantity: {item.quantity}</p>
              <p className="font-bold text-blue-600">${item.product.variants?.find(v => v.sku === item.variantId)?.price || 'N/A'}</p>
            </div>
            <button onClick={() => handleRemove(item.product._id, item.variantId)} className="text-red-600 hover:underline">Remove</button>
          </div>
        ))}
      </div>
      <div className="flex justify-between items-center">
        <Link href="/checkout">
          <button className="bg-green-600 text-white px-6 py-2 rounded hover:bg-green-700">Proceed to Checkout</button>
        </Link>
      </div>
    </main>
  );
}

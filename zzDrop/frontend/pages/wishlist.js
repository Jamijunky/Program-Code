import { useEffect, useState } from 'react';
import axios from 'axios';
import Link from 'next/link';
import { useRouter } from 'next/router';

export default function Wishlist() {
  const router = useRouter();
  const [wishlist, setWishlist] = useState([]);
  const [loading, setLoading] = useState(true);

  useEffect(() => {
    const token = localStorage.getItem('token');
    if (!token) return router.push('/login');
    axios.get(`${process.env.NEXT_PUBLIC_API_URL}/users/me`, {
      headers: { Authorization: `Bearer ${token}` }
    })
      .then(res => { setWishlist(res.data.wishlist || []); setLoading(false); })
      .catch(() => setLoading(false));
  }, [router]);

  if (loading) return <p>Loading...</p>;
  if (!wishlist.length) return <p>Your wishlist is empty.</p>;

  return (
    <main className="max-w-3xl mx-auto px-4 py-8">
      <h1 className="text-3xl font-bold mb-6">My Wishlist</h1>
      <div className="grid grid-cols-2 md:grid-cols-3 gap-6">
        {wishlist.map(productId => (
          <Link key={productId} href={`/product/${productId}`}>
            <div className="border rounded-lg p-4 bg-white hover:shadow-lg transition cursor-pointer">
              <p>Product ID: {productId}</p>
              {/* For full product info, fetch details by ID */}
            </div>
          </Link>
        ))}
      </div>
    </main>
  );
}

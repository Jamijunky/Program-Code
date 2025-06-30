import { useEffect, useState } from 'react';
import axios from 'axios';
import { useRouter } from 'next/router';

export default function AdminReviews() {
  const router = useRouter();
  const [reviews, setReviews] = useState([]);
  const [loading, setLoading] = useState(true);

  useEffect(() => {
    const token = localStorage.getItem('token');
    if (!token) return router.push('/login');
    axios.get(`${process.env.NEXT_PUBLIC_API_URL}/reviews`, {
      headers: { Authorization: `Bearer ${token}` }
    })
      .then(res => { setReviews(res.data); setLoading(false); })
      .catch(() => setLoading(false));
  }, [router]);

  async function handleDelete(id) {
    const token = localStorage.getItem('token');
    await axios.delete(`${process.env.NEXT_PUBLIC_API_URL}/reviews/${id}`, {
      headers: { Authorization: `Bearer ${token}` }
    });
    setReviews(reviews.filter(r => r._id !== id));
  }

  if (loading) return <p>Loading...</p>;

  return (
    <main className="max-w-5xl mx-auto px-4 py-8">
      <h1 className="text-3xl font-bold mb-6">Manage Reviews</h1>
      <div className="grid grid-cols-1 gap-6">
        {reviews.map(review => (
          <div key={review._id} className="border rounded-lg p-4 bg-white flex flex-col gap-2">
            <div className="flex justify-between">
              <span className="font-semibold">{review.user?.name || review.user}</span>
              <span className="text-yellow-500">{'★'.repeat(review.rating)}{'☆'.repeat(5 - review.rating)}</span>
            </div>
            <div>Product: {review.product}</div>
            <div className="text-gray-700">{review.comment}</div>
            <button onClick={() => handleDelete(review._id)} className="text-red-600 hover:underline self-end">Delete</button>
          </div>
        ))}
      </div>
    </main>
  );
}

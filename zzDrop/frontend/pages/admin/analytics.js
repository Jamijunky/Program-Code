import { useEffect, useState } from 'react';
import axios from 'axios';
import { useRouter } from 'next/router';

export default function AdminAnalytics() {
  const router = useRouter();
  const [analytics, setAnalytics] = useState(null);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState('');

  useEffect(() => {
    const token = localStorage.getItem('token');
    if (!token) return router.push('/login');
    axios.get(`${process.env.NEXT_PUBLIC_API_URL}/admin/analytics`, {
      headers: { Authorization: `Bearer ${token}` }
    })
      .then(res => { setAnalytics(res.data); setLoading(false); })
      .catch(() => { setError('Access denied'); setLoading(false); });
  }, [router]);

  if (loading) return <p>Loading...</p>;
  if (error) return <p className="text-red-500">{error}</p>;

  return (
    <main className="max-w-5xl mx-auto px-4 py-8">
      <h1 className="text-3xl font-bold mb-6">Analytics Dashboard</h1>
      <div className="grid grid-cols-1 md:grid-cols-2 gap-6 mb-8">
        <div className="bg-white p-6 rounded shadow">
          <h2 className="font-semibold mb-2">Top Products</h2>
          <ul>
            {analytics.topProducts.map(p => (
              <li key={p._id}>{p.name} - {p.sales} sales</li>
            ))}
          </ul>
        </div>
        <div className="bg-white p-6 rounded shadow">
          <h2 className="font-semibold mb-2">Conversion Rate</h2>
          <div className="text-2xl font-bold">{analytics.conversionRate}%</div>
        </div>
        <div className="bg-white p-6 rounded shadow">
          <h2 className="font-semibold mb-2">Total Revenue</h2>
          <div className="text-2xl font-bold">${analytics.revenue}</div>
        </div>
        <div className="bg-white p-6 rounded shadow">
          <h2 className="font-semibold mb-2">Traffic (stub)</h2>
          <div className="text-2xl font-bold">{analytics.traffic || 'N/A'}</div>
        </div>
      </div>
    </main>
  );
}

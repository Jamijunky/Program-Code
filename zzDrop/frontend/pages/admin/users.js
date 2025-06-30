import { useEffect, useState } from 'react';
import axios from 'axios';
import { useRouter } from 'next/router';

export default function AdminUsers() {
  const router = useRouter();
  const [users, setUsers] = useState([]);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState('');

  useEffect(() => {
    const token = localStorage.getItem('token');
    if (!token) return router.push('/login');
    axios.get(`${process.env.NEXT_PUBLIC_API_URL}/users`, {
      headers: { Authorization: `Bearer ${token}` }
    })
      .then(res => { setUsers(res.data); setLoading(false); })
      .catch(() => setLoading(false));
  }, [router]);

  async function handleDelete(id) {
    const token = localStorage.getItem('token');
    await axios.delete(`${process.env.NEXT_PUBLIC_API_URL}/users/${id}`, {
      headers: { Authorization: `Bearer ${token}` }
    });
    setUsers(users.filter(u => u._id !== id));
  }

  if (loading) return <p>Loading...</p>;

  return (
    <main className="max-w-5xl mx-auto px-4 py-8">
      <h1 className="text-3xl font-bold mb-6">Manage Users</h1>
      <div className="grid grid-cols-1 md:grid-cols-2 gap-6">
        {users.map(user => (
          <div key={user._id} className="border rounded-lg p-4 bg-white flex flex-col gap-2">
            <h2 className="font-semibold text-lg">{user.name}</h2>
            <p className="text-gray-600">{user.email}</p>
            <p className="text-gray-600">Role: {user.role}</p>
            <button onClick={() => handleDelete(user._id)} className="text-red-600 hover:underline self-end">Delete</button>
          </div>
        ))}
      </div>
    </main>
  );
}

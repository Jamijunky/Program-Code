import { useEffect, useState } from 'react';
import axios from 'axios';
import { useRouter } from 'next/router';

export default function Profile() {
  const router = useRouter();
  const [user, setUser] = useState(null);
  const [name, setName] = useState('');
  const [avatar, setAvatar] = useState('');
  const [addresses, setAddresses] = useState([]);
  const [error, setError] = useState('');
  const [success, setSuccess] = useState('');

  useEffect(() => {
    const token = localStorage.getItem('token');
    if (!token) return router.push('/login');
    axios.get(`${process.env.NEXT_PUBLIC_API_URL}/users/me`, {
      headers: { Authorization: `Bearer ${token}` }
    }).then(res => {
      setUser(res.data);
      setName(res.data.name);
      setAvatar(res.data.avatar || '');
      setAddresses(res.data.addresses || []);
    }).catch(() => router.push('/login'));
  }, [router]);

  async function handleUpdate(e) {
    e.preventDefault();
    setError(''); setSuccess('');
    const token = localStorage.getItem('token');
    try {
      const res = await axios.put(`${process.env.NEXT_PUBLIC_API_URL}/users/me`, { name, avatar, addresses }, {
        headers: { Authorization: `Bearer ${token}` }
      });
      setSuccess('Profile updated');
      setUser(res.data);
    } catch (err) {
      setError(err.response?.data?.message || 'Update failed');
    }
  }

  if (!user) return null;

  return (
    <main className="min-h-screen flex items-center justify-center bg-gray-50">
      <form onSubmit={handleUpdate} className="bg-white p-8 rounded shadow-md w-full max-w-md">
        <h1 className="text-2xl font-bold mb-6">My Profile</h1>
        {error && <p className="text-red-500 mb-4">{error}</p>}
        {success && <p className="text-green-600 mb-4">{success}</p>}
        <input
          type="text"
          placeholder="Name"
          className="w-full mb-4 p-2 border rounded"
          value={name}
          onChange={e => setName(e.target.value)}
        />
        <input
          type="text"
          placeholder="Avatar URL"
          className="w-full mb-4 p-2 border rounded"
          value={avatar}
          onChange={e => setAvatar(e.target.value)}
        />
        {/* Addresses editing can be expanded here */}
        <button type="submit" className="w-full bg-blue-600 text-white py-2 rounded hover:bg-blue-700">Update Profile</button>
      </form>
    </main>
  );
}

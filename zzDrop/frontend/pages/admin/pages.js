import { useEffect, useState } from 'react';
import axios from 'axios';
import { useRouter } from 'next/router';

export default function AdminPages() {
  const router = useRouter();
  const [pages, setPages] = useState([]);
  const [loading, setLoading] = useState(true);
  const [editing, setEditing] = useState(null);
  const [form, setForm] = useState({ slug: '', title: '', content: '', published: true });
  const [error, setError] = useState('');
  const [success, setSuccess] = useState('');

  useEffect(() => {
    fetchPages();
    // eslint-disable-next-line
  }, []);

  async function fetchPages() {
    const token = localStorage.getItem('token');
    if (!token) return router.push('/login');
    const res = await axios.get(`${process.env.NEXT_PUBLIC_API_URL}/pages`, {
      headers: { Authorization: `Bearer ${token}` }
    });
    setPages(res.data);
    setLoading(false);
  }

  function handleEdit(page) {
    setEditing(page._id);
    setForm({ slug: page.slug, title: page.title, content: page.content, published: page.published });
  }

  function handleCancel() {
    setEditing(null);
    setForm({ slug: '', title: '', content: '', published: true });
    setError(''); setSuccess('');
  }

  async function handleSubmit(e) {
    e.preventDefault();
    setError(''); setSuccess('');
    const token = localStorage.getItem('token');
    try {
      if (editing) {
        await axios.put(`${process.env.NEXT_PUBLIC_API_URL}/pages/${editing}`, form, {
          headers: { Authorization: `Bearer ${token}` }
        });
        setSuccess('Page updated');
      } else {
        await axios.post(`${process.env.NEXT_PUBLIC_API_URL}/pages`, form, {
          headers: { Authorization: `Bearer ${token}` }
        });
        setSuccess('Page created');
      }
      setForm({ slug: '', title: '', content: '', published: true });
      setEditing(null);
      fetchPages();
    } catch {
      setError('Failed to save page');
    }
  }

  async function handleDelete(id) {
    const token = localStorage.getItem('token');
    await axios.delete(`${process.env.NEXT_PUBLIC_API_URL}/pages/${id}`, {
      headers: { Authorization: `Bearer ${token}` }
    });
    fetchPages();
  }

  if (loading) return <p>Loading...</p>;

  return (
    <main className="max-w-4xl mx-auto px-4 py-8">
      <h1 className="text-3xl font-bold mb-6">CMS Page Management</h1>
      <form onSubmit={handleSubmit} className="bg-white p-6 rounded shadow mb-8 flex flex-col gap-4">
        <input type="text" placeholder="Slug (e.g. terms)" className="border p-2 rounded" value={form.slug} onChange={e => setForm({ ...form, slug: e.target.value })} required disabled={!!editing} />
        <input type="text" placeholder="Title" className="border p-2 rounded" value={form.title} onChange={e => setForm({ ...form, title: e.target.value })} required />
        <textarea placeholder="Content" className="border p-2 rounded h-32" value={form.content} onChange={e => setForm({ ...form, content: e.target.value })} required />
        <label className="flex items-center gap-2">
          <input type="checkbox" checked={form.published} onChange={e => setForm({ ...form, published: e.target.checked })} /> Published
        </label>
        <div className="flex gap-2">
          <button type="submit" className="bg-blue-600 text-white px-4 py-2 rounded hover:bg-blue-700">{editing ? 'Update' : 'Create'} Page</button>
          {editing && <button type="button" onClick={handleCancel} className="bg-gray-300 px-4 py-2 rounded">Cancel</button>}
        </div>
        {success && <p className="text-green-600">{success}</p>}
        {error && <p className="text-red-500">{error}</p>}
      </form>
      <div className="grid grid-cols-1 gap-6">
        {pages.map(page => (
          <div key={page._id} className="border rounded-lg p-4 bg-white flex flex-col gap-2">
            <div className="flex justify-between">
              <span className="font-semibold">{page.title}</span>
              <span className="text-gray-500">/{page.slug}</span>
            </div>
            <div className="text-gray-600 truncate">{page.content.slice(0, 80)}...</div>
            <div className="flex gap-2 mt-2">
              <button onClick={() => handleEdit(page)} className="text-blue-600 hover:underline">Edit</button>
              <button onClick={() => handleDelete(page._id)} className="text-red-600 hover:underline">Delete</button>
            </div>
          </div>
        ))}
      </div>
    </main>
  );
}

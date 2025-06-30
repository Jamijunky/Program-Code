import { useRouter } from 'next/router';
import { useEffect, useState } from 'react';
import axios from 'axios';

export default function ProductPage() {
  const router = useRouter();
  const { id } = router.query;
  const [product, setProduct] = useState(null);
  const [variantIdx, setVariantIdx] = useState(0);
  const [quantity, setQuantity] = useState(1);
  const [reviews, setReviews] = useState([]);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState('');
  const [success, setSuccess] = useState('');

  useEffect(() => {
    if (!id) return;
    setLoading(true);
    axios.get(`${process.env.NEXT_PUBLIC_API_URL}/products/${id}`)
      .then(res => { setProduct(res.data); setLoading(false); })
      .catch(() => setLoading(false));
    axios.get(`${process.env.NEXT_PUBLIC_API_URL}/reviews/product/${id}`)
      .then(res => setReviews(res.data));
  }, [id]);

  async function handleAddToCart() {
    setError(''); setSuccess('');
    const token = localStorage.getItem('token');
    try {
      await axios.post(`${process.env.NEXT_PUBLIC_API_URL}/carts/me`, {
        product: id,
        variantId: product.variants?.[variantIdx]?.sku,
        quantity
      }, token ? { headers: { Authorization: `Bearer ${token}` } } : {});
      setSuccess('Added to cart!');
    } catch (err) {
      setError('Failed to add to cart');
    }
  }

  if (loading) return <p>Loading...</p>;
  if (!product) return <p>Product not found.</p>;

  return (
    <main className="max-w-4xl mx-auto px-4 py-8">
      <div className="flex flex-col md:flex-row gap-8">
        <img src={product.images?.[0] || '/placeholder.png'} alt={product.name} className="w-full md:w-1/2 h-96 object-cover rounded" />
        <div className="flex-1">
          <h1 className="text-3xl font-bold mb-2">{product.name}</h1>
          <p className="text-gray-600 mb-4">{product.description}</p>
          <div className="mb-4">
            <span className="font-semibold">Category:</span> {product.categories?.join(', ')}
          </div>
          <div className="mb-4">
            <span className="font-semibold">Variants:</span>
            <select className="ml-2 border p-2 rounded" value={variantIdx} onChange={e => setVariantIdx(Number(e.target.value))}>
              {product.variants?.map((v, i) => (
                <option key={v.sku} value={i}>{Object.entries(v.options || {}).map(([k, val]) => `${k}: ${val}`).join(', ')} - ${v.price}$</option>
              ))}
            </select>
          </div>
          <div className="mb-4">
            <span className="font-semibold">Quantity:</span>
            <input type="number" min="1" max={product.variants?.[variantIdx]?.stock || 99} value={quantity} onChange={e => setQuantity(Number(e.target.value))} className="ml-2 border p-2 rounded w-20" />
          </div>
          <button onClick={handleAddToCart} className="bg-blue-600 text-white px-6 py-2 rounded hover:bg-blue-700">Add to Cart</button>
          {success && <p className="text-green-600 mt-2">{success}</p>}
          {error && <p className="text-red-500 mt-2">{error}</p>}
        </div>
      </div>
      <div className="mt-8">
        <h2 className="text-2xl font-bold mb-4">Reviews</h2>
        {reviews.length === 0 ? <p>No reviews yet.</p> : (
          <div className="space-y-4">
            {reviews.map(r => (
              <div key={r._id} className="border p-4 rounded">
                <div className="flex items-center gap-2 mb-1">
                  <span className="font-semibold">{r.user?.name || 'User'}</span>
                  <span className="text-yellow-500">{'★'.repeat(r.rating)}{'☆'.repeat(5 - r.rating)}</span>
                </div>
                <p className="text-gray-700">{r.comment}</p>
              </div>
            ))}
          </div>
        )}
      </div>
    </main>
  );
}

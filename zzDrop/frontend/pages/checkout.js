import { useEffect, useState } from 'react';
import axios from 'axios';
import { useRouter } from 'next/router';

export default function Checkout() {
  const router = useRouter();
  const [cart, setCart] = useState(null);
  const [shipping, setShipping] = useState({ street: '', city: '', state: '', zip: '', country: '' });
  const [paymentMethod, setPaymentMethod] = useState('cod');
  const [coupon, setCoupon] = useState('');
  const [couponInfo, setCouponInfo] = useState(null);
  const [couponError, setCouponError] = useState('');
  const [discount, setDiscount] = useState(0);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState('');
  const [success, setSuccess] = useState('');

  useEffect(() => {
    const token = localStorage.getItem('token');
    if (!token) return router.push('/login');
    axios.get(`${process.env.NEXT_PUBLIC_API_URL}/carts/me`, {
      headers: { Authorization: `Bearer ${token}` }
    })
      .then(res => { setCart(res.data); setLoading(false); })
      .catch(() => setLoading(false));
  }, [router]);

  async function handleCheckout(e) {
    e.preventDefault();
    setError(''); setSuccess('');
    const token = localStorage.getItem('token');
    try {
      const res = await axios.post(`${process.env.NEXT_PUBLIC_API_URL}/orders/checkout`, {
        shippingAddress: shipping,
        paymentMethod,
        coupon: couponInfo ? couponInfo.code : undefined
      }, { headers: { Authorization: `Bearer ${token}` } });
      setSuccess('Order placed successfully!');
      if (res.data.breakdown) {
        setOrderBreakdown(res.data.breakdown);
      }
      setTimeout(() => router.push(`/order/${res.data._id}`), 1500);
    } catch (err) {
      setError(err.response?.data?.message || 'Checkout failed');
    }
  }

  async function handleCoupon(e) {
    e.preventDefault();
    setCouponError('');
    setCouponInfo(null);
    setDiscount(0);
    const token = localStorage.getItem('token');
    try {
      const res = await axios.post(`${process.env.NEXT_PUBLIC_API_URL}/coupons/validate`, {
        code: coupon,
        orderTotal: cart.total
      }, { headers: { Authorization: `Bearer ${token}` } });
      setCouponInfo(res.data.coupon);
      let disc = 0;
      if (res.data.coupon.discountType === 'percent') {
        disc = (cart.total * res.data.coupon.discountValue) / 100;
      } else {
        disc = res.data.coupon.discountValue;
      }
      setDiscount(disc);
    } catch (err) {
      setCouponError(err.response?.data?.message || 'Invalid coupon');
    }
  }

  if (loading) return <p>Loading...</p>;
  if (!cart || !cart.items.length) return <p>Your cart is empty.</p>;

  const finalTotal = Math.max(0, (cart.total || 0) - discount);
  const [orderBreakdown, setOrderBreakdown] = useState(null);

  return (
    <main className="max-w-2xl mx-auto px-4 py-8">
      <h1 className="text-3xl font-bold mb-6">Checkout</h1>
      <form onSubmit={handleCheckout} className="bg-white p-6 rounded shadow">
        <h2 className="text-xl font-semibold mb-4">Shipping Address</h2>
        <div className="grid grid-cols-1 md:grid-cols-2 gap-4 mb-4">
          <input type="text" placeholder="Street" className="border p-2 rounded" value={shipping.street} onChange={e => setShipping({ ...shipping, street: e.target.value })} required />
          <input type="text" placeholder="City" className="border p-2 rounded" value={shipping.city} onChange={e => setShipping({ ...shipping, city: e.target.value })} required />
          <input type="text" placeholder="State" className="border p-2 rounded" value={shipping.state} onChange={e => setShipping({ ...shipping, state: e.target.value })} required />
          <input type="text" placeholder="ZIP" className="border p-2 rounded" value={shipping.zip} onChange={e => setShipping({ ...shipping, zip: e.target.value })} required />
          <input type="text" placeholder="Country" className="border p-2 rounded" value={shipping.country} onChange={e => setShipping({ ...shipping, country: e.target.value })} required />
        </div>
        <h2 className="text-xl font-semibold mb-4">Coupon</h2>
        <div className="flex gap-2 mb-4">
          <input type="text" placeholder="Enter coupon code" className="border p-2 rounded flex-1" value={coupon} onChange={e => setCoupon(e.target.value)} />
          <button type="button" onClick={handleCoupon} className="bg-blue-600 text-white px-4 py-2 rounded hover:bg-blue-700">Apply</button>
        </div>
        {couponInfo && <p className="text-green-600 mb-2">Coupon applied: {couponInfo.code} ({couponInfo.discountType === 'percent' ? couponInfo.discountValue + '%' : '$' + couponInfo.discountValue} off)</p>}
        {couponError && <p className="text-red-500 mb-2">{couponError}</p>}
        <h2 className="text-xl font-semibold mb-4">Payment Method</h2>
        <select className="border p-2 rounded mb-4 w-full" value={paymentMethod} onChange={e => setPaymentMethod(e.target.value)}>
          <option value="cod">Cash on Delivery</option>
          <option value="stripe">Stripe (stub)</option>
        </select>
        <div className="mb-4">
          {orderBreakdown ? (
            <>
              <div>Subtotal: <span className="font-semibold">${orderBreakdown.subtotal.toFixed(2)}</span></div>
              <div>Shipping: <span>${orderBreakdown.shipping.toFixed(2)}</span></div>
              <div>Tax: <span>${orderBreakdown.tax.toFixed(2)}</span></div>
              {orderBreakdown.discount > 0 && <div>Discount: <span className="text-green-600">-${orderBreakdown.discount.toFixed(2)}</span></div>}
              <div className="text-lg font-bold">Total: ${orderBreakdown.finalTotal.toFixed(2)}</div>
            </>
          ) : (
            <>
              <div>Subtotal: <span className="font-semibold">${cart.total?.toFixed(2)}</span></div>
              {discount > 0 && <div>Discount: <span className="text-green-600">-${discount.toFixed(2)}</span></div>}
              <div className="text-lg font-bold">Total: ${finalTotal.toFixed(2)}</div>
            </>
          )}
        </div>
        <button type="submit" className="w-full bg-green-600 text-white py-2 rounded hover:bg-green-700">Place Order</button>
        {success && <p className="text-green-600 mt-4">{success}</p>}
        {error && <p className="text-red-500 mt-4">{error}</p>}
      </form>
    </main>
  );
}


import { useRouter } from 'next/router';
import { useEffect, useState } from 'react';
import axios from 'axios';

export default function CMSPage() {
  const router = useRouter();
  const { slug } = router.query;
  const [page, setPage] = useState(null);
  const [loading, setLoading] = useState(true);

  useEffect(() => {
    if (!slug) return;
    axios.get(`${process.env.NEXT_PUBLIC_API_URL}/pages/${slug}`)
      .then(res => { setPage(res.data); setLoading(false); })
      .catch(() => setLoading(false));
  }, [slug]);

  if (loading) return <p>Loading...</p>;
  if (!page) return <p>Page not found.</p>;

  return (
    <main className="max-w-2xl mx-auto px-4 py-8">
      <h1 className="text-3xl font-bold mb-6">{page.title}</h1>
      <div className="prose prose-lg" dangerouslySetInnerHTML={{ __html: page.content }} />
    </main>
  );
}

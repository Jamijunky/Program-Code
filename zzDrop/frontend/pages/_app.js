import '../styles/globals.css';

import Head from 'next/head';

export default function App({ Component, pageProps }) {
  return (
    <>
      <Head>
        <title>PFM</title>
      </Head>
      <header className="w-full bg-white py-4 shadow flex flex-col items-center mb-4">
        <div className="text-3xl font-extrabold tracking-tight text-blue-700">PFM</div>
        <div className="text-xs text-gray-500 font-semibold tracking-wide">ProfessionalsMart</div>
      </header>
      <Component {...pageProps} />
    </>
  );
}


// src/pages/_app.tsx
import { useEffect } from 'react';
import { AppProps } from 'next/app';
import { useRouter } from 'next/router';
import { AuthProvider } from '@/context/AuthContext';
import { CartProvider } from '@/context/CartContext';
import { UIProvider } from '@/context/UIContext';
import { WishlistProvider } from '@/context/WishlistContext';
import Layout from '@/components/layout/Layout';
import { initGA, logPageView } from '@/lib/analytics';
import '@/styles/globals.css';

function MyApp({ Component, pageProps }: AppProps) {
  const router = useRouter();
  
  useEffect(() => {
    // Initialize Google Analytics
    if (process.env.NODE_ENV === 'production') {
      initGA();
      logPageView();
      
      // Log page views on route changes
      router.events.on('routeChangeComplete', logPageView);
      
      return () => {
        router.events.off('routeChangeComplete', logPageView);
      };
    }
  }, [router.events]);

  // Check if the current route is an admin route
  const isAdminRoute = router.pathname.startsWith('/admin');
  // Check if the current route is an auth route (login, register, etc.)
  const isAuthRoute = router.pathname.startsWith('/auth');
  
  return (
    <AuthProvider>
      <UIProvider>
        <CartProvider>
          <WishlistProvider>
            {isAuthRoute ? (
              // Auth pages don't need the full layout
              <Component {...pageProps} />
            ) : isAdminRoute ? (
              // Admin pages use admin layout 
              <Layout isAdmin>
                <Component {...pageProps} />
              </Layout>
            ) : (
              // Regular pages use the standard layout
              <Layout>
                <Component {...pageProps} />
              </Layout>
            )}
          </WishlistProvider>
        </CartProvider>
      </UIProvider>
    </AuthProvider>
  );
}

export default MyApp;
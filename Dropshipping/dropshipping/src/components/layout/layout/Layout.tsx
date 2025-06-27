// src/components/layout/Layout.tsx
import React, { ReactNode } from 'react';
import Head from 'next/head';
import Header from './Header';
import Footer from './Footer';
import Sidebar from './Sidebar';
import { useUI } from '@/hooks/useUI';
import CartSidebar from '../cart/CartSidebar';
import { useRouter } from 'next/router';
import SEO from '../common/SEO';

type LayoutProps = {
  children: ReactNode;
  title?: string;
  description?: string;
  isAdmin?: boolean;
};

const Layout: React.FC<LayoutProps> = ({ 
  children, 
  title = 'Dropship Store - Your One-Stop Shop', 
  description = 'Find the best products at the best prices with our dropshipping store.',
  isAdmin = false 
}) => {
  const { isSidebarOpen, isCartOpen } = useUI();
  const router = useRouter();

  return (
    <>
      <SEO title={title} description={description} />
      
      <div className="flex flex-col min-h-screen">
        {isAdmin ? (
          <div className="flex flex-grow">
            <Sidebar isAdmin />
            <div className="flex-1 overflow-x-hidden">
              <Header isAdmin />
              <main className="p-4 md:p-6 bg-gray-50">
                {children}
              </main>
            </div>
          </div>
        ) : (
          <>
            <Header />
            <main className="flex-grow">
              {children}
            </main>
            <Footer />
            
            {/* Cart Sidebar */}
            {isCartOpen && <CartSidebar />}
          </>
        )}
      </div>
    </>
  );
};

export default Layout;
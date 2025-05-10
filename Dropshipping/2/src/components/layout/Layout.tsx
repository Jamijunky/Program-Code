import React from 'react';
import Header from './Header';
import Footer from './Footer';
import { useLocation } from 'react-router-dom';

type LayoutProps = {
  children: React.ReactNode;
};

const Layout: React.FC<LayoutProps> = ({ children }) => {
  const location = useLocation();
  const isCheckoutPage = location.pathname === '/checkout';

  // Simplified header on checkout page
  return (
    <div className="flex flex-col min-h-screen">
      <Header simplified={isCheckoutPage} />
      <main className="flex-grow">{children}</main>
      <Footer />
    </div>
  );
};

export default Layout;
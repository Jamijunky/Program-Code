import React from 'react';
import MatrixRainingCode from './components/MatrixRainingCode';
import Navbar from './components/Navbar';
import Hero from './components/Hero';
import Features from './components/Features';
import Testimonials from './components/Testimonials';
import Pricing from './components/Pricing';
import Footer from './components/Footer';

function App() {
  return (
    <div className="min-h-screen">
      <MatrixRainingCode className="absolute inset-0" />
      <div className="flex flex-col">
        <Navbar />
        <Hero />
        <Features />
        <Testimonials />
        <Pricing />
        <Footer />
      </div>
    </div>
  );
}

export default App;
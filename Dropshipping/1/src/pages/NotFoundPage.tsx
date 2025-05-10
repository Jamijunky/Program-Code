import { Link } from 'react-router-dom';
import { Home, ShoppingBag } from 'lucide-react';

const NotFoundPage = () => {
  return (
    <div className="flex min-h-[60vh] flex-col items-center justify-center px-4 py-16 text-center">
      <h1 className="mb-4 text-9xl font-bold text-gray-200">404</h1>
      <h2 className="mb-4 text-3xl font-bold">Page Not Found</h2>
      <p className="mb-8 text-gray-600">The page you are looking for doesn't exist or has been moved.</p>
      <div className="flex flex-col space-y-3 sm:flex-row sm:space-x-3 sm:space-y-0">
        <Link to="/" className="btn btn-primary inline-flex items-center">
          <Home size={16} className="mr-2" />
          Return Home
        </Link>
        <Link to="/shop" className="btn btn-secondary inline-flex items-center">
          <ShoppingBag size={16} className="mr-2" />
          Continue Shopping
        </Link>
      </div>
    </div>
  );
};

export default NotFoundPage;
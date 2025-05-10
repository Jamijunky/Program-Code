import React from 'react';
import { Package, ChevronRight } from 'lucide-react';
import { Link } from 'react-router-dom';
import Button from '../components/ui/Button';

// Mock order data - in a real app, this would come from an API
const mockOrders = [
  {
    id: '1',
    date: '2024-02-15',
    status: 'delivered',
    total: 259.97,
    items: [
      {
        id: '1',
        title: 'Premium Wireless Earbuds',
        image: 'https://images.pexels.com/photos/3780681/pexels-photo-3780681.jpeg?auto=compress&cs=tinysrgb&w=600',
        price: 129.99,
        quantity: 1
      },
      {
        id: '2',
        title: 'Smart Fitness Tracker Watch',
        image: 'https://images.pexels.com/photos/437037/pexels-photo-437037.jpeg?auto=compress&cs=tinysrgb&w=600',
        price: 89.99,
        quantity: 1
      }
    ]
  },
  {
    id: '2',
    date: '2024-02-10',
    status: 'shipped',
    total: 49.99,
    items: [
      {
        id: '3',
        title: 'Minimalist Desk Lamp',
        image: 'https://images.pexels.com/photos/1112598/pexels-photo-1112598.jpeg?auto=compress&cs=tinysrgb&w=600',
        price: 49.99,
        quantity: 1
      }
    ]
  }
];

const OrdersPage: React.FC = () => {
  if (mockOrders.length === 0) {
    return (
      <div className="container mx-auto px-4 py-16 text-center">
        <div className="mb-6 flex justify-center">
          <div className="bg-gray-100 rounded-full p-6">
            <Package size={64} className="text-gray-400" />
          </div>
        </div>
        <h1 className="text-2xl font-bold text-gray-900 mb-4">No Orders Yet</h1>
        <p className="text-gray-600 mb-8 max-w-md mx-auto">
          Looks like you haven't placed any orders yet. Start shopping to see your orders here.
        </p>
        <Link to="/products">
          <Button variant="primary">Browse Products</Button>
        </Link>
      </div>
    );
  }

  return (
    <div className="bg-gray-50 min-h-screen py-8">
      <div className="container mx-auto px-4">
        <h1 className="text-2xl md:text-3xl font-bold text-gray-900 mb-8">Your Orders</h1>
        
        <div className="space-y-6">
          {mockOrders.map((order) => (
            <div key={order.id} className="bg-white rounded-lg shadow-sm overflow-hidden">
              {/* Order Header */}
              <div className="p-6 border-b border-gray-200">
                <div className="flex flex-col sm:flex-row sm:items-center justify-between">
                  <div>
                    <p className="text-sm text-gray-500">Order placed</p>
                    <p className="font-medium">{new Date(order.date).toLocaleDateString()}</p>
                  </div>
                  <div className="mt-2 sm:mt-0">
                    <p className="text-sm text-gray-500">Order number</p>
                    <p className="font-medium">{order.id}</p>
                  </div>
                  <div className="mt-2 sm:mt-0">
                    <p className="text-sm text-gray-500">Total</p>
                    <p className="font-medium">${order.total.toFixed(2)}</p>
                  </div>
                  <div className="mt-2 sm:mt-0">
                    <span className={`inline-flex items-center px-2.5 py-0.5 rounded-full text-xs font-medium capitalize ${
                      order.status === 'delivered' 
                        ? 'bg-green-100 text-green-800'
                        : 'bg-blue-100 text-blue-800'
                    }`}>
                      {order.status}
                    </span>
                  </div>
                </div>
              </div>
              
              {/* Order Items */}
              <div className="divide-y divide-gray-200">
                {order.items.map((item) => (
                  <div key={item.id} className="p-6 flex items-center">
                    <div className="h-20 w-20 flex-shrink-0 overflow-hidden rounded-lg bg-gray-100">
                      <img
                        src={item.image}
                        alt={item.title}
                        className="h-full w-full object-cover object-center"
                      />
                    </div>
                    <div className="ml-6 flex-1">
                      <div className="flex items-center justify-between">
                        <h3 className="text-base font-medium text-gray-900">
                          <Link to={`/products/${item.id}`} className="hover:text-primary-700">
                            {item.title}
                          </Link>
                        </h3>
                        <p className="text-sm font-medium text-gray-900">
                          ${item.price.toFixed(2)}
                        </p>
                      </div>
                      <p className="mt-1 text-sm text-gray-500">Quantity: {item.quantity}</p>
                    </div>
                  </div>
                ))}
              </div>
              
              {/* Order Actions */}
              <div className="p-6 bg-gray-50 flex justify-between items-center">
                <Button
                  variant="outline"
                  size="sm"
                  onClick={() => {}}
                >
                  Track Order
                </Button>
                <Link
                  to={`/orders/${order.id}`}
                  className="text-primary-700 hover:text-primary-800 font-medium flex items-center text-sm"
                >
                  View Order Details <ChevronRight size={16} className="ml-1" />
                </Link>
              </div>
            </div>
          ))}
        </div>
      </div>
    </div>
  );
};

export default OrdersPage;
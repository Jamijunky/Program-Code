import { useState } from 'react';
import { Link, Routes, Route, useNavigate } from 'react-router-dom';
import { Package, ShoppingBag, Users, BarChart2, Settings, LogOut, Plus, Search } from 'lucide-react';
import { useAuth } from '../contexts/AuthContext';
import { productData } from '../data/products';

const DashboardSidebar = ({ activeTab }: { activeTab: string }) => {
  const { logout } = useAuth();
  const navigate = useNavigate();

  const handleLogout = () => {
    logout();
    navigate('/');
  };

  const menuItems = [
    { id: 'overview', name: 'Overview', icon: <BarChart2 size={20} />, path: '/dashboard' },
    { id: 'products', name: 'Products', icon: <Package size={20} />, path: '/dashboard/products' },
    { id: 'orders', name: 'Orders', icon: <ShoppingBag size={20} />, path: '/dashboard/orders' },
    { id: 'customers', name: 'Customers', icon: <Users size={20} />, path: '/dashboard/customers' },
    { id: 'settings', name: 'Settings', icon: <Settings size={20} />, path: '/dashboard/settings' },
  ];

  return (
    <div className="h-full bg-white">
      <div className="flex h-16 items-center justify-center border-b border-gray-200">
        <Link to="/" className="text-xl font-bold text-blue-600">
          DropMarket Admin
        </Link>
      </div>
      <nav className="p-4">
        <ul className="space-y-1">
          {menuItems.map((item) => (
            <li key={item.id}>
              <Link
                to={item.path}
                className={`flex items-center rounded-md px-3 py-2 ${
                  activeTab === item.id
                    ? 'bg-blue-50 text-blue-600'
                    : 'text-gray-700 hover:bg-gray-100'
                }`}
              >
                <span className="mr-3">{item.icon}</span>
                {item.name}
              </Link>
            </li>
          ))}
          <li className="mt-6">
            <button
              onClick={handleLogout}
              className="flex w-full items-center rounded-md px-3 py-2 text-left text-red-600 hover:bg-red-50"
            >
              <LogOut size={20} className="mr-3" />
              Logout
            </button>
          </li>
        </ul>
      </nav>
    </div>
  );
};

const DashboardHeader = ({ title }: { title: string }) => {
  const { user } = useAuth();

  return (
    <header className="bg-white px-6 py-4 shadow">
      <div className="flex items-center justify-between">
        <h1 className="text-2xl font-bold">{title}</h1>
        <div className="flex items-center space-x-4">
          <div className="flex items-center rounded-md bg-gray-100 px-3 py-2">
            <Search size={18} className="text-gray-500" />
            <input
              type="text"
              placeholder="Search..."
              className="ml-2 bg-transparent text-sm focus:outline-none"
            />
          </div>
          <div className="flex items-center">
            <div className="flex h-8 w-8 items-center justify-center rounded-full bg-blue-100 text-blue-600">
              <span className="text-sm font-medium">{user?.name.charAt(0)}</span>
            </div>
            <span className="ml-2 text-sm font-medium">{user?.name}</span>
          </div>
        </div>
      </div>
    </header>
  );
};

// Dashboard Overview
const DashboardOverview = () => {
  const stats = [
    { id: 'revenue', name: 'Total Revenue', value: '$12,345.67', change: '+12.5%' },
    { id: 'orders', name: 'Orders', value: '156', change: '+5.2%' },
    { id: 'customers', name: 'Customers', value: '1,245', change: '+2.3%' },
    { id: 'products', name: 'Products', value: productData.length.toString(), change: '0%' },
  ];

  const recentOrders = [
    { id: 'ORD-001', customer: 'John Doe', date: '2023-06-15', status: 'Delivered', total: '$125.99' },
    { id: 'ORD-002', customer: 'Jane Smith', date: '2023-06-14', status: 'Processing', total: '$89.50' },
    { id: 'ORD-003', customer: 'Michael Johnson', date: '2023-06-14', status: 'Shipped', total: '$246.75' },
    { id: 'ORD-004', customer: 'Sarah Williams', date: '2023-06-13', status: 'Delivered', total: '$59.99' },
    { id: 'ORD-005', customer: 'Robert Brown', date: '2023-06-12', status: 'Cancelled', total: '$132.45' },
  ];

  return (
    <div className="p-6">
      <div className="mb-8 grid grid-cols-1 gap-4 sm:grid-cols-2 md:grid-cols-4">
        {stats.map((stat) => (
          <div key={stat.id} className="rounded-lg border border-gray-200 bg-white p-4 shadow-sm">
            <p className="text-sm font-medium text-gray-600">{stat.name}</p>
            <p className="mt-2 text-2xl font-bold">{stat.value}</p>
            <p className={`mt-1 text-xs ${stat.change.startsWith('+') ? 'text-green-600' : stat.change === '0%' ? 'text-gray-500' : 'text-red-600'}`}>
              {stat.change} from last month
            </p>
          </div>
        ))}
      </div>

      <div className="mb-8">
        <h2 className="mb-4 text-lg font-bold">Recent Orders</h2>
        <div className="overflow-hidden rounded-lg border border-gray-200 bg-white shadow-sm">
          <table className="min-w-full divide-y divide-gray-200">
            <thead className="bg-gray-50">
              <tr>
                <th className="px-6 py-3 text-left text-xs font-medium uppercase tracking-wider text-gray-500">
                  Order ID
                </th>
                <th className="px-6 py-3 text-left text-xs font-medium uppercase tracking-wider text-gray-500">
                  Customer
                </th>
                <th className="px-6 py-3 text-left text-xs font-medium uppercase tracking-wider text-gray-500">
                  Date
                </th>
                <th className="px-6 py-3 text-left text-xs font-medium uppercase tracking-wider text-gray-500">
                  Status
                </th>
                <th className="px-6 py-3 text-left text-xs font-medium uppercase tracking-wider text-gray-500">
                  Total
                </th>
                <th className="px-6 py-3 text-right text-xs font-medium uppercase tracking-wider text-gray-500">
                  Actions
                </th>
              </tr>
            </thead>
            <tbody className="divide-y divide-gray-200 bg-white">
              {recentOrders.map((order) => (
                <tr key={order.id}>
                  <td className="whitespace-nowrap px-6 py-4">
                    <span className="font-medium text-blue-600">{order.id}</span>
                  </td>
                  <td className="whitespace-nowrap px-6 py-4">{order.customer}</td>
                  <td className="whitespace-nowrap px-6 py-4">{order.date}</td>
                  <td className="whitespace-nowrap px-6 py-4">
                    <span
                      className={`inline-flex rounded-full px-2 text-xs font-semibold leading-5 ${
                        order.status === 'Delivered'
                          ? 'bg-green-100 text-green-800'
                          : order.status === 'Processing'
                          ? 'bg-yellow-100 text-yellow-800'
                          : order.status === 'Shipped'
                          ? 'bg-blue-100 text-blue-800'
                          : 'bg-red-100 text-red-800'
                      }`}
                    >
                      {order.status}
                    </span>
                  </td>
                  <td className="whitespace-nowrap px-6 py-4">{order.total}</td>
                  <td className="whitespace-nowrap px-6 py-4 text-right text-sm font-medium">
                    <a href="#" className="text-blue-600 hover:text-blue-900">
                      View
                    </a>
                  </td>
                </tr>
              ))}
            </tbody>
          </table>
        </div>
      </div>

      <div>
        <h2 className="mb-4 text-lg font-bold">Top Selling Products</h2>
        <div className="overflow-hidden rounded-lg border border-gray-200 bg-white shadow-sm">
          <table className="min-w-full divide-y divide-gray-200">
            <thead className="bg-gray-50">
              <tr>
                <th className="px-6 py-3 text-left text-xs font-medium uppercase tracking-wider text-gray-500">
                  Product
                </th>
                <th className="px-6 py-3 text-left text-xs font-medium uppercase tracking-wider text-gray-500">
                  Category
                </th>
                <th className="px-6 py-3 text-left text-xs font-medium uppercase tracking-wider text-gray-500">
                  Price
                </th>
                <th className="px-6 py-3 text-left text-xs font-medium uppercase tracking-wider text-gray-500">
                  Sold
                </th>
                <th className="px-6 py-3 text-left text-xs font-medium uppercase tracking-wider text-gray-500">
                  Revenue
                </th>
              </tr>
            </thead>
            <tbody className="divide-y divide-gray-200 bg-white">
              {productData.slice(0, 5).map((product) => (
                <tr key={product.id}>
                  <td className="px-6 py-4">
                    <div className="flex items-center">
                      <div className="h-10 w-10 flex-shrink-0">
                        <img
                          className="h-10 w-10 rounded-md object-cover"
                          src={product.image}
                          alt={product.name}
                        />
                      </div>
                      <div className="ml-4">
                        <div className="text-sm font-medium text-gray-900">{product.name}</div>
                      </div>
                    </div>
                  </td>
                  <td className="whitespace-nowrap px-6 py-4 text-sm text-gray-500">
                    {product.category}
                  </td>
                  <td className="whitespace-nowrap px-6 py-4 text-sm text-gray-500">
                    ${product.price.toFixed(2)}
                  </td>
                  <td className="whitespace-nowrap px-6 py-4 text-sm text-gray-500">
                    {Math.floor(Math.random() * 100) + 1}
                  </td>
                  <td className="whitespace-nowrap px-6 py-4 text-sm text-gray-500">
                    ${((Math.floor(Math.random() * 100) + 1) * product.price).toFixed(2)}
                  </td>
                </tr>
              ))}
            </tbody>
          </table>
        </div>
      </div>
    </div>
  );
};

// Products Management
const ProductsManagement = () => {
  return (
    <div className="p-6">
      <div className="mb-6 flex items-center justify-between">
        <div className="flex items-center space-x-4">
          <div className="relative">
            <input
              type="text"
              placeholder="Search products..."
              className="rounded-md border border-gray-300 py-2 pl-10 pr-4 focus:border-blue-500 focus:outline-none focus:ring-1 focus:ring-blue-500"
            />
            <Search className="absolute left-3 top-1/2 h-4 w-4 -translate-y-1/2 text-gray-400" />
          </div>
          <select className="rounded-md border border-gray-300 px-3 py-2 focus:border-blue-500 focus:outline-none focus:ring-1 focus:ring-blue-500">
            <option value="">All Categories</option>
            <option value="Electronics">Electronics</option>
            <option value="Clothing">Clothing</option>
            <option value="Home">Home & Kitchen</option>
            <option value="Beauty">Beauty</option>
          </select>
        </div>
        <button className="flex items-center rounded-md bg-blue-600 px-4 py-2 text-white hover:bg-blue-700">
          <Plus size={16} className="mr-2" />
          Add Product
        </button>
      </div>

      <div className="overflow-hidden rounded-lg border border-gray-200 bg-white shadow-sm">
        <table className="min-w-full divide-y divide-gray-200">
          <thead className="bg-gray-50">
            <tr>
              <th className="px-6 py-3 text-left text-xs font-medium uppercase tracking-wider text-gray-500">
                Product
              </th>
              <th className="px-6 py-3 text-left text-xs font-medium uppercase tracking-wider text-gray-500">
                Category
              </th>
              <th className="px-6 py-3 text-left text-xs font-medium uppercase tracking-wider text-gray-500">
                Price
              </th>
              <th className="px-6 py-3 text-left text-xs font-medium uppercase tracking-wider text-gray-500">
                Stock
              </th>
              <th className="px-6 py-3 text-left text-xs font-medium uppercase tracking-wider text-gray-500">
                Rating
              </th>
              <th className="px-6 py-3 text-right text-xs font-medium uppercase tracking-wider text-gray-500">
                Actions
              </th>
            </tr>
          </thead>
          <tbody className="divide-y divide-gray-200 bg-white">
            {productData.map((product) => (
              <tr key={product.id}>
                <td className="px-6 py-4">
                  <div className="flex items-center">
                    <div className="h-10 w-10 flex-shrink-0">
                      <img
                        className="h-10 w-10 rounded-md object-cover"
                        src={product.image}
                        alt={product.name}
                      />
                    </div>
                    <div className="ml-4">
                      <div className="text-sm font-medium text-gray-900">{product.name}</div>
                      <div className="text-xs text-gray-500">ID: {product.id}</div>
                    </div>
                  </div>
                </td>
                <td className="whitespace-nowrap px-6 py-4 text-sm text-gray-500">
                  {product.category}
                </td>
                <td className="whitespace-nowrap px-6 py-4 text-sm text-gray-500">
                  ${product.price.toFixed(2)}
                </td>
                <td className="whitespace-nowrap px-6 py-4 text-sm">
                  <span
                    className={`inline-flex rounded-full px-2 text-xs font-semibold leading-5 ${
                      product.inStock
                        ? 'bg-green-100 text-green-800'
                        : 'bg-red-100 text-red-800'
                    }`}
                  >
                    {product.inStock ? 'In Stock' : 'Out of Stock'}
                  </span>
                </td>
                <td className="whitespace-nowrap px-6 py-4 text-sm text-gray-500">
                  <div className="flex items-center">
                    <span className="mr-1 text-amber-500">★</span>
                    {product.rating.toFixed(1)}
                  </div>
                </td>
                <td className="whitespace-nowrap px-6 py-4 text-right text-sm font-medium">
                  <a href="#" className="mr-3 text-blue-600 hover:text-blue-900">
                    Edit
                  </a>
                  <a href="#" className="text-red-600 hover:text-red-900">
                    Delete
                  </a>
                </td>
              </tr>
            ))}
          </tbody>
        </table>
      </div>

      <div className="mt-4 flex items-center justify-between">
        <div className="text-sm text-gray-500">
          Showing <span className="font-medium">1</span> to{' '}
          <span className="font-medium">{productData.length}</span> of{' '}
          <span className="font-medium">{productData.length}</span> results
        </div>
        <div className="flex space-x-2">
          <button className="rounded-md border border-gray-300 bg-white px-3 py-1 text-sm hover:bg-gray-50">
            Previous
          </button>
          <button className="rounded-md bg-blue-600 px-3 py-1 text-sm text-white hover:bg-blue-700">
            1
          </button>
          <button className="rounded-md border border-gray-300 bg-white px-3 py-1 text-sm hover:bg-gray-50">
            Next
          </button>
        </div>
      </div>
    </div>
  );
};

// Placeholder components for other sections
const OrdersManagement = () => (
  <div className="p-6">
    <h2 className="mb-4 text-lg font-bold">Orders Management</h2>
    <p className="text-gray-600">Manage and process customer orders here.</p>
  </div>
);

const CustomersManagement = () => (
  <div className="p-6">
    <h2 className="mb-4 text-lg font-bold">Customers Management</h2>
    <p className="text-gray-600">View and manage customer accounts.</p>
  </div>
);

const SettingsPage = () => (
  <div className="p-6">
    <h2 className="mb-4 text-lg font-bold">Store Settings</h2>
    <p className="text-gray-600">Configure your store settings and preferences.</p>
  </div>
);

// Main Dashboard Page
const DashboardPage = () => {
  const [activeTab, setActiveTab] = useState('overview');

  return (
    <div className="flex h-screen">
      <div className="w-64 flex-shrink-0 border-r border-gray-200">
        <DashboardSidebar activeTab={activeTab} />
      </div>
      <div className="flex flex-1 flex-col">
        <Routes>
          <Route
            path="/"
            element={
              <>
                <DashboardHeader title="Dashboard Overview" />
                <div className="flex-1 overflow-y-auto bg-gray-50">
                  <DashboardOverview />
                </div>
              </>
            }
          />
          <Route
            path="/products"
            element={
              <>
                <DashboardHeader title="Products Management" />
                <div className="flex-1 overflow-y-auto bg-gray-50">
                  <ProductsManagement />
                </div>
              </>
            }
          />
          <Route
            path="/orders"
            element={
              <>
                <DashboardHeader title="Orders Management" />
                <div className="flex-1 overflow-y-auto bg-gray-50">
                  <OrdersManagement />
                </div>
              </>
            }
          />
          <Route
            path="/customers"
            element={
              <>
                <DashboardHeader title="Customers Management" />
                <div className="flex-1 overflow-y-auto bg-gray-50">
                  <CustomersManagement />
                </div>
              </>
            }
          />
          <Route
            path="/settings"
            element={
              <>
                <DashboardHeader title="Store Settings" />
                <div className="flex-1 overflow-y-auto bg-gray-50">
                  <SettingsPage />
                </div>
              </>
            }
          />
        </Routes>
      </div>
    </div>
  );
};

export default DashboardPage;
import React, { useState, useEffect } from 'react';
import { 
  ShoppingCartIcon, 
  UserGroupIcon, 
  CurrencyDollarIcon, 
  TrendingUpIcon,
  TrendingDownIcon,
  EyeIcon,
  ClockIcon,
  CheckCircleIcon,
  XCircleIcon
} from '@heroicons/react/outline';

// Mock data - replace with real API calls
const mockStats = {
  totalSales: 45890,
  totalOrders: 234,
  totalCustomers: 1456,
  pendingOrders: 12,
  salesGrowth: 12.5,
  ordersGrowth: -3.2,
  customerGrowth: 8.7,
  conversionRate: 3.4
};

const mockRecentOrders = [
  { id: 'ORD-001', customer: 'John Doe', amount: 129.99, status: 'processing', date: '2025-06-27' },
  { id: 'ORD-002', customer: 'Jane Smith', amount: 89.50, status: 'shipped', date: '2025-06-27' },
  { id: 'ORD-003', customer: 'Mike Johnson', amount: 199.00, status: 'delivered', date: '2025-06-26' },
  { id: 'ORD-004', customer: 'Sarah Wilson', amount: 75.25, status: 'cancelled', date: '2025-06-26' },
  { id: 'ORD-005', customer: 'Tom Brown', amount: 149.99, status: 'processing', date: '2025-06-25' }
];

const mockTopProducts = [
  { id: 1, name: 'Wireless Headphones', sales: 145, revenue: 14500 },
  { id: 2, name: 'Smart Watch', sales: 89, revenue: 17800 },
  { id: 3, name: 'Phone Case', sales: 234, revenue: 4680 },
  { id: 4, name: 'Bluetooth Speaker', sales: 67, revenue: 6700 },
  { id: 5, name: 'Laptop Stand', sales: 98, revenue: 4900 }
];

interface StatCardProps {
  title: string;
  value: string | number;
  growth?: number;
  icon: React.ReactNode;
  color: string;
}

const StatCard: React.FC<StatCardProps> = ({ title, value, growth, icon, color }) => (
  <div className="bg-white rounded-lg shadow p-6">
    <div className="flex items-center">
      <div className={`p-3 rounded-lg ${color}`}>
        {icon}
      </div>
      <div className="ml-4 flex-1">
        <p className="text-sm font-medium text-gray-600">{title}</p>
        <p className="text-2xl font-bold text-gray-900">{value}</p>
        {growth !== undefined && (
          <div className="flex items-center mt-1">
            {growth >= 0 ? (
              <TrendingUpIcon className="w-4 h-4 text-green-500 mr-1" />
            ) : (
              <TrendingDownIcon className="w-4 h-4 text-red-500 mr-1" />
            )}
            <span className={`text-sm font-medium ${growth >= 0 ? 'text-green-600' : 'text-red-600'}`}>
              {Math.abs(growth)}%
            </span>
          </div>
        )}
      </div>
    </div>
  </div>
);

const getStatusBadge = (status: string) => {
  const statusConfig = {
    processing: { color: 'bg-yellow-100 text-yellow-800', icon: ClockIcon },
    shipped: { color: 'bg-blue-100 text-blue-800', icon: TrendingUpIcon },
    delivered: { color: 'bg-green-100 text-green-800', icon: CheckCircleIcon },
    cancelled: { color: 'bg-red-100 text-red-800', icon: XCircleIcon }
  };
  
  const config = statusConfig[status as keyof typeof statusConfig];
  const Icon = config.icon;
  
  return (
    <span className={`inline-flex items-center px-2.5 py-0.5 rounded-full text-xs font-medium ${config.color}`}>
      <Icon className="w-3 h-3 mr-1" />
      {status.charAt(0).toUpperCase() + status.slice(1)}
    </span>
  );
};

const Dashboard: React.FC = () => {
  const [timeRange, setTimeRange] = useState('7d');
  
  return (
    <div className="space-y-6">
      {/* Header */}
      <div className="flex justify-between items-center">
        <div>
          <h1 className="text-2xl font-bold text-gray-900">Dashboard</h1>
          <p className="text-gray-600">Welcome back! Here's what's happening with your store.</p>
        </div>
        <div className="flex items-center space-x-2">
          <select 
            value={timeRange} 
            onChange={(e) => setTimeRange(e.target.value)}
            className="border border-gray-300 rounded-lg px-3 py-2 text-sm focus:outline-none focus:ring-2 focus:ring-indigo-500"
          >
            <option value="24h">Last 24 hours</option>
            <option value="7d">Last 7 days</option>
            <option value="30d">Last 30 days</option>
            <option value="90d">Last 90 days</option>
          </select>
        </div>
      </div>

      {/* Stats Grid */}
      <div className="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-4 gap-6">
        <StatCard
          title="Total Sales"
          value={`$${mockStats.totalSales.toLocaleString()}`}
          growth={mockStats.salesGrowth}
          icon={<CurrencyDollarIcon className="w-6 h-6 text-white" />}
          color="bg-green-500"
        />
        <StatCard
          title="Total Orders"
          value={mockStats.totalOrders}
          growth={mockStats.ordersGrowth}
          icon={<ShoppingCartIcon className="w-6 h-6 text-white" />}
          color="bg-blue-500"
        />
        <StatCard
          title="Customers"
          value={mockStats.totalCustomers}
          growth={mockStats.customerGrowth}
          icon={<UserGroupIcon className="w-6 h-6 text-white" />}
          color="bg-purple-500"
        />
        <StatCard
          title="Conversion Rate"
          value={`${mockStats.conversionRate}%`}
          icon={<TrendingUpIcon className="w-6 h-6 text-white" />}
          color="bg-indigo-500"
        />
      </div>

      <div className="grid grid-cols-1 lg:grid-cols-2 gap-6">
        {/* Recent Orders */}
        <div className="bg-white rounded-lg shadow">
          <div className="px-6 py-4 border-b border-gray-200">
            <div className="flex items-center justify-between">
              <h3 className="text-lg font-medium text-gray-900">Recent Orders</h3>
              <button className="text-indigo-600 hover:text-indigo-800 text-sm font-medium">
                View all
              </button>
            </div>
          </div>
          <div className="divide-y divide-gray-200">
            {mockRecentOrders.map((order) => (
              <div key={order.id} className="px-6 py-4">
                <div className="flex items-center justify-between">
                  <div className="flex-1">
                    <div className="flex items-center space-x-3">
                      <p className="text-sm font-medium text-gray-900">{order.id}</p>
                      {getStatusBadge(order.status)}
                    </div>
                    <p className="text-sm text-gray-600 mt-1">{order.customer}</p>
                    <p className="text-xs text-gray-500 mt-1">{order.date}</p>
                  </div>
                  <div className="text-right">
                    <p className="text-sm font-medium text-gray-900">${order.amount}</p>
                    <button className="text-xs text-indigo-600 hover:text-indigo-800 mt-1">
                      <EyeIcon className="w-4 h-4 inline mr-1" />
                      View
                    </button>
                  </div>
                </div>
              </div>
            ))}
          </div>
        </div>

        {/* Top Products */}
        <div className="bg-white rounded-lg shadow">
          <div className="px-6 py-4 border-b border-gray-200">
            <h3 className="text-lg font-medium text-gray-900">Top Products</h3>
          </div>
          <div className="p-6">
            <div className="space-y-4">
              {mockTopProducts.map((product, index) => (
                <div key={product.id} className="flex items-center justify-between">
                  <div className="flex items-center space-x-3">
                    <div className="w-8 h-8 bg-indigo-100 rounded-full flex items-center justify-center">
                      <span className="text-sm font-medium text-indigo-600">#{index + 1}</span>
                    </div>
                    <div>
                      <p className="text-sm font-medium text-gray-900">{product.name}</p>
                      <p className="text-xs text-gray-500">{product.sales} sales</p>
                    </div>
                  </div>
                  <div className="text-right">
                    <p className="text-sm font-medium text-gray-900">${product.revenue.toLocaleString()}</p>
                  </div>
                </div>
              ))}
            </div>
          </div>
        </div>
      </div>

      {/* Quick Actions */}
      <div className="bg-white rounded-lg shadow">
        <div className="px-6 py-4 border-b border-gray-200">
          <h3 className="text-lg font-medium text-gray-900">Quick Actions</h3>
        </div>
        <div className="p-6">
          <div className="grid grid-cols-1 md:grid-cols-3 gap-4">
            <button className="flex items-center justify-center p-4 border-2 border-dashed border-gray-300 rounded-lg hover:border-indigo-500 hover:bg-indigo-50 transition-colors">
              <div className="text-center">
                <ShoppingCartIcon className="w-8 h-8 text-gray-400 mx-auto mb-2" />
                <p className="text-sm font-medium text-gray-600">Add Product</p>
              </div>
            </button>
            <button className="flex items-center justify-center p-4 border-2 border-dashed border-gray-300 rounded-lg hover:border-indigo-500 hover:bg-indigo-50 transition-colors">
              <div className="text-center">
                <UserGroupIcon className="w-8 h-8 text-gray-400 mx-auto mb-2" />
                <p className="text-sm font-medium text-gray-600">Manage Users</p>
              </div>
            </button>
            <button className="flex items-center justify-center p-4 border-2 border-dashed border-gray-300 rounded-lg hover:border-indigo-500 hover:bg-indigo-50 transition-colors">
              <div className="text-center">
                <TrendingUpIcon className="w-8 h-8 text-gray-400 mx-auto mb-2" />
                <p className="text-sm font-medium text-gray-600">View Analytics</p>
              </div>
            </button>
          </div>
        </div>
      </div>
    </div>
  );
};

export default Dashboard;
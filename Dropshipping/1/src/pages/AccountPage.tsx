import { useState } from 'react';
import { useNavigate } from 'react-router-dom';
import { useAuth } from '../contexts/AuthContext';
import { Package, User, Heart, CreditCard, Bell, LogOut } from 'lucide-react';

const AccountPage = () => {
  const { user, logout } = useAuth();
  const navigate = useNavigate();
  const [activeTab, setActiveTab] = useState('profile');

  const handleLogout = () => {
    logout();
    navigate('/');
  };

  if (!user) {
    return null; // This should be handled by the ProtectedRoute component
  }

  return (
    <div className="container mx-auto px-4 py-8">
      <h1 className="mb-8 text-3xl font-bold">My Account</h1>

      <div className="grid grid-cols-1 gap-8 md:grid-cols-12">
        {/* Sidebar */}
        <div className="md:col-span-3">
          <div className="rounded-lg border border-gray-200 bg-white p-4">
            <div className="mb-6 flex items-center">
              <div className="flex h-12 w-12 items-center justify-center rounded-full bg-blue-100 text-blue-600">
                <User className="h-6 w-6" />
              </div>
              <div className="ml-3">
                <p className="font-medium">{user.name}</p>
                <p className="text-sm text-gray-600">{user.email}</p>
              </div>
            </div>

            <nav className="space-y-1">
              <button
                onClick={() => setActiveTab('profile')}
                className={`flex w-full items-center rounded-md px-3 py-2 text-left ${
                  activeTab === 'profile'
                    ? 'bg-blue-50 text-blue-600'
                    : 'text-gray-700 hover:bg-gray-50'
                }`}
              >
                <User className="mr-3 h-5 w-5" />
                <span>Profile</span>
              </button>

              <button
                onClick={() => setActiveTab('orders')}
                className={`flex w-full items-center rounded-md px-3 py-2 text-left ${
                  activeTab === 'orders'
                    ? 'bg-blue-50 text-blue-600'
                    : 'text-gray-700 hover:bg-gray-50'
                }`}
              >
                <Package className="mr-3 h-5 w-5" />
                <span>Orders</span>
              </button>

              <button
                onClick={() => setActiveTab('wishlist')}
                className={`flex w-full items-center rounded-md px-3 py-2 text-left ${
                  activeTab === 'wishlist'
                    ? 'bg-blue-50 text-blue-600'
                    : 'text-gray-700 hover:bg-gray-50'
                }`}
              >
                <Heart className="mr-3 h-5 w-5" />
                <span>Wishlist</span>
              </button>

              <button
                onClick={() => setActiveTab('payment')}
                className={`flex w-full items-center rounded-md px-3 py-2 text-left ${
                  activeTab === 'payment'
                    ? 'bg-blue-50 text-blue-600'
                    : 'text-gray-700 hover:bg-gray-50'
                }`}
              >
                <CreditCard className="mr-3 h-5 w-5" />
                <span>Payment Methods</span>
              </button>

              <button
                onClick={() => setActiveTab('notifications')}
                className={`flex w-full items-center rounded-md px-3 py-2 text-left ${
                  activeTab === 'notifications'
                    ? 'bg-blue-50 text-blue-600'
                    : 'text-gray-700 hover:bg-gray-50'
                }`}
              >
                <Bell className="mr-3 h-5 w-5" />
                <span>Notifications</span>
              </button>

              <button
                onClick={handleLogout}
                className="flex w-full items-center rounded-md px-3 py-2 text-left text-red-600 hover:bg-red-50"
              >
                <LogOut className="mr-3 h-5 w-5" />
                <span>Logout</span>
              </button>
            </nav>
          </div>
        </div>

        {/* Content */}
        <div className="md:col-span-9">
          <div className="rounded-lg border border-gray-200 bg-white p-6">
            {activeTab === 'profile' && (
              <div>
                <h2 className="mb-6 text-xl font-bold">Profile Information</h2>
                <form>
                  <div className="mb-6 grid grid-cols-1 gap-6 md:grid-cols-2">
                    <div>
                      <label htmlFor="fullName" className="mb-1 block text-sm font-medium">
                        Full Name
                      </label>
                      <input
                        type="text"
                        id="fullName"
                        defaultValue={user.name}
                        className="input w-full"
                      />
                    </div>
                    <div>
                      <label htmlFor="email" className="mb-1 block text-sm font-medium">
                        Email Address
                      </label>
                      <input
                        type="email"
                        id="email"
                        defaultValue={user.email}
                        className="input w-full"
                        disabled
                      />
                    </div>
                    <div>
                      <label htmlFor="phone" className="mb-1 block text-sm font-medium">
                        Phone Number
                      </label>
                      <input
                        type="tel"
                        id="phone"
                        defaultValue=""
                        placeholder="(123) 456-7890"
                        className="input w-full"
                      />
                    </div>
                    <div>
                      <label htmlFor="birthday" className="mb-1 block text-sm font-medium">
                        Date of Birth
                      </label>
                      <input type="date" id="birthday" className="input w-full" />
                    </div>
                  </div>

                  <h3 className="mb-4 mt-8 text-lg font-medium">Default Address</h3>
                  <div className="mb-6 grid grid-cols-1 gap-6 md:grid-cols-2">
                    <div className="md:col-span-2">
                      <label htmlFor="address" className="mb-1 block text-sm font-medium">
                        Street Address
                      </label>
                      <input type="text" id="address" className="input w-full" />
                    </div>
                    <div>
                      <label htmlFor="city" className="mb-1 block text-sm font-medium">
                        City
                      </label>
                      <input type="text" id="city" className="input w-full" />
                    </div>
                    <div>
                      <label htmlFor="state" className="mb-1 block text-sm font-medium">
                        State/Province
                      </label>
                      <input type="text" id="state" className="input w-full" />
                    </div>
                    <div>
                      <label htmlFor="zip" className="mb-1 block text-sm font-medium">
                        ZIP/Postal Code
                      </label>
                      <input type="text" id="zip" className="input w-full" />
                    </div>
                    <div>
                      <label htmlFor="country" className="mb-1 block text-sm font-medium">
                        Country
                      </label>
                      <select id="country" className="input w-full">
                        <option value="US">United States</option>
                        <option value="CA">Canada</option>
                        <option value="UK">United Kingdom</option>
                        <option value="AU">Australia</option>
                      </select>
                    </div>
                  </div>

                  <div className="mt-8 flex justify-end">
                    <button type="submit" className="btn btn-primary">
                      Save Changes
                    </button>
                  </div>
                </form>
              </div>
            )}

            {activeTab === 'orders' && (
              <div>
                <h2 className="mb-6 text-xl font-bold">Order History</h2>
                <div className="rounded-md bg-blue-50 p-4 text-blue-800">
                  <p>You haven't placed any orders yet.</p>
                </div>
              </div>
            )}

            {activeTab === 'wishlist' && (
              <div>
                <h2 className="mb-6 text-xl font-bold">My Wishlist</h2>
                <div className="rounded-md bg-blue-50 p-4 text-blue-800">
                  <p>Your wishlist is empty.</p>
                </div>
              </div>
            )}

            {activeTab === 'payment' && (
              <div>
                <h2 className="mb-6 text-xl font-bold">Payment Methods</h2>
                <div className="mb-6 rounded-md bg-blue-50 p-4 text-blue-800">
                  <p>You don't have any saved payment methods.</p>
                </div>
                <button className="btn btn-primary">Add Payment Method</button>
              </div>
            )}

            {activeTab === 'notifications' && (
              <div>
                <h2 className="mb-6 text-xl font-bold">Notification Preferences</h2>
                <div className="space-y-4">
                  <div className="flex items-center justify-between rounded-md border border-gray-200 p-4">
                    <div>
                      <h3 className="font-medium">Order Updates</h3>
                      <p className="text-sm text-gray-600">
                        Receive updates about your order status
                      </p>
                    </div>
                    <label className="relative inline-flex cursor-pointer items-center">
                      <input type="checkbox" defaultChecked className="peer sr-only" />
                      <div className="peer h-6 w-11 rounded-full bg-gray-200 after:absolute after:left-[2px] after:top-[2px] after:h-5 after:w-5 after:rounded-full after:border after:border-gray-300 after:bg-white after:transition-all after:content-[''] peer-checked:bg-blue-600 peer-checked:after:translate-x-full peer-focus:outline-none"></div>
                    </label>
                  </div>

                  <div className="flex items-center justify-between rounded-md border border-gray-200 p-4">
                    <div>
                      <h3 className="font-medium">Promotions</h3>
                      <p className="text-sm text-gray-600">
                        Receive emails about promotions and discounts
                      </p>
                    </div>
                    <label className="relative inline-flex cursor-pointer items-center">
                      <input type="checkbox" className="peer sr-only" />
                      <div className="peer h-6 w-11 rounded-full bg-gray-200 after:absolute after:left-[2px] after:top-[2px] after:h-5 after:w-5 after:rounded-full after:border after:border-gray-300 after:bg-white after:transition-all after:content-[''] peer-checked:bg-blue-600 peer-checked:after:translate-x-full peer-focus:outline-none"></div>
                    </label>
                  </div>

                  <div className="flex items-center justify-between rounded-md border border-gray-200 p-4">
                    <div>
                      <h3 className="font-medium">Product Updates</h3>
                      <p className="text-sm text-gray-600">
                        Receive updates on new products and features
                      </p>
                    </div>
                    <label className="relative inline-flex cursor-pointer items-center">
                      <input type="checkbox" defaultChecked className="peer sr-only" />
                      <div className="peer h-6 w-11 rounded-full bg-gray-200 after:absolute after:left-[2px] after:top-[2px] after:h-5 after:w-5 after:rounded-full after:border after:border-gray-300 after:bg-white after:transition-all after:content-[''] peer-checked:bg-blue-600 peer-checked:after:translate-x-full peer-focus:outline-none"></div>
                    </label>
                  </div>
                </div>
              </div>
            )}
          </div>
        </div>
      </div>
    </div>
  );
};

export default AccountPage;
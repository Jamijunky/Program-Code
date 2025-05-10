import React, { useState } from 'react';
import { useNavigate } from 'react-router-dom';
import { Check, CreditCard, Plus } from 'lucide-react';
import Button from '../components/ui/Button';
import { useCartStore } from '../stores/cartStore';

type FormStepType = 'shipping' | 'payment' | 'review';

const CheckoutPage: React.FC = () => {
  const [currentStep, setCurrentStep] = useState<FormStepType>('shipping');
  const [paymentMethod, setPaymentMethod] = useState<string>('credit-card');
  const [loading, setLoading] = useState(false);
  
  const { items, getTotal, clearCart } = useCartStore();
  const navigate = useNavigate();
  
  const subtotal = getTotal();
  const shippingCost = subtotal > 100 ? 0 : 10;
  const tax = subtotal * 0.08; // 8% tax rate
  const total = subtotal + shippingCost + tax;
  
  // Handle next step
  const handleNextStep = () => {
    if (currentStep === 'shipping') {
      setCurrentStep('payment');
    } else if (currentStep === 'payment') {
      setCurrentStep('review');
    }
  };
  
  // Handle previous step
  const handlePrevStep = () => {
    if (currentStep === 'payment') {
      setCurrentStep('shipping');
    } else if (currentStep === 'review') {
      setCurrentStep('payment');
    }
  };
  
  // Handle order submission
  const handlePlaceOrder = () => {
    setLoading(true);
    
    // Simulate order processing
    setTimeout(() => {
      clearCart();
      navigate('/orders?success=true');
    }, 1500);
  };
  
  return (
    <div className="bg-gray-50 min-h-screen py-8">
      <div className="container mx-auto px-4">
        <h1 className="text-2xl md:text-3xl font-bold text-gray-900 mb-8">Checkout</h1>
        
        {/* Progress Steps */}
        <div className="mb-8">
          <div className="flex items-center justify-center">
            <div className="flex items-center">
              <div className={`rounded-full h-8 w-8 flex items-center justify-center ${
                currentStep === 'shipping' ? 'bg-primary-700 text-white' : 'bg-primary-700 text-white'
              }`}>
                {currentStep === 'shipping' ? '1' : <Check size={16} />}
              </div>
              <div className={`text-sm font-medium ${
                currentStep === 'shipping' ? 'text-gray-900' : 'text-gray-500'
              } ml-2`}>
                Shipping
              </div>
            </div>
            
            <div className={`h-0.5 w-16 md:w-24 mx-2 ${
              currentStep === 'shipping' ? 'bg-gray-300' : 'bg-primary-700'
            }`}></div>
            
            <div className="flex items-center">
              <div className={`rounded-full h-8 w-8 flex items-center justify-center ${
                currentStep === 'payment' ? 'bg-primary-700 text-white' 
                : currentStep === 'review' ? 'bg-primary-700 text-white' 
                : 'bg-gray-300 text-gray-500'
              }`}>
                {currentStep === 'review' ? <Check size={16} /> : '2'}
              </div>
              <div className={`text-sm font-medium ${
                currentStep === 'payment' ? 'text-gray-900' : 'text-gray-500'
              } ml-2`}>
                Payment
              </div>
            </div>
            
            <div className={`h-0.5 w-16 md:w-24 mx-2 ${
              currentStep === 'review' ? 'bg-primary-700' : 'bg-gray-300'
            }`}></div>
            
            <div className="flex items-center">
              <div className={`rounded-full h-8 w-8 flex items-center justify-center ${
                currentStep === 'review' ? 'bg-primary-700 text-white' : 'bg-gray-300 text-gray-500'
              }`}>
                3
              </div>
              <div className={`text-sm font-medium ${
                currentStep === 'review' ? 'text-gray-900' : 'text-gray-500'
              } ml-2`}>
                Review
              </div>
            </div>
          </div>
        </div>
        
        <div className="flex flex-col lg:flex-row gap-8">
          {/* Form Section */}
          <div className="lg:w-2/3">
            <div className="bg-white rounded-lg shadow-sm overflow-hidden">
              {/* Shipping Information */}
              {currentStep === 'shipping' && (
                <div className="p-6">
                  <h2 className="text-lg font-medium text-gray-900 mb-6">Shipping Information</h2>
                  
                  <div className="grid grid-cols-1 md:grid-cols-2 gap-6">
                    <div>
                      <label htmlFor="first-name" className="block text-sm font-medium text-gray-700 mb-1">
                        First Name
                      </label>
                      <input
                        type="text"
                        id="first-name"
                        className="block w-full border-gray-300 rounded-md shadow-sm focus:ring-primary-500 focus:border-primary-500 sm:text-sm py-3 border"
                      />
                    </div>
                    <div>
                      <label htmlFor="last-name" className="block text-sm font-medium text-gray-700 mb-1">
                        Last Name
                      </label>
                      <input
                        type="text"
                        id="last-name"
                        className="block w-full border-gray-300 rounded-md shadow-sm focus:ring-primary-500 focus:border-primary-500 sm:text-sm py-3 border"
                      />
                    </div>
                    <div>
                      <label htmlFor="email" className="block text-sm font-medium text-gray-700 mb-1">
                        Email Address
                      </label>
                      <input
                        type="email"
                        id="email"
                        className="block w-full border-gray-300 rounded-md shadow-sm focus:ring-primary-500 focus:border-primary-500 sm:text-sm py-3 border"
                      />
                    </div>
                    <div>
                      <label htmlFor="phone" className="block text-sm font-medium text-gray-700 mb-1">
                        Phone Number
                      </label>
                      <input
                        type="tel"
                        id="phone"
                        className="block w-full border-gray-300 rounded-md shadow-sm focus:ring-primary-500 focus:border-primary-500 sm:text-sm py-3 border"
                      />
                    </div>
                    <div className="md:col-span-2">
                      <label htmlFor="address" className="block text-sm font-medium text-gray-700 mb-1">
                        Address
                      </label>
                      <input
                        type="text"
                        id="address"
                        className="block w-full border-gray-300 rounded-md shadow-sm focus:ring-primary-500 focus:border-primary-500 sm:text-sm py-3 border"
                      />
                    </div>
                    <div>
                      <label htmlFor="city" className="block text-sm font-medium text-gray-700 mb-1">
                        City
                      </label>
                      <input
                        type="text"
                        id="city"
                        className="block w-full border-gray-300 rounded-md shadow-sm focus:ring-primary-500 focus:border-primary-500 sm:text-sm py-3 border"
                      />
                    </div>
                    <div>
                      <label htmlFor="postal-code" className="block text-sm font-medium text-gray-700 mb-1">
                        Postal Code
                      </label>
                      <input
                        type="text"
                        id="postal-code"
                        className="block w-full border-gray-300 rounded-md shadow-sm focus:ring-primary-500 focus:border-primary-500 sm:text-sm py-3 border"
                      />
                    </div>
                    <div>
                      <label htmlFor="state" className="block text-sm font-medium text-gray-700 mb-1">
                        State / Province
                      </label>
                      <select
                        id="state"
                        className="block w-full border-gray-300 rounded-md shadow-sm focus:ring-primary-500 focus:border-primary-500 sm:text-sm py-3 border"
                      >
                        <option>Select state</option>
                        <option>California</option>
                        <option>New York</option>
                        <option>Texas</option>
                      </select>
                    </div>
                    <div>
                      <label htmlFor="country" className="block text-sm font-medium text-gray-700 mb-1">
                        Country
                      </label>
                      <select
                        id="country"
                        className="block w-full border-gray-300 rounded-md shadow-sm focus:ring-primary-500 focus:border-primary-500 sm:text-sm py-3 border"
                      >
                        <option>United States</option>
                        <option>Canada</option>
                        <option>United Kingdom</option>
                      </select>
                    </div>
                  </div>
                  
                  <div className="mt-8 flex justify-end">
                    <Button variant="primary" onClick={handleNextStep}>
                      Continue to Payment
                    </Button>
                  </div>
                </div>
              )}
              
              {/* Payment Information */}
              {currentStep === 'payment' && (
                <div className="p-6">
                  <h2 className="text-lg font-medium text-gray-900 mb-6">Payment Method</h2>
                  
                  <div className="space-y-4">
                    <div className="relative border rounded-md p-4 flex cursor-pointer bg-gray-50 border-primary-500">
                      <input
                        type="radio"
                        name="payment-method"
                        id="credit-card"
                        className="h-4 w-4 text-primary-700 focus:ring-primary-500 border-gray-300"
                        checked={paymentMethod === 'credit-card'}
                        onChange={() => setPaymentMethod('credit-card')}
                      />
                      <label htmlFor="credit-card" className="ml-3 flex flex-col cursor-pointer">
                        <span className="block text-sm font-medium text-gray-900">Credit / Debit Card</span>
                        <span className="block text-sm text-gray-500">Pay securely with your card</span>
                      </label>
                      <div className="absolute right-4 top-1/2 transform -translate-y-1/2">
                        <CreditCard size={24} className="text-gray-400" />
                      </div>
                    </div>
                    
                    <div className="relative border rounded-md p-4 flex cursor-pointer">
                      <input
                        type="radio"
                        name="payment-method"
                        id="paypal"
                        className="h-4 w-4 text-primary-700 focus:ring-primary-500 border-gray-300"
                        checked={paymentMethod === 'paypal'}
                        onChange={() => setPaymentMethod('paypal')}
                      />
                      <label htmlFor="paypal" className="ml-3 flex flex-col cursor-pointer">
                        <span className="block text-sm font-medium text-gray-900">PayPal</span>
                        <span className="block text-sm text-gray-500">Pay with your PayPal account</span>
                      </label>
                    </div>
                  </div>
                  
                  {paymentMethod === 'credit-card' && (
                    <div className="mt-6 space-y-6">
                      <div>
                        <label htmlFor="card-number" className="block text-sm font-medium text-gray-700 mb-1">
                          Card Number
                        </label>
                        <input
                          type="text"
                          id="card-number"
                          placeholder="1234 5678 9012 3456"
                          className="block w-full border-gray-300 rounded-md shadow-sm focus:ring-primary-500 focus:border-primary-500 sm:text-sm py-3 border"
                        />
                      </div>
                      
                      <div className="grid grid-cols-2 gap-6">
                        <div>
                          <label htmlFor="expiration" className="block text-sm font-medium text-gray-700 mb-1">
                            Expiration Date
                          </label>
                          <input
                            type="text"
                            id="expiration"
                            placeholder="MM / YY"
                            className="block w-full border-gray-300 rounded-md shadow-sm focus:ring-primary-500 focus:border-primary-500 sm:text-sm py-3 border"
                          />
                        </div>
                        <div>
                          <label htmlFor="cvc" className="block text-sm font-medium text-gray-700 mb-1">
                            CVC
                          </label>
                          <input
                            type="text"
                            id="cvc"
                            placeholder="123"
                            className="block w-full border-gray-300 rounded-md shadow-sm focus:ring-primary-500 focus:border-primary-500 sm:text-sm py-3 border"
                          />
                        </div>
                      </div>
                      
                      <div>
                        <label htmlFor="name-on-card" className="block text-sm font-medium text-gray-700 mb-1">
                          Name on Card
                        </label>
                        <input
                          type="text"
                          id="name-on-card"
                          className="block w-full border-gray-300 rounded-md shadow-sm focus:ring-primary-500 focus:border-primary-500 sm:text-sm py-3 border"
                        />
                      </div>
                    </div>
                  )}
                  
                  <div className="mt-8 flex justify-between">
                    <Button variant="outline" onClick={handlePrevStep}>
                      Back to Shipping
                    </Button>
                    <Button variant="primary" onClick={handleNextStep}>
                      Review Order
                    </Button>
                  </div>
                </div>
              )}
              
              {/* Order Review */}
              {currentStep === 'review' && (
                <div className="p-6">
                  <h2 className="text-lg font-medium text-gray-900 mb-6">Review Your Order</h2>
                  
                  <div className="mb-8">
                    <h3 className="text-sm font-medium text-gray-900 mb-2">Shipping Address</h3>
                    <div className="bg-gray-50 p-4 rounded-md">
                      <p className="text-gray-900">John Doe</p>
                      <p className="text-gray-600">123 Main St, Apt 4B</p>
                      <p className="text-gray-600">New York, NY 10001</p>
                      <p className="text-gray-600">United States</p>
                      <button className="text-primary-700 hover:text-primary-800 text-sm flex items-center mt-2">
                        <Plus size={14} className="mr-1" /> Add delivery instructions
                      </button>
                    </div>
                  </div>
                  
                  <div className="mb-8">
                    <h3 className="text-sm font-medium text-gray-900 mb-2">Payment Method</h3>
                    <div className="bg-gray-50 p-4 rounded-md flex items-center">
                      <CreditCard size={20} className="text-gray-500 mr-2" />
                      <div>
                        <p className="text-gray-900">Credit Card ending in 3456</p>
                        <p className="text-gray-600 text-sm">Expires 12/25</p>
                      </div>
                    </div>
                  </div>
                  
                  <div>
                    <h3 className="text-sm font-medium text-gray-900 mb-2">Order Items</h3>
                    <ul className="divide-y divide-gray-200 border-t border-b">
                      {items.map((item) => (
                        <li key={item.variantId} className="py-4 flex">
                          <div className="h-16 w-16 bg-gray-100 rounded overflow-hidden">
                            <img
                              src={item.image}
                              alt={item.title}
                              className="h-full w-full object-cover object-center"
                            />
                          </div>
                          <div className="ml-4 flex-1">
                            <div className="flex justify-between">
                              <h4 className="text-sm font-medium text-gray-900">{item.title}</h4>
                              <p className="text-sm font-medium text-gray-900">${(item.price * item.quantity).toFixed(2)}</p>
                            </div>
                            <div className="mt-1 flex text-sm">
                              <p className="text-gray-500">
                                {item.size && `Size: ${item.size}`} 
                                {item.color && item.size && ' / '} 
                                {item.color && `Color: ${item.color}`}
                              </p>
                              <p className="text-gray-500 ml-4">Qty: {item.quantity}</p>
                            </div>
                          </div>
                        </li>
                      ))}
                    </ul>
                  </div>
                  
                  <div className="mt-8 flex justify-between">
                    <Button variant="outline" onClick={handlePrevStep}>
                      Back to Payment
                    </Button>
                    <Button 
                      variant="primary" 
                      onClick={handlePlaceOrder}
                      loading={loading}
                    >
                      Place Order
                    </Button>
                  </div>
                </div>
              )}
            </div>
          </div>
          
          {/* Order Summary */}
          <div className="lg:w-1/3">
            <div className="bg-white rounded-lg shadow-sm overflow-hidden sticky top-20">
              <div className="p-6 border-b border-gray-200">
                <h2 className="text-lg font-medium text-gray-900">Order Summary</h2>
              </div>
              
              <div className="p-6 space-y-4">
                <div className="flex justify-between text-base">
                  <p className="text-gray-600">Subtotal ({items.length} {items.length === 1 ? 'item' : 'items'})</p>
                  <p className="text-gray-900 font-medium">${subtotal.toFixed(2)}</p>
                </div>
                <div className="flex justify-between text-base">
                  <p className="text-gray-600">Shipping</p>
                  <p className="text-gray-900 font-medium">
                    {shippingCost === 0 ? 'Free' : `$${shippingCost.toFixed(2)}`}
                  </p>
                </div>
                <div className="flex justify-between text-base">
                  <p className="text-gray-600">Taxes</p>
                  <p className="text-gray-900 font-medium">${tax.toFixed(2)}</p>
                </div>
                <div className="border-t border-gray-200 pt-4 flex justify-between text-base font-medium">
                  <p className="text-gray-900">Order total</p>
                  <p className="text-primary-700">${total.toFixed(2)}</p>
                </div>
                
                <div className="mt-4 bg-gray-50 p-4 rounded-md">
                  <div className="flex">
                    <div className="text-green-500 mr-2">
                      <Check size={20} />
                    </div>
                    <div>
                      <p className="text-sm font-medium text-gray-900">Free shipping on orders over $100</p>
                      <p className="text-xs text-gray-500 mt-1">Your order qualifies for free shipping!</p>
                    </div>
                  </div>
                </div>
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>
  );
};

export default CheckoutPage;
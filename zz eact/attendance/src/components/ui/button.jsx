import React from 'react'

const Button = ({ children, variant = 'default', onClick, className = '', size = 'normal' }) => {
  const variants = {
    default: 'bg-blue-500 text-white hover:bg-blue-600',
    secondary: 'bg-gray-200 text-gray-800 hover:bg-gray-300',
    destructive: 'bg-red-500 text-white hover:bg-red-600',
    outline: 'border border-gray-300 text-gray-800 hover:bg-gray-100',
    ghost: 'bg-transparent text-gray-800 hover:bg-gray-100',
    link: 'bg-transparent text-blue-500 hover:underline',
  }

  const sizes = {
    normal: 'px-4 py-2',
    small: 'px-2 py-1',
  }

  return (
    <button
      className={`rounded ${variants[variant]} ${sizes[size]} ${className}`}
      onClick={onClick}
    >
      {children}
    </button>
  )
}

export default Button
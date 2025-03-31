import React from 'react'

const Input = ({ value, onChange, className = '' }) => (
  <input
    type="text"
    value={value}
    onChange={onChange}
    className={`border border-gray-300 rounded px-4 py-2 ${className}`}
  />
)

export default Input
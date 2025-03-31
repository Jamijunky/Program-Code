import React from 'react'

const Card = ({ children, className = '' }) => (
  <div className={`bg-white rounded-lg shadow-md p-4 ${className}`}>
    {children}
  </div>
)

const CardHeader = ({ children, className = '' }) => (
  <div className={`border-b pb-2 ${className}`}>
    {children}
  </div>
)

const CardTitle = ({ children, className = '' }) => (
  <h2 className={`text-xl font-bold ${className}`}>
    {children}
  </h2>
)

const CardContent = ({ children, className = '' }) => (
  <div className={`pt-4 ${className}`}>
    {children}
  </div>
)

const CardFooter = ({ children, className = '' }) => (
  <div className={`border-t pt-2 ${className}`}>
    {children}
  </div>
)

export { Card, CardHeader, CardTitle, CardContent, CardFooter }
import { Link } from 'react-router-dom';

const categories = [
  { id: 'electronics', name: 'Electronics' },
  { id: 'clothing', name: 'Clothing' },
  { id: 'home', name: 'Home & Kitchen' },
  { id: 'beauty', name: 'Beauty' },
];

const NavMenu = () => {
  return (
    <>
      <Link to="/" className="text-gray-800 hover:text-blue-600">
        Home
      </Link>
      <div className="group relative">
        <Link to="/shop" className="flex items-center text-gray-800 hover:text-blue-600">
          Shop
        </Link>
        <div className="absolute left-0 z-10 mt-2 w-48 origin-top-left rounded-md bg-white p-2 shadow-lg opacity-0 invisible group-hover:opacity-100 group-hover:visible transition-all duration-300">
          {categories.map((category) => (
            <Link
              key={category.id}
              to={`/shop?category=${category.id}`}
              className="block rounded-md px-3 py-2 text-sm hover:bg-gray-100"
            >
              {category.name}
            </Link>
          ))}
        </div>
      </div>
      <Link to="/about" className="text-gray-800 hover:text-blue-600">
        About
      </Link>
      <Link to="/contact" className="text-gray-800 hover:text-blue-600">
        Contact
      </Link>
    </>
  );
};

export default NavMenu;
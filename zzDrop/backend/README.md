# Backend (Express + MongoDB)

## Setup
1. `cd backend`
2. `npm install`
3. Create `.env` file (see `.env.example`)
4. `npm run dev`

## Features
- REST API for products, users, orders, reviews
- JWT authentication
- Stripe/Razorpay integration
- Dropshipping supplier integration (AliExpress, Spocket, etc.)
- Admin dashboard endpoints
- Email notifications
- Swagger docs

---

## Scripts
- `npm run dev` - Start in dev mode
- `npm run start` - Start in prod mode
- `npm run lint` - Lint code
- `npm run test` - Run tests

---

## Folder Structure
- `/models` - Mongoose models
- `/routes` - Express routes
- `/controllers` - Business logic
- `/middleware` - Auth, error handling, etc.
- `/utils` - Utilities
- `/jobs` - Scheduled/queued jobs
- `/config` - Config files

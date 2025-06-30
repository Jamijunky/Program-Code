import { Server } from 'socket.io';

let io;
export function initSocket(server) {
  io = new Server(server, { cors: { origin: '*' } });
  io.on('connection', (socket) => {
    // For admin dashboard: join admin room
    socket.on('joinAdmin', () => {
      socket.join('admins');
    });
    // For user order updates: join user room
    socket.on('joinUser', (userId) => {
      socket.join(`user_${userId}`);
    });
  });
  return io;
}

export function getIO() {
  if (!io) throw new Error('Socket.io not initialized!');
  return io;
}

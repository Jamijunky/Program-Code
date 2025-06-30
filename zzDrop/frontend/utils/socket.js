import { io } from 'socket.io-client';

let socket;
export function getSocket() {
  if (!socket) {
    socket = io(process.env.NEXT_PUBLIC_API_URL.replace(/^http/, 'ws'));
  }
  return socket;
}

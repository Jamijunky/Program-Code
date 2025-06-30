import AdminLog from '../models/AdminLog.js';

export default async function logAdminAction({ admin, action, targetType, targetId, details }) {
  try {
    await AdminLog.create({
      admin,
      action,
      targetType,
      targetId,
      details
    });
  } catch (e) {
    // Do not block main flow on logging error
    console.error('AdminLog error:', e.message);
  }
}

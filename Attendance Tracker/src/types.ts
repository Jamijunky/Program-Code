export interface StudentRow {
  rollNo: string;
  studentName: string;
  attendance: string[];
  totalPresents: number;
  totalLeaves: number;
  attendancePercentage: number;
  originalAttendance: string[];
}

export interface ChangeLog {
  timestamp: string;
  description: string;
}

export interface Notification {
  show: boolean;
  message: string;
  type: 'success' | 'error' | 'info' | 'warning';
}

export type ChangedCells = Record<string, boolean>;

export interface CellChangeEvent extends React.ChangeEvent<HTMLSelectElement> {
  target: HTMLSelectElement;
}

export interface FileInputEvent extends React.ChangeEvent<HTMLInputElement> {
  target: HTMLInputElement & {
    files: FileList;
  };
}

export interface SavedData {
  rows: StudentRow[];
  columns: string[];
  changeHistory: ChangeLog[];
  description: string;
}

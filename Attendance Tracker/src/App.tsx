import { useState, useEffect, useCallback } from 'react';
import { Button } from './components/ui/button';
import { Card, CardContent, CardHeader, CardTitle } from './components/ui/card';
import { Input } from './components/ui/input';
import { Calendar, Delete, Download, Upload, Search, Plus, X, Award } from "lucide-react";
import { format } from 'date-fns';
import { motion, AnimatePresence } from 'framer-motion';
import DatePicker from 'react-datepicker';
import "react-datepicker/dist/react-datepicker.css";
import { StudentRow, Notification, FileInputEvent, SavedData } from './types';

function App(): JSX.Element {
  const [rows, setRows] = useState<StudentRow[]>([]);
  const [columns, setColumns] = useState<string[]>([]);
  const [selectedDate, setSelectedDate] = useState<Date>(new Date());
  const [showDatePicker, setShowDatePicker] = useState<boolean>(false);
  const [showHistory, setShowHistory] = useState<boolean>(false);
  const [searchQuery, setSearchQuery] = useState<string>('');
  const [isLoading, setIsLoading] = useState<boolean>(false);
  const [notification, setNotification] = useState<Notification>({ show: false, message: '', type: 'success' });
  const [description, setDescription] = useState<string>('');

  // Update table width on mount and window resize
  useEffect(() => {
    const updateTableWidth = () => {
    };
    updateTableWidth();
    window.addEventListener('resize', updateTableWidth);
    return () => window.removeEventListener('resize', updateTableWidth);
  }, []);

  const showNotification = useCallback((message: string, type: Notification['type'] = 'success'): void => {
    setNotification({ show: true, message, type });
    setTimeout(() => setNotification({ show: false, message: '', type: 'success' }), 3000);
  }, []);

  useEffect(() => {
    setIsLoading(true);
    try {
      const savedData = localStorage.getItem('attendanceData');
      if (savedData) {
        const data = JSON.parse(savedData) as SavedData;
        if (data.rows && data.columns) {
          setRows(data.rows);
          setColumns(data.columns);
          setDescription(data.description || '');
          showNotification('Data loaded successfully');
        }
      }
    } catch (error) {
      console.error('Error loading data:', error);
      showNotification('Error loading data', 'error');
      localStorage.removeItem('attendanceData');
    } finally {
      setIsLoading(false);
    }
  }, [showNotification]);

  const addRow = (): void => {
    const newRow: StudentRow = {
      rollNo: `${rows.length + 1}`,
      studentName: `Student ${rows.length + 1}`,
      attendance: Array(columns.length).fill(''),
      totalPresents: 0,
      totalLeaves: 0,
      attendancePercentage: 0,
      originalAttendance: Array(columns.length).fill(''),
    };
    setRows([...rows, newRow]);
    showNotification(`Added row for ${newRow.studentName}`);
  };

  const handleCellChange = (rowIndex: number, colIndex: number, value: string): void => {
    const updatedRows = rows.map((row: StudentRow, i: number) => {
      if (i === rowIndex) {
        const newAttendance = [...row.attendance];
        newAttendance[colIndex] = value;
        const { totalPresents, totalLeaves, attendancePercentage } = calculateSummary(newAttendance);
        return { ...row, attendance: newAttendance, totalPresents, totalLeaves, attendancePercentage };
      }
      return row;
    });
    setRows(updatedRows);
    showNotification(`Updated attendance for ${rows[rowIndex].studentName} on ${columns[colIndex]}`);
  };

  const calculateSummary = (attendance: string[]): { totalPresents: number; totalLeaves: number; attendancePercentage: number } => {
    const totalPresents = attendance.filter(cell => cell === 'Present').length;
    const totalLeaves = attendance.filter(cell => cell === 'Leave').length;
    const attendancePercentage = (totalPresents / attendance.length) * 100 || 0;
    return { totalPresents, totalLeaves, attendancePercentage };
  };

  const handleSave = (): void => {
    const updatedRows = rows.map(row => ({
      ...row,
      originalAttendance: [...row.attendance],
    }));
    setRows(updatedRows);
    localStorage.setItem(
      'attendanceData',
      JSON.stringify({ rows: updatedRows, columns, description })
    );
    showNotification('Changes saved successfully');
  };

  const handleClear = (): void => {
    if (confirm('Are you sure you want to clear all data? This cannot be undone.')) {
      localStorage.removeItem('attendanceData');
      setRows([]);
      setColumns([]);
      setDescription('');
      showNotification('All data cleared');
    }
  };

  const handleStudentNameChange = (rowIndex: number, newName: string): void => {
    const updatedRows = rows.map((row, i) => {
      if (i === rowIndex) {
        return { ...row, studentName: newName };
      }
      return row;
    });
    setRows(updatedRows);
    showNotification(`Updated student name to ${newName}`);
  };

  const handleRollNoChange = (rowIndex: number, newRollNo: string): void => {
    const updatedRows = rows.map((row, i) => {
      if (i === rowIndex) {
        return { ...row, rollNo: newRollNo };
      }
      return row;
    });
    setRows(updatedRows);
    showNotification(`Updated roll no to ${newRollNo}`);
  };

  const deleteRow = (rowIndex: number): void => {
    const studentName = rows[rowIndex].studentName;
    const updatedRows = rows.filter((_, i) => i !== rowIndex);
    setRows(updatedRows);
    showNotification(`Removed ${studentName}`);
  };

  const deleteColumn = (colIndex: number): void => {
    const date = columns[colIndex];
    const updatedColumns = columns.filter((_, i) => i !== colIndex);
    const updatedRows = rows.map(row => ({
      ...row,
      attendance: row.attendance.filter((_, i) => i !== colIndex),
      originalAttendance: row.originalAttendance.filter((_, i) => i !== colIndex),
    }));
    setColumns(updatedColumns);
    setRows(updatedRows);
    showNotification(`Removed date column ${date}`);
  };

  const exportToCSV = (): void => {
    const descriptionLine = description ? `# ${description.replace(/\n/g, ' ')}` : '';
    const headers = ['Roll No', 'Student Name', ...columns, 'Total Presents', 'Total Leaves', 'Attendance %'];
    const csvData = rows.map(row => [
      row.rollNo,
      row.studentName,
      ...row.attendance,
      row.totalPresents,
      row.totalLeaves,
      row.attendancePercentage,
    ]);

    const csvContent = [
      descriptionLine,
      headers.join(','),
      ...csvData.map(row => row.join(',')),
    ].filter(Boolean).join('\n');

    const blob = new Blob([csvContent], { type: 'text/csv;charset=utf-8;' });
    const link = document.createElement('a');
    const url = URL.createObjectURL(blob);
    link.setAttribute('href', url);
    link.setAttribute('download', 'attendance.csv');
    document.body.appendChild(link);
    link.click();
    document.body.removeChild(link);
  };

  const importFromCSV = (event: FileInputEvent): void => {
    const file = event.target.files[0];
    if (!file) return;

    const reader = new FileReader();
    reader.onload = (e: ProgressEvent<FileReader>) => {
      if (!e.target?.result) return;
      const content = e.target.result;
      if (typeof content !== 'string') return;

      const lines = content.split('\n');
      
      let startIndex = 0;
      if (lines[0].startsWith('#')) {
        setDescription(lines[0].substring(2)); // Remove '# ' prefix
        startIndex = 1;
      }

      if (lines.length < startIndex + 2) return;

      const headers = lines[startIndex].split(',');
      const newColumns = headers.slice(2, -3);
      const newRows = lines.slice(startIndex + 1).map((line: string) => {
        if (!line.trim()) return null; // Skip empty lines
        const values = line.split(',');
        const attendance = values.slice(2, -3);
        return {
          rollNo: values[0],
          studentName: values[1],
          attendance,
          totalPresents: parseInt(values[values.length - 3]) || 0,
          totalLeaves: parseInt(values[values.length - 2]) || 0,
          attendancePercentage: parseFloat(values[values.length - 1]) || 0,
          originalAttendance: [...attendance],
        };
      }).filter((row): row is StudentRow => row !== null);

      setColumns(newColumns);
      setRows(newRows);
      showNotification('Data imported successfully');
    };
    reader.readAsText(file);
  };

  if (isLoading) {
    return (
      <div className="flex items-center justify-center h-screen">
        <div className="animate-spin rounded-full h-32 w-32 border-b-2 border-gray-900"></div>
      </div>
    );
  }

  const topStudents = [...rows]
    .sort((a, b) => b.attendancePercentage - a.attendancePercentage)
    .slice(0, 3);

  return (
    <div className="container mx-auto p-4">
      <div className="relative">
        {notification.show && (
          <div 
            className={`fixed top-4 right-4 p-4 rounded-lg shadow-lg ${
              notification.type === 'error' ? 'bg-red-500' : 'bg-green-500'
            } text-white z-50`}
            role="alert"
          >
            {notification.message}
          </div>
        )}
        <div className="max-w-7xl mx-auto space-y-6">
          <Card>
            <CardHeader>
              <CardTitle className="text-3xl">Advanced Attendance Tracker</CardTitle>
              <div className="mt-4 relative">
                <textarea
                  id="description"
                  rows={2}
                  className="w-full px-4 py-3 text-sm text-gray-600 bg-gray-50/50 border-0 rounded-lg focus:outline-none focus:ring-1 focus:ring-gray-200 transition-all duration-200 placeholder:text-gray-400 resize-none"
                  placeholder="✏️ Add class details, semester, or any other information about this tracker..."
                  value={description}
                  onChange={(e) => setDescription(e.target.value)}
                />
              </div>
            </CardHeader>
            <CardContent>
              <div className="grid grid-cols-1 md:grid-cols-3 gap-4 mb-6">
                {topStudents.map((student, index) => (
                  <div key={index} className="bg-white rounded-lg shadow-sm p-4 border">
                    <div className="flex items-center space-x-3">
                      <Award className={`w-8 h-8 ${
                        index === 0 ? 'text-yellow-400' :
                        index === 1 ? 'text-gray-400' : 'text-orange-400'
                      }`} />
                      <div>
                        <h3 className="font-semibold">{student.studentName}</h3>
                        <p className="text-sm text-gray-500">
                          {student.attendancePercentage.toFixed(1)}% Attendance
                        </p>
                      </div>
                    </div>
                  </div>
                ))}
              </div>

              <div className="flex flex-wrap gap-3 mb-6">
                <Button onClick={addRow} className="bg-blue-500 hover:bg-blue-600">
                  <Plus className="mr-2 h-4 w-4" /> Add Student
                </Button>
                <Button onClick={() => setShowDatePicker(true)} className="bg-green-500 hover:bg-green-600">
                  <Calendar className="mr-2 h-4 w-4" /> Add Date
                </Button>
                <Button onClick={handleSave} className="bg-purple-500 hover:bg-purple-600">
                  Save Changes
                </Button>
                <input
                  type="file"
                  accept=".csv"
                  onChange={importFromCSV}
                  className="hidden"
                  id="csvInput"
                />
                <Button
                  onClick={() => {
                    const input = document.getElementById('csvInput') as HTMLInputElement | null;
                    input?.click();
                  }}
                  className="bg-indigo-500 hover:bg-indigo-600"
                >
                  <Upload className="mr-2 h-4 w-4" /> Import CSV
                </Button>
                <Button onClick={exportToCSV} className="bg-violet-500 hover:bg-violet-600">
                  <Download className="mr-2 h-4 w-4" /> Export CSV
                </Button>
                <Button
                  onClick={() => setShowHistory(!showHistory)}
                  className="bg-gray-500 hover:bg-gray-600"
                >
                  {showHistory ? 'Hide History' : 'Show History'}
                </Button>
                <Button onClick={handleClear} variant="outline" size="sm">
                  <Delete className="h-4 w-4 mr-2" />
                  Clear All
                </Button>
              </div>

              <div className="overflow-x-auto bg-white rounded-lg shadow">
                <table className="w-full">
                  <thead>
                    <tr className="bg-gray-50">
                      <th className="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider w-20">
                        Roll No
                      </th>
                      <th className="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider w-64">
                        Student Name
                      </th>
                      {columns.map((date, colIndex) => (
                        <th key={colIndex} className="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider w-32">
                          <div className="flex items-center justify-between">
                            <span>{date}</span>
                            <Button
                              variant="ghost"
                              size="sm"
                              onClick={() => deleteColumn(colIndex)}
                              className="text-red-500 hover:text-red-700 opacity-0 group-hover:opacity-100 transition-opacity"
                            >
                              <X className="h-4 w-4" />
                            </Button>
                          </div>
                        </th>
                      ))}
                      <th className="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider w-24">
                        Present
                      </th>
                      <th className="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider w-24">
                        Leave
                      </th>
                      <th className="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider w-32">
                        Attendance %
                      </th>
                      <th className="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider w-24">
                        Actions
                      </th>
                    </tr>
                  </thead>
                  <tbody>
                    {rows.map((row, rowIndex) => (
                      <tr key={rowIndex}>
                        <td className="px-6 py-4 whitespace-nowrap">
                          <Input
                            value={row.rollNo}
                            onChange={(e) => handleRollNoChange(rowIndex, e.target.value)}
                          />
                        </td>
                        <td className="px-6 py-4 whitespace-nowrap">
                          <Input
                            value={row.studentName}
                            onChange={(e) => handleStudentNameChange(rowIndex, e.target.value)}
                          />
                        </td>
                        {row.attendance.map((cell, colIndex) => (
                          <td key={colIndex} className="px-6 py-4 whitespace-nowrap">
                            <select
                              value={cell}
                              onChange={(e) => handleCellChange(rowIndex, colIndex, e.target.value)}
                            >
                              <option value="">Not marked</option>
                              <option value="Present">Present</option>
                              <option value="Leave">Leave</option>
                            </select>
                          </td>
                        ))}
                        <td className="px-6 py-4 whitespace-nowrap text-center font-medium text-green-600">
                          {row.totalPresents}
                        </td>
                        <td className="px-6 py-4 whitespace-nowrap text-center font-medium text-yellow-600">
                          {row.totalLeaves}
                        </td>
                        <td className="px-6 py-4 whitespace-nowrap text-center">
                          <span className={`inline-flex items-center px-2.5 py-0.5 rounded-full text-xs font-medium ${
                            row.attendancePercentage >= 90 ? 'bg-green-100 text-green-800' :
                            row.attendancePercentage >= 75 ? 'bg-yellow-100 text-yellow-800' :
                            'bg-red-100 text-red-800'
                          }`}>
                            {row.attendancePercentage.toFixed(1)}%
                          </span>
                        </td>
                        <td className="px-6 py-4 whitespace-nowrap text-right">
                          <Button
                            variant="ghost"
                            size="sm"
                            onClick={() => deleteRow(rowIndex)}
                            className="text-red-500 hover:text-red-700"
                          >
                            <Delete className="h-4 w-4" />
                          </Button>
                        </td>
                      </tr>
                    ))}
                    <tr className="bg-gray-100 font-semibold">
                      <td className="px-6 py-4 whitespace-nowrap">
                        Total
                      </td>
                      <td className="px-6 py-4 whitespace-nowrap"></td>
                      {columns.map((_, colIndex) => (
                        <td key={colIndex} className="px-6 py-4 whitespace-nowrap text-center">
                          {rows.filter(row => row.attendance[colIndex] === 'Present').length}
                        </td>
                      ))}
                      <td colSpan={4}></td>
                    </tr>
                  </tbody>
                </table>
              </div>
            </CardContent>
          </Card>

          <AnimatePresence>
            {showHistory && (
              <motion.div
                initial={{ opacity: 0, y: 20 }}
                animate={{ opacity: 1, y: 0 }}
                exit={{ opacity: 0, y: 20 }}
              >
                <Card>
                  <CardHeader>
                    <div className="flex items-center justify-between">
                      <CardTitle>Change History</CardTitle>
                      <div className="flex items-center space-x-4">
                        <div className="relative">
                          <Search className="absolute left-3 top-1/2 transform -translate-y-1/2 text-gray-400 h-4 w-4" />
                          <Input
                            placeholder="Search history..."
                            value={searchQuery}
                            onChange={(e) => setSearchQuery(e.target.value)}
                            className="pl-10"
                          />
                        </div>
                        <Button
                          variant="ghost"
                          size="sm"
                          onClick={() => setShowHistory(false)}
                        >
                          <X className="h-4 w-4" />
                        </Button>
                      </div>
                    </div>
                  </CardHeader>
                  <CardContent>
                    <div className="space-y-2 max-h-96 overflow-y-auto">
                    </div>
                  </CardContent>
                </Card>
              </motion.div>
            )}
          </AnimatePresence>

          <AnimatePresence>
            {showDatePicker && (
              <motion.div
                initial={{ opacity: 0 }}
                animate={{ opacity: 1 }}
                exit={{ opacity: 0 }}
                className="fixed inset-0 bg-black bg-opacity-50 flex items-center justify-center z-50"
              >
                <motion.div
                  initial={{ scale: 0.9 }}
                  animate={{ scale: 1 }}
                  exit={{ scale: 0.9 }}
                  className="bg-white p-6 rounded-lg shadow-xl"
                >
                  <h3 className="text-lg font-medium mb-4">Select Date</h3>
                  <DatePicker
                    selected={selectedDate}
                    onChange={(date: Date | null) => {
                      if (date) {
                        setSelectedDate(date);
                        const newDate = format(date, 'dd/MM/yy');
                        if (!columns.includes(newDate)) {
                          setColumns([...columns, newDate]);
                          const updatedRows = rows.map(row => ({
                            ...row,
                            attendance: [...row.attendance, ''],
                            originalAttendance: [...row.originalAttendance, ''],
                          }));
                          setRows(updatedRows);
                          showNotification(`Added column for ${newDate}`);
                        }
                        setShowDatePicker(false);
                      }
                    }}
                    inline
                  />
                  <div className="flex justify-end mt-4">
                    <Button
                      variant="ghost"
                      onClick={() => setShowDatePicker(false)}
                    >
                      Cancel
                    </Button>
                  </div>
                </motion.div>
              </motion.div>
            )}
          </AnimatePresence>
        </div>
      </div>
    </div>
  );
}

export default App;
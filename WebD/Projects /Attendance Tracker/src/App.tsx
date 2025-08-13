import { useState, useEffect, useCallback, useRef } from 'react';
import { Button } from './components/ui/button';
import { Card, CardContent, CardHeader, CardTitle } from './components/ui/card';
import { Input } from './components/ui/input';
import { Calendar, Delete, Download, Upload, Search, Plus, X, Award, Save, Loader2, History, Trash2 } from "lucide-react";
import { format } from 'date-fns';
import { motion, AnimatePresence } from 'framer-motion';
import DatePicker from 'react-datepicker';
import "react-datepicker/dist/react-datepicker.css";
import { StudentRow, Notification, FileInputEvent, SavedData } from './types';
import { useHotkeys } from 'react-hotkeys-hook';

function App(): JSX.Element {
  const [rows, setRows] = useState<StudentRow[]>([]);
  const [columns, setColumns] = useState<string[]>([]);
  const [selectedDate, setSelectedDate] = useState<Date>(new Date());
  const [showDatePicker, setShowDatePicker] = useState<boolean>(false);
  const [showHistory, setShowHistory] = useState<boolean>(false);
  const [isLoading, setIsLoading] = useState<boolean>(false);
  const [notification, setNotification] = useState<Notification>({ show: false, message: '', type: 'success' });
  const [description, setDescription] = useState<string>('');
  const [isSaving, setIsSaving] = useState<boolean>(false);
  const [lastSaved, setLastSaved] = useState<string>('');
  const [history, setHistory] = useState<Array<{ action: string; timestamp: string }>>([]);
  const tableRef = useRef<HTMLDivElement>(null);
  const fileInputRef = useRef<HTMLInputElement>(null);

  // Update table width on mount and window resize
  useEffect(() => {
    const updateTableWidth = () => {
    };
    updateTableWidth();
    window.addEventListener('resize', updateTableWidth);
    return () => window.removeEventListener('resize', updateTableWidth);
  }, []);

  // Load saved data including history
  useEffect(() => {
    setIsLoading(true);
    try {
      const savedData = localStorage.getItem('attendanceData');
      const savedHistory = localStorage.getItem('attendanceHistory');
      
      if (savedData) {
        const data = JSON.parse(savedData) as SavedData;
        if (data.rows && data.columns) {
          setRows(data.rows);
          setColumns(data.columns);
          setDescription(data.description || '');
          showNotification('Data loaded successfully');
        }
      }

      if (savedHistory) {
        setHistory(JSON.parse(savedHistory));
      }
    } catch (error) {
      console.error('Error loading data:', error);
      showNotification('Error loading data', 'error');
    } finally {
      setIsLoading(false);
    }
  }, []);

  const showNotification = useCallback((message: string, type: Notification['type'] = 'success'): void => {
    setNotification({ show: true, message, type });
    setTimeout(() => setNotification({ show: false, message: '', type: 'success' }), 3000);
  }, []);

  const addToHistory = (action: string): void => {
    const timestamp = format(new Date(), 'dd/MM/yy HH:mm:ss');
    const newHistory = [{ action, timestamp }, ...history];
    setHistory(newHistory);
    localStorage.setItem('attendanceHistory', JSON.stringify(newHistory));
  };

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
    addToHistory(`Added row for ${newRow.studentName}`);
  };

  const handleCellChange = (rowIndex: number, colIndex: number, value: string): void => {
    const updatedRows = rows.map((row: StudentRow, i: number) => {
      if (i === rowIndex) {
        const newAttendance = [...row.attendance];
        newAttendance[colIndex] = value;
        const { totalPresents, totalLeaves, attendancePercentage } = calculateSummary(newAttendance);
        return { 
          ...row, 
          attendance: newAttendance,
          totalPresents,
          totalLeaves,
          attendancePercentage
        };
      }
      return row;
    });
    setRows(updatedRows);
    showNotification(`Updated attendance for ${rows[rowIndex].studentName} on ${columns[colIndex]}`);
    addToHistory(`Updated attendance for ${rows[rowIndex].studentName} on ${columns[colIndex]} to ${value}`);
  };

  const calculateSummary = (attendance: string[]): { totalPresents: number; totalLeaves: number; attendancePercentage: number } => {
    const totalClasses = attendance.length;
    const totalPresents = attendance.filter(cell => cell === 'Present').length;
    const totalLeaves = 0; // Removing leave count
    const attendancePercentage = totalClasses > 0 ? (totalPresents / totalClasses) * 100 : 0;
    return { totalPresents, totalLeaves, attendancePercentage };
  };

  const handleSave = async (): Promise<void> => {
    setIsSaving(true);
    try {
      const updatedRows = rows.map(row => ({
        ...row,
        originalAttendance: [...row.attendance]
      }));
      
      const dataToSave: SavedData = {
        rows: updatedRows,
        columns,
        description,
        lastModified: new Date().toISOString()
      };
      
      await new Promise(resolve => setTimeout(resolve, 500)); // Simulate network delay
      localStorage.setItem('attendanceData', JSON.stringify(dataToSave));
      setRows(updatedRows);
      setLastSaved(format(new Date(), 'HH:mm:ss'));
      showNotification('Changes saved successfully');
      addToHistory('Saved changes');
    } catch (error) {
      console.error('Error saving data:', error);
      showNotification('Error saving changes', 'error');
    } finally {
      setIsSaving(false);
    }
  };

  const handleClear = async (): Promise<void> => {
    if (window.confirm('Are you sure you want to clear all data? This action cannot be undone.')) {
      setIsLoading(true);
      try {
        setRows([]);
        setColumns([]);
        setDescription('');
        setHistory([]);
        localStorage.removeItem('attendanceData');
        localStorage.removeItem('attendanceHistory');
        showNotification('All data cleared successfully');
      } catch (error) {
        console.error('Error clearing data:', error);
        showNotification('Error clearing data', 'error');
      } finally {
        setIsLoading(false);
      }
    }
  };

  const exportToCSV = (): void => {
    try {
      // Create CSV content
      const headers = ['Roll No', 'Student Name', ...columns, 'Total Present', 'Total Leave', 'Attendance %'];
      const csvContent = [
        headers.join(','),
        ...rows.map(row => [
          row.rollNo,
          `"${row.studentName}"`,
          ...row.attendance,
          row.totalPresents,
          row.totalLeaves,
          `${row.attendancePercentage.toFixed(1)}%`
        ].join(','))
      ].join('\n');

      // Create and download file
      const blob = new Blob([csvContent], { type: 'text/csv;charset=utf-8;' });
      const link = document.createElement('a');
      const url = URL.createObjectURL(blob);
      link.setAttribute('href', url);
      link.setAttribute('download', `attendance_${format(new Date(), 'dd_MM_yy')}.csv`);
      document.body.appendChild(link);
      link.click();
      document.body.removeChild(link);
      
      showNotification('CSV exported successfully');
      addToHistory('Exported data to CSV');
    } catch (error) {
      console.error('Error exporting CSV:', error);
      showNotification('Error exporting CSV', 'error');
    }
  };

  const importFromCSV = (event: FileInputEvent): void => {
    const file = event.target.files?.[0];
    if (!file) return;

    const reader = new FileReader();
    reader.onload = (e: ProgressEvent<FileReader>) => {
      try {
        const text = e.target?.result as string;
        const lines = text.split('\n');
        const headers = lines[0].split(',');
        const dates = headers.slice(2, -3);
        
        const newRows: StudentRow[] = lines.slice(1).map(line => {
          const values = line.split(',');
          const attendance = values.slice(2, 2 + dates.length);
          
          return {
            rollNo: values[0],
            studentName: values[1].replace(/"/g, ''),
            attendance,
            originalAttendance: [...attendance],
            totalPresents: attendance.filter(a => a === 'Present').length,
            totalLeaves: attendance.filter(a => a === 'Absent').length,
            attendancePercentage: (attendance.filter(a => a === 'Present').length / attendance.length) * 100
          };
        });

        setColumns(dates);
        setRows(newRows);
        if (fileInputRef.current) {
          fileInputRef.current.value = '';
        }
        showNotification('CSV imported successfully');
        addToHistory('Imported data from CSV');
      } catch (error) {
        console.error('Error parsing CSV:', error);
        showNotification('Error importing CSV. Please check the file format.', 'error');
      }
    };
    reader.readAsText(file);
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
    addToHistory(`Updated student name to ${newName}`);
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
    addToHistory(`Updated roll no to ${newRollNo}`);
  };

  const deleteRow = (rowIndex: number): void => {
    const studentName = rows[rowIndex].studentName;
    const updatedRows = rows.filter((_, i) => i !== rowIndex);
    setRows(updatedRows);
    showNotification(`Removed ${studentName}`);
    addToHistory(`Removed ${studentName}`);
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
    addToHistory(`Removed date column ${date}`);
  };

  // Keyboard shortcuts
  useHotkeys('ctrl+s, cmd+s', (e) => {
    e.preventDefault();
    handleSave();
  });

  useHotkeys('ctrl+n, cmd+n', (e) => {
    e.preventDefault();
    addRow();
  });

  if (isLoading) {
    return (
      <div className="flex items-center justify-center h-screen">
        <Loader2 className="h-8 w-8 animate-spin" />
      </div>
    );
  }

  const topStudents = [...rows]
    .sort((a, b) => b.attendancePercentage - a.attendancePercentage)
    .slice(0, 3);

  return (
    <div className="container mx-auto px-4 py-8">
      <Card className="mb-6">
        <CardHeader>
          <div className="flex flex-col md:flex-row md:items-center justify-between gap-4">
            <div>
              <CardTitle className="text-2xl font-bold">Attendance Tracker</CardTitle>
              <p className="text-sm text-gray-500 mt-1">
                {rows.length} students • {columns.length} days
                {lastSaved && ` • Last saved at ${lastSaved}`}
              </p>
              {rows.length > 0 && (
                <div className="mt-4 grid grid-cols-1 sm:grid-cols-3 gap-4">
                  {rows
                    .slice()
                    .sort((a, b) => b.attendancePercentage - a.attendancePercentage)
                    .slice(0, 3)
                    .map((student, index) => (
                      <div key={index} className="flex items-center gap-3 p-3 bg-white rounded-lg border shadow-sm">
                        <div className={`flex items-center justify-center w-8 h-8 rounded-full text-white ${
                          index === 0 ? 'bg-yellow-400' :
                          index === 1 ? 'bg-gray-400' :
                          'bg-amber-600'
                        }`}>
                          {index + 1}
                        </div>
                        <div className="flex-1 min-w-0">
                          <p className="text-sm font-medium text-gray-900 truncate">
                            {student.studentName}
                          </p>
                          <div className="flex items-center gap-2">
                            <div className="text-xs text-gray-500">
                              Present: {student.totalPresents}/{columns.length}
                            </div>
                            <div className={`text-xs font-medium px-1.5 py-0.5 rounded-full ${
                              student.attendancePercentage >= 75 ? 'bg-green-100 text-green-800' :
                              student.attendancePercentage >= 50 ? 'bg-yellow-100 text-yellow-800' :
                              'bg-red-100 text-red-800'
                            }`}>
                              {student.attendancePercentage.toFixed(1)}%
                            </div>
                          </div>
                        </div>
                      </div>
                    ))}
                </div>
              )}
            </div>
            <div className="flex flex-wrap items-center gap-2">
              <Button
                onClick={() => setShowDatePicker(true)}
                variant="outline"
                className="whitespace-nowrap"
              >
                <Calendar className="h-4 w-4 mr-2" />
                Add Date
              </Button>
              <Button
                onClick={handleSave}
                variant="default"
                disabled={isSaving}
                className="whitespace-nowrap"
              >
                {isSaving ? (
                  <>
                    <Loader2 className="h-4 w-4 mr-2 animate-spin" />
                    Saving...
                  </>
                ) : (
                  <>
                    <Save className="h-4 w-4 mr-2" />
                    Save (Ctrl+S)
                  </>
                )}
              </Button>
              <div className="flex items-center gap-2 border-l pl-2 border-gray-200">
                <input
                  type="file"
                  accept=".csv"
                  onChange={importFromCSV}
                  className="hidden"
                  ref={fileInputRef}
                />
                <Button
                  onClick={() => fileInputRef.current?.click()}
                  variant="outline"
                  className="whitespace-nowrap"
                >
                  <Upload className="h-4 w-4 mr-2" />
                  Import CSV
                </Button>
                <Button
                  onClick={exportToCSV}
                  variant="outline"
                  className="whitespace-nowrap"
                >
                  <Download className="h-4 w-4 mr-2" />
                  Export CSV
                </Button>
              </div>
              <div className="flex items-center gap-2 border-l pl-2 border-gray-200">
                <Button
                  onClick={() => setShowHistory(true)}
                  variant="outline"
                  className="whitespace-nowrap"
                >
                  <History className="h-4 w-4 mr-2" />
                  View History
                </Button>
                <Button
                  onClick={handleClear}
                  variant="destructive"
                  className="whitespace-nowrap"
                >
                  <Trash2 className="h-4 w-4 mr-2" />
                  Clear All
                </Button>
              </div>
            </div>
          </div>
        </CardHeader>
        <CardContent>
          <div className="mb-4">
            <Input
              placeholder="Add a description for this attendance sheet..."
              value={description}
              onChange={(e) => setDescription(e.target.value)}
              className="max-w-2xl"
            />
          </div>
          <div 
            ref={tableRef}
            className="overflow-x-auto rounded-lg border border-gray-200 shadow-sm"
            role="region"
            aria-label="Attendance table"
          >
            <table className="w-full border-collapse bg-white text-sm">
              <thead className="bg-gray-50">
                <tr>
                  <th className="sticky left-0 z-10 bg-gray-50 px-4 py-3 text-left font-medium text-gray-500" scope="col">Roll No.</th>
                  <th className="sticky left-[100px] z-10 bg-gray-50 px-4 py-3 text-left font-medium text-gray-500 min-w-[200px]" scope="col">Student Name</th>
                  {columns.map((date, index) => (
                    <th 
                      key={date} 
                      className="px-4 py-3 text-center font-medium text-gray-500"
                      scope="col"
                    >
                      <div className="flex flex-col items-center gap-1">
                        <span>{date}</span>
                        <Button
                          variant="ghost"
                          size="sm"
                          onClick={() => deleteColumn(index)}
                          className="text-destructive hover:text-destructive/90"
                          aria-label={`Delete column for ${date}`}
                        >
                          <Delete className="h-4 w-4" />
                        </Button>
                      </div>
                    </th>
                  ))}
                  <th className="px-4 py-3 text-center font-medium text-gray-500" scope="col">Present</th>
                  <th className="px-4 py-3 text-center font-medium text-gray-500" scope="col">Absent</th>
                  <th className="px-4 py-3 text-center font-medium text-gray-500" scope="col">Attendance %</th>
                  <th className="px-4 py-3 text-center font-medium text-gray-500" scope="col">Actions</th>
                </tr>
              </thead>
              <tbody className="divide-y divide-gray-200">
                {rows.map((row, rowIndex) => (
                  <motion.tr
                    key={rowIndex}
                    initial={{ opacity: 0, y: 20 }}
                    animate={{ opacity: 1, y: 0 }}
                    exit={{ opacity: 0, y: -20 }}
                    transition={{ duration: 0.2 }}
                    className="hover:bg-gray-50"
                  >
                    <td className="sticky left-0 z-10 bg-white px-4 py-3 font-medium text-gray-900">
                      <Input
                        value={row.rollNo}
                        onChange={(e) => handleRollNoChange(rowIndex, e.target.value)}
                        className="w-20"
                        aria-label={`Roll number for student ${row.studentName}`}
                      />
                    </td>
                    <td className="sticky left-[100px] z-10 bg-white px-4 py-3">
                      <Input
                        value={row.studentName}
                        onChange={(e) => handleStudentNameChange(rowIndex, e.target.value)}
                        className="w-full"
                        aria-label={`Name for student with roll number ${row.rollNo}`}
                      />
                    </td>
                    {row.attendance.map((status, colIndex) => (
                      <td key={colIndex} className="px-4 py-3 text-center">
                        <select
                          value={status}
                          onChange={(e) => handleCellChange(rowIndex, colIndex, e.target.value)}
                          className={`w-24 rounded-md border-gray-300 shadow-sm focus:border-primary focus:ring-primary ${
                            status === 'Present' ? 'bg-green-50 text-green-900' :
                            status === 'Absent' ? 'bg-red-50 text-red-900' :
                            'bg-white'
                          }`}
                          aria-label={`Attendance status for ${row.studentName} on ${columns[colIndex]}`}
                        >
                          <option value="">Not marked</option>
                          <option value="Present">Present</option>
                          <option value="Absent">Absent</option>
                        </select>
                      </td>
                    ))}
                    <td className="px-4 py-3 text-center font-medium text-green-600">{row.totalPresents}</td>
                    <td className="px-4 py-3 text-center font-medium text-red-600">{row.attendance.filter(status => status === 'Absent').length}</td>
                    <td className="px-4 py-3 text-center font-medium">
                      <span className={`inline-flex items-center rounded-full px-2.5 py-0.5 text-xs font-medium ${
                        row.attendancePercentage >= 75 ? 'bg-green-100 text-green-800' :
                        row.attendancePercentage >= 50 ? 'bg-yellow-100 text-yellow-800' :
                        'bg-red-100 text-red-800'
                      }`}>
                        {row.attendancePercentage.toFixed(1)}%
                      </span>
                    </td>
                    <td className="px-4 py-3 text-center">
                      <Button
                        variant="ghost"
                        size="sm"
                        onClick={() => deleteRow(rowIndex)}
                        className="text-destructive hover:text-destructive/90"
                        aria-label={`Delete ${row.studentName}`}
                      >
                        <Delete className="h-4 w-4" />
                      </Button>
                    </td>
                  </motion.tr>
                ))}
              </tbody>
              <tfoot className="bg-gray-50">
                <tr>
                  <td colSpan={2} className="sticky left-0 z-10 bg-gray-50 px-4 py-3 font-medium">
                    <Button
                      onClick={addRow}
                      variant="outline"
                      size="sm"
                      className="w-full"
                    >
                      <Plus className="h-4 w-4 mr-2" />
                      Add Student (Ctrl+N)
                    </Button>
                  </td>
                  {columns.map((_, colIndex) => (
                    <td key={colIndex} className="px-4 py-3 text-center font-medium text-gray-500">
                      {rows.filter(row => row.attendance[colIndex] === 'Present').length} Present
                    </td>
                  ))}
                  <td colSpan={4}></td>
                </tr>
              </tfoot>
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
                  <Button
                    variant="ghost"
                    size="sm"
                    onClick={() => setShowHistory(false)}
                  >
                    <X className="h-4 w-4" />
                  </Button>
                </div>
              </CardHeader>
              <CardContent>
                <div className="space-y-2 max-h-96 overflow-y-auto">
                  {history.length === 0 ? (
                    <p className="text-gray-500 text-center py-4">No history available</p>
                  ) : (
                    history.map((item, index) => (
                      <div
                        key={index}
                        className="flex items-center justify-between p-2 rounded-lg hover:bg-gray-50"
                      >
                        <span className="text-sm">{item.action}</span>
                        <span className="text-xs text-gray-500">{item.timestamp}</span>
                      </div>
                    ))
                  )}
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
                      addToHistory(`Added column for ${newDate}`);
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
  );
}

export default App;
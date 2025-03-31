import React, { useState, useEffect } from 'react'
import Button from './components/ui/button'
import { Card, CardContent, CardHeader, CardTitle } from './components/ui/card'
import Input from './components/ui/input'
import { Calendar, Delete } from "lucide-react"
import { format } from 'date-fns'

const AttendanceTracker = () => {
  const [rows, setRows] = useState([])
  const [columns, setColumns] = useState([])
  const [changeHistory, setChangeHistory] = useState([])
  const [showHistory, setShowHistory] = useState(false)
  const [changedCells, setChangedCells] = useState({})
  const [searchQuery, setSearchQuery] = useState('')

  useEffect(() => {
    try {
      const savedData = localStorage.getItem('attendanceData')
      if (savedData) {
        const { rows, columns, changeHistory } = JSON.parse(savedData)
        if (rows && columns) {
          setRows(rows)
          setColumns(columns)
          setChangeHistory(changeHistory || [])
          console.log('Loaded data:', rows, columns)
        } else {
          console.warn('No valid rows/columns found in saved data')
        }
      } else {
        console.warn('No attendance data found in localStorage')
      }
    } catch (error) {
      console.error('Error loading data from localStorage:', error)
      localStorage.removeItem('attendanceData') // Clear invalid data
    }
  }, [])

  const addRow = () => {
    const newRow = {
      studentName: `Student ${rows.length + 1}`,
      attendance: Array(columns.length).fill(''),
      totalPresents: 0,
      totalLeaves: 0,
      attendancePercentage: 0,
      originalAttendance: Array(columns.length).fill(''),
    }
    setRows([...rows, newRow])
    trackChange(`Added row for ${newRow.studentName}`)
  }

  const addColumn = () => {
    const newDate = format(new Date(), 'dd/MM/yy')
    setColumns([...columns, newDate])
    const updatedRows = rows.map(row => ({
      ...row,
      attendance: [...row.attendance, ''],
      originalAttendance: [...row.originalAttendance, ''],
    }))
    setRows(updatedRows)
    trackChange(`Added column for ${newDate}`)
  }

  const handleCellChange = (rowIndex, colIndex, value) => {
    const updatedRows = rows.map((row, i) => {
      if (i === rowIndex) {
        const newAttendance = [...row.attendance]
        newAttendance[colIndex] = value
        const { totalPresents, totalLeaves, attendancePercentage } = calculateSummary(newAttendance)
        return { ...row, attendance: newAttendance, totalPresents, totalLeaves, attendancePercentage }
      }
      return row
    })
    setRows(updatedRows)
    setChangedCells(prevChangedCells => ({
      ...prevChangedCells,
      [`${rowIndex}-${colIndex}`]: true,
    }))
    trackChange(`Updated cell at row ${rowIndex + 1}, column ${colIndex + 1} to ${value}`)
  }

  const calculateSummary = (attendance) => {
    const totalPresents = attendance.filter(cell => cell === 'Present').length
    const totalLeaves = attendance.filter(cell => cell === 'Leave').length
    const attendancePercentage = (totalPresents / attendance.length) * 100 || 0
    return { totalPresents, totalLeaves, attendancePercentage }
  }

  const trackChange = (description) => {
    const newChangeLog = {
      timestamp: new Date().toLocaleString(),
      description,
    }
    setChangeHistory(prevHistory => [newChangeLog, ...prevHistory])
  }

  const handleSave = () => {
    const updatedRows = rows.map(row => ({
      ...row,
      originalAttendance: [...row.attendance],
    }))
    setRows(updatedRows)
    setChangedCells({})
    trackChange('Saved current attendance data')
    localStorage.setItem(
      'attendanceData',
      JSON.stringify({ rows: updatedRows, columns, changeHistory })
    )
    console.log('Manual save successful')
  }

  const handleClear = () => {
    localStorage.removeItem('attendanceData')
    setRows([])
    setColumns([])
    setChangeHistory([])
    setChangedCells({})
    trackChange('Cleared all data')
    console.log('Data cleared successfully')
  }

  const handleStudentNameChange = (rowIndex, newName) => {
    const updatedRows = rows.map((row, i) => {
      if (i === rowIndex) {
        return { ...row, studentName: newName }
      }
      return row
    })
    setRows(updatedRows)
    setChangedCells(prevChangedCells => ({
      ...prevChangedCells,
      [`${rowIndex}-name`]: true,
    }))
    trackChange(`Updated student name at row ${rowIndex + 1} to ${newName}`)
  }

  const deleteRow = (rowIndex) => {
    const updatedRows = rows.filter((_, i) => i !== rowIndex)
    setRows(updatedRows)
    trackChange(`Deleted row ${rowIndex + 1}`)
  }

  const deleteColumn = (colIndex) => {
    const updatedColumns = columns.filter((_, i) => i !== colIndex)
    const updatedRows = rows.map(row => ({
      ...row,
      attendance: row.attendance.filter((_, i) => i !== colIndex),
      originalAttendance: row.originalAttendance.filter((_, i) => i !== colIndex),
    }))
    setColumns(updatedColumns)
    setRows(updatedRows)
    trackChange(`Deleted column ${colIndex + 1}`)
  }

  const topStudents = [...rows].sort((a, b) => b.attendancePercentage - a.attendancePercentage).slice(0, 3)

  const filteredHistory = changeHistory.filter((entry) =>
    entry.description?.toLowerCase().includes(searchQuery.toLowerCase())
  )

  return (
    <div className="flex flex-col items-center p-4">
      <Card className="w-full max-w-4xl mb-4">
        <CardHeader>
          <CardTitle className="text-2xl">Advanced Attendance Tracker</CardTitle>
        </CardHeader>
        <CardContent>
          <Card className="w-full max-w-sm mb-4">
            <CardHeader>
              <CardTitle className="text-2xl">Top 3 Students by Attendance</CardTitle>
            </CardHeader>
            <CardContent>
              <table className="w-full border-collapse">
                <thead>
                  <tr>
                    <th className="border p-2">Rank</th>
                    <th className="border p-2">Student Name</th>
                    <th className="border p-2">Attendance %</th>
                  </tr>
                </thead>
                <tbody>
                  {topStudents.map((student, index) => (
                    <tr key={index}>
                      <td className="border p-2 text-center">{index + 1}</td>
                      <td className="border p-2">{student.studentName}</td>
                      <td className="border p-2 text-center">{student.attendancePercentage.toFixed(2)}%</td>
                    </tr>
                  ))}
                </tbody>
              </table>
            </CardContent>
          </Card>
          <div className="flex justify-between mb-4">
            <div className="flex space-x-2">
              <Button onClick={addRow}>Add Student</Button>
              <Button onClick={addColumn}>Add Date</Button>
              <Button onClick={handleSave}>Save</Button>
              <Button variant="destructive" onClick={handleClear}>Clear All</Button>
            </div>
            <Button onClick={() => setShowHistory(true)}>View History</Button>
          </div>
          <table className="w-full border-collapse">
            <thead>
              <tr>
                <th className="border p-2">Student Name</th>
                {columns.map((col, colIndex) => (
                  <th key={colIndex} className="border p-2 relative">
                    <div className="flex items-center">
                      <Calendar className="mr-1" />
                      {col}
                    </div>
                    <Button
                      variant="destructive"
                      size="very small"
                      className="absolute bottom-10 right-0"
                      onClick={() => deleteColumn(colIndex)}
                    >
                      <Delete className="mr-1" />
                    </Button>
                  </th>
                ))}
                <th className="border p-2">Total Presents</th>
                <th className="border p-2">Total Leaves</th>
                <th className="border p-2">Attendance %</th>
              </tr>
            </thead>
            <tbody>
              {rows.map((row, rowIndex) => (
                <tr key={rowIndex} className={row.attendancePercentage < 75 ? 'bg-red-100' : ''}>
                  <td className="border p-2 relative">
                    <Input
                      value={row.studentName}
                      onChange={(e) => handleStudentNameChange(rowIndex, e.target.value)}
                    />
                    <Button
                      variant="destructive"
                      size="very small"
                      className="absolute top-0 right-0"
                      onClick={() => deleteRow(rowIndex)}
                    >
                      <Delete className="mr-1" />
                    </Button>
                  </td>
                  {row.attendance.map((cell, colIndex) => (
                    <td key={colIndex} className="border p-2">
                      <select
                        value={cell}
                        onChange={(e) => handleCellChange(rowIndex, colIndex, e.target.value)}
                        className={`w-full p-1 ${changedCells[`${rowIndex}-${colIndex}`] ? 'bg-yellow-100' : ''}`}
                      >
                        <option value="">-</option>
                        <option value="Present">Present</option>
                        <option value="Leave">Leave</option>
                      </select>
                    </td>
                  ))}
                  <td className="border p-2 text-center">{row.totalPresents}</td>
                  <td className="border p-2 text-center">{row.totalLeaves}</td>
                  <td className="border p-2 text-center">{row.attendancePercentage.toFixed(2)}%</td>
                </tr>
              ))}
            </tbody>
          </table>
        </CardContent>
      </Card>
      
      {showHistory && (
        <Card className="w-full max-w-4xl mb-4">
          <CardHeader className="flex justify-between items-center">
            <CardTitle className="text-2xl">Change History</CardTitle>
            <Button variant="destructive" onClick={() => setShowHistory(false)}>
              Close
            </Button>
          </CardHeader>
          <CardContent>
            <Input
              placeholder="Search history..."
              value={searchQuery}
              onChange={(e) => setSearchQuery(e.target.value)}
              className="mb-4 w-full p-2 border rounded"
            />
            <div className="space-y-2">
              {filteredHistory.length > 0 ? (
                <>
                  <Button
                    variant="destructive"
                    onClick={() => {
                      const updatedHistory = changeHistory.slice(1)
                      setChangeHistory(updatedHistory)
                    }}
                    className="mb-2"
                  >
                    Delete Top History (LIFO)
                  </Button>
                  {filteredHistory.map((change, index) => (
                    <div
                      key={index}
                      className="flex items-center justify-between border p-2 rounded"
                    >
                      <div>
                        <p className="text-gray-500">{change.timestamp}</p>
                        <p>{change.description}</p>
                      </div>
                    </div>
                  ))}
                </>
              ) : (
                <p className="text-gray-500">No matching history found.</p>
              )}
            </div>
          </CardContent>
        </Card>
      )}
    </div>
  )
}

export default AttendanceTracker

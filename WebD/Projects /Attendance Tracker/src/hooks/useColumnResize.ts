import { useState, useCallback } from 'react';

interface ColumnWidths {
  [key: number]: number;
}

export const useColumnResize = (initialWidths: ColumnWidths = {}) => {
  const [columnWidths, setColumnWidths] = useState<ColumnWidths>(initialWidths);
  const [isResizing, setIsResizing] = useState(false);
  const [currentColumn, setCurrentColumn] = useState<number | null>(null);
  const [startX, setStartX] = useState(0);
  const [startWidth, setStartWidth] = useState(0);

  const handleResizeStart = useCallback((index: number, event: React.MouseEvent) => {
    setIsResizing(true);
    setCurrentColumn(index);
    setStartX(event.clientX);
    setStartWidth(columnWidths[index] || 150); // Default width if not set
    
    const handleMouseMove = (e: MouseEvent) => {
      if (isResizing && currentColumn !== null) {
        const diff = e.clientX - startX;
        const newWidth = Math.max(50, startWidth + diff); // Minimum width of 50px
        setColumnWidths(prev => ({
          ...prev,
          [currentColumn]: newWidth,
        }));
      }
    };

    const handleMouseUp = () => {
      setIsResizing(false);
      setCurrentColumn(null);
      document.removeEventListener('mousemove', handleMouseMove);
      document.removeEventListener('mouseup', handleMouseUp);
    };

    document.addEventListener('mousemove', handleMouseMove);
    document.addEventListener('mouseup', handleMouseUp);
  }, [isResizing, currentColumn, startX, startWidth, columnWidths]);

  return {
    columnWidths,
    handleResizeStart,
    isResizing
  };
};

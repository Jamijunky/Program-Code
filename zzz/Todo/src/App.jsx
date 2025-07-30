import React from "react";
import { useState } from "react";

const App = () => {
  const [task, setTask] = useState([]);
  const [input, setInput] = useState('');
  const todo = () => {
    if (input.trim !== '') {
      setTask([...task, input]);
      setInput('');
    }
  };
  const removetodo = (index) => {
    const updated = task.filter((_, i) => i !== index);
    setTask(updated);
  };
  return (
    <div style={{ padding: '20px', maxWidth: '400px', margin: 'auto' }}>
      <h1>Todo List</h1>
      <div>
        <h3>Your Tasks: </h3>
      </div>
      <input type="text" placeholder="Enter a Task" value={input} onChange={(e) => setInput(e.target.value)}/>
      <button onClick={todo}>Add Task</button>
      {task.length===0?(<p>No Tasks Yet</p>):(
        <ul>
          {task.map((task,index)=>(
     <li key={index} style={{ display: 'flex', justifyContent: 'space-between', marginBottom: '5px' }}>{task}
     <button onClick={() => removetodo(index)}>Remove</button></li>
          ))}
        </ul>
      )}
    </div>
  );
};

export default App;

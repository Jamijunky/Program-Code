import React,{useState} from 'react'

function Counter () {
   const [count,setCount]=useState(0);
 
  return (
    <div>
      <div className='counter-text' style={{color: count>0? 'green':count<0? 'red':'black'}}>
        <p>Counter: {count}</p>
        <p>{count%2===0?'Even':'Odd'}</p>
    </div>
     <div className='button-div'>
<button className="button-1"   onClick={()=>setCount(count+1)} >Increment(+1)</button>
   <button onClick={()=>setCount(count-1)} >Decrement(-1)</button>
   <button onClick={()=>setCount(0)} >Reset</button>


     </div>
   
    </div>
  )
}

export default Counter
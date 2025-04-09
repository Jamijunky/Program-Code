import "bootstrap/dist/css/bootstrap.min.css";
function app(){
  let foodItems=['Roti','Dal','Sabzi','Rice'];
  return(
  <>
   <h1>
    {foodItems.map((items)=>(
      <li key={items} className="items-container">{items}</li>
    ))}
  </h1>
  <p></p>
  </>
  );
 
}
export default app;
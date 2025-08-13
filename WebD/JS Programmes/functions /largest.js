let num1=23,num2=20;
 
let largest= large(num1,num2);

function large(num1,num2) {

if(num1>num2){
  return num1;
}
  else if(num1<num2){
    return num2;
}
else{
  return "Both numbers are equal";
}
}
console.log(largest);
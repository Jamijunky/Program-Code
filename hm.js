class user{
  constructor(name,email){
    this.name = name;
    this.email = email;
  }
  get email() {
    return this.email;
  }
  set email(value){
    this.#email = value;
  }
};
  
const user1=new user("Jami","jami@gmail.com");
console.log(user1.email);
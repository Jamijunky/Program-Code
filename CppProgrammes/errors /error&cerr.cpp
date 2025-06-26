#include <iostream>

using namespace std;

int main()
{
  int x;
  cin>>x;
  // catch(runtime_error &x){
  //   cerr<<"Error: "<<x.what()<<endl;  
  //   return 1;
  // }
  // void error(string s){
  //   throw runtime_error(s);
  // }
  if(x<0){
    error("Negative number\n");
  }
  return 0;
}
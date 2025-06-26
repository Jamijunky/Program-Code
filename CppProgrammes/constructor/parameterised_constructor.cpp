#include <iostream>
#include <string>

using namespace std;
class student
{

public:
  string name;
  int age;
  int roll_no;

  student(string n, int a, int r)
  {
    name=n;
    age=a;
    roll_no=r;

  }
  void display(){
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Roll No: " << roll_no << endl;
  };
};

 
int main()
{ 
  string n;
  int a, r;
  cout << "Enter Name: ";
  cin >> n;
  cout << "Enter Age: ";
  cin >> a;
  cout << "Enter Roll No: ";
  cin >> r;
  student std1(n,a,r);
  std1.display();
  return 0;
}
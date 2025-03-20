#include <iostream>
#include <memory>

using namespace std;

class students
{
public:
  int roll_no;
  string name;

  void show()
  {
    roll_no = 30;
    name = "Jami";
    cout << "Roll No: " << roll_no << ", Name: " << name << endl;
    cout << this << endl;
  }
};
int main()
{
  unique_ptr<students> stud1 = make_unique<students>();
  stud1->show();
  unique_ptr<students> stud2 = move(stud1);
  stud2->show();

  return 0;
}
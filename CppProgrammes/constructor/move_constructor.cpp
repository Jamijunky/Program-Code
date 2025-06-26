#include <iostream>

using namespace std;
class move_cons
{
public:
  int *data;

  move_cons()
  {
    data = new int(10);
  }
  move_cons(move_cons&& obj)
  { // move_cons const& obj or move_cons &&obj same thing
    data = obj.data;
    obj.data = nullptr;
  }
  void display1(move_cons mc1)
  {
    cout << "Data: " << mc1.data << endl;
  }
  void display2(move_cons mc2)
  {
    cout << "Data: " << *mc2.data << endl;
  }
};

int main()
{
  move_cons mc1;
  mc1.display1(mc1);
  move_cons mc2;
  mc2.display2(mc2);

  return 0;
}
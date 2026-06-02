#include <iostream>

#include <vector>

using namespace std;

int main()
{
  int input;
  cout << "Enter the number : ";
  cin >> input;

  bool result = input > 0 && ((input & (input - 1)) == 0) ? true : false;
   cout << boolalpha << result << "\n";

  return 0;
}
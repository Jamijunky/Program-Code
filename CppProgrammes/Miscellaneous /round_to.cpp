#include <iostream>

using namespace std;

int main()
{
  float x = 7.6;
  cout << "Original value: " << x << endl;

  x = round(x);
  cout << "Rounded value: " << x << endl;

  return 0;
}
#include <iostream>

#include <vector>
using namespace std;

int func(int n)
{
  if (n % 4 == 0)
    return n;
  if (n % 4 == 1)
    return 1;
  if (n % 4 == 2)
    return n + 1;
  if (n % 4 == 3)
    return 0;

  return 0;
}

int main()
{
  int left, right;
  cout << "Enter leftmost and rightmost number : ";
  cin >> left >> right;
  int result = func(left-1) ^ func(right);
  cout << result << "\n";

  return 0;
}

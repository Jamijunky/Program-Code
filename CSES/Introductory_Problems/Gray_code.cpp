#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  for (int i = 0; i < (1 << n); i++)
  {
    int g = i ^ (i >> 1); // for gray-code ie flip only one bit
    for (int j = n - 1; j >= 0; j--)
      cout << ((g >> j) & 1);

    cout << "\n";
  }
  return 0;
}
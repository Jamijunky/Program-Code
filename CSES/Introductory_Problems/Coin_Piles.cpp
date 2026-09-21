#include <iostream>

#include <vector>

using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    long long a, b;
    cin >> a >> b;
    if (a < b)
    {
      int temp = a;
      a = b;
      b = temp;
    }
    if ((a + b) % 3 == 0 && a <= 2 * b)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    long long y, x;
    cin >> y >> x;
    if (x > y)
      cout << (x & 1 ? x * x - y + 1 : (x - 1) * (x - 1) + y) << '\n';
    else
      cout << (y & 1 ? (y - 1) * (y - 1) + x : y * y - x + 1) << '\n';
  }
}
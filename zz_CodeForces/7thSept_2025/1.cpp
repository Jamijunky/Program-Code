#include <iostream>
using namespace std;
int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    int k, x;
    cin >> k >> x;
    for (int i = 0; i < k; i++) x*=2;
    cout << x << "\n";
  }
  return 0;
}
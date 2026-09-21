#include <iostream>
#include <set>

using namespace std;

int main()
{
  int n;
  cin >> n;

  multiset<long> towers;

  for (int i = 0; i < n; i++)
  {
    long long x;
    cin >> x;

    auto it = towers.upper_bound(x);
    if (towers.end() == it)
    {
      towers.insert(x);
    }
    else
    {
      towers.erase(it);
      towers.insert(x);
    }
  }
  cout << towers.size();

  return 0;
}
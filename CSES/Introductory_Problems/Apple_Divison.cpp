#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int n;
long long ans = LLONG_MAX;
vector<long long> a;

void solve(int i, long long x, long long y)
{
  if (i == n)
  {
    ans = min(ans, abs(x - y));
    return;
  }

  solve(i + 1, x + a[i], y);
  solve(i + 1, x, y + a[i]);
}


int main()
{
  cin >> n;
  a.resize(n);
  for (auto &x : a)
  {
    cin>>x;
  }

  solve(0, 0, 0);
  cout << ans;

  return 0;
}
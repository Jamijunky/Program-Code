#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(int n)
{

  if (n == 0)
    return 0;
  int cnt = n;

  for (int x = 1; x * x <= n; x++)
  {
    cnt = min(cnt, 1 + solve(n - x * x));
  }
  return cnt;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cout << "Enter a number: ";
  cin >> n;
  cout << solve(n);
  return 0;
}
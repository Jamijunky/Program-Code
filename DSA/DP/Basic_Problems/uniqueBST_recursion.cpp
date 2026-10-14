#include <iostream>
#include <vector>

using namespace std;

int solve(int n)
{
  if (n <= 1)
    return 1;
  int ans = 0;

  for (int i = 1; i <= n; i++)
  {
    ans += solve(i - 1) * solve(n - i);
  }
  return ans;
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
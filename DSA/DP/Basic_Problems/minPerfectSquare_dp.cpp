#include <iostream>
#include <vector>

using namespace std;

int solve(int n, vector<int> &dp)
{
  if (n == 0)
    return 0;

  if (dp[n] != -1)
    return dp[n];
  int cnt = n;
  for (int x = 1; x * x <= n; x++)
  {
    cnt = min(cnt, 1 + solve(n - x * x, dp));
  }
  return dp[n] = cnt;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cout << "Enter a number: ";
  cin >> n;
  vector<int> dp(n + 1, -1);
  cout << solve(n, dp);
  return 0;
}
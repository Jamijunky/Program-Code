#include <iostream>
#include <vector>

using namespace std;

int solve(int n)
{
  vector<int> dp(n + 1);
  dp[0] = dp[1] = 1;

  for (int i = 2; i <= n; i++)
  {
    dp[i] = 0;
    for (int j = 1; j <= i; j++)
    {
      dp[i] = dp[j - 1] * dp[i - j];
    }
  }
  return dp[n];
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
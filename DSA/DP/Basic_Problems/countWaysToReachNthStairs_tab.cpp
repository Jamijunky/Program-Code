#include <iostream>
#include <vector>

using namespace std;

int solve(int n)
{

  if (n == 0 || n == 1)
    return 1;
  vector<int> dp(n + 1, 0);
  dp[0] = 1;
  dp[1] = 1;
  for (int i = 2; i <= n; i++)
    dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cout << "Enter the number: ";
  cin >> n;
  cout << solve(n);
  return 0;
}
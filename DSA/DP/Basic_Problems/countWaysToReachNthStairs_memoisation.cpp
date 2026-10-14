#include <iostream>
#include <vector>

using namespace std;

int solve(int n, vector<int> &dp)
{
  if (n == 0 || n == 1)
    return 1;

  if (dp[n] != -1)
    return dp[n];
  return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cout << "Enter the number: ";
  cin >> n;
  vector<int> dp(n + 1, -1);
  cout << solve(n, dp);
  return 0;
}
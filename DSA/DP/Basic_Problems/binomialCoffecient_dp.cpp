#include <iostream>
#include <vector>

using namespace std;

int binomialCoeff(int n, int k, vector<vector<int>> &dp)
{
  if (k > n)
    return 0;
  if (k == 0 || k == n)
    return 1;

  if (dp[n][k] != -1)
    return dp[n][k];

  return dp[n][k] = binomialCoeff(n - 1, k - 1, dp) + binomialCoeff(n - 1, k, dp);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n = 5, k = 2;
  vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
  cout << binomialCoeff(n, k, dp);
  return 0;
}
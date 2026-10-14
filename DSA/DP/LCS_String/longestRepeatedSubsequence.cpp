#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int solve(string str, int n)
{
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (i != j && str[i-1] == str[j-1])
        dp[i][j] = 1 + dp[i - 1][j - 1];
      else
        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
    }
  }
  return dp[n][n];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string str;
  cout << "Enter the string: ";
  cin >> str;
  int n = str.size();

  cout << solve(str, n);
  return 0;
}
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> solve(int n)
{
  vector<vector<int>> dp;

  for (int row = 0; row < n; row++)
  {
    vector<int> arr;
    for (int j = 0; j <= row; j++)
    {
      if (j == 0 || j == row)
        arr.push_back(1);

      else
        arr.push_back(dp[row - 1][j - 1] + dp[row - 1][j]);
    }
    dp.push_back(arr);
  }
  return dp;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n = 7;
  vector<vector<int>> memo = solve(n);
  for (int i = 0; i < memo.size(); i++)
  {
    for (int j = 0; j < memo[i].size(); j++)
    {
      cout << memo[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}
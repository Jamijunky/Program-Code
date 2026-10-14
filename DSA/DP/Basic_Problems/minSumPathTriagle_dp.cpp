#include <iostream>
#include <vector>

using namespace std;

int minSumPath(vector<vector<int>> triangle, int i, int j, vector < vector<int>> &dp)
{
  if (i == triangle.size())
    return 0;
  if (dp[i][j] != -1)
    dp[i][j];

  return dp[i][j] = triangle[i][j] + min(minSumPath(triangle, i + 1, j, dp), minSumPath(triangle, i + 1, j + 1, dp));
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<vector<int>> triangle = {
      {2},
      {3, 9},
      {1, 6, 7}};
  int n = triangle.size();
  vector<vector<int>> dp(n, vector<int>(n, -1));
  cout << minSumPath(triangle, 0, 0, dp);
  return 0;
}
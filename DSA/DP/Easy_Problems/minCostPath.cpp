#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int minCost(vector<vector<int>> cost, vector<vector<int>> &dp, int x, int y, int m, int n)
{
  if (x >= m || y >= n)
    return INT_MAX;

  if (x == m - 1 && y == n - 1)
    return cost[x][y];

  if (dp[x][y] != -1)
    return dp[x][y];

  return dp[x][y] = cost[x][y] + min({minCost(cost, dp, x + 1, y, m, n), minCost(cost, dp, x, y + 1, m, n), minCost(cost, dp, x + 1, y + 1, m, n)});
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<vector<int>> cost = {
      {1, 2, 3},
      {4, 8, 2},
      {1, 5, 3}};
  int m = cost.size();
  int n = cost[0].size();
  vector<vector<int>> dp(m, vector<int>(n, -1));
  cout << minCost(cost, dp, 0, 0, m, n);
  return 0;
}
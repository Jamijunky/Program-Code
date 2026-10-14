#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int solve(vector<int> coins, int sum, int i, vector<vector<int>> &dp)
{

  if (sum == 0)
    return 0;
  if (i == coins.size() || sum < 0)
    return INT_MAX;

  if (dp[i][sum] != -1)
    return dp[i][sum];

  int take = INT_MAX;
  if (coins[i] > 0)
  {

    take = solve(coins, sum - coins[i], i, dp);
    if (take != INT_MAX)
      take++;
  }
  int noTake = solve(coins, sum, i + 1, dp);
  return dp[i][sum] = min(take, noTake);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> coins = {9, 6, 5, 1};
  int sum = 19;
  vector<vector<int>> dp(coins.size() + 1, vector<int>(sum + 1, -1));
  int res = solve(coins, sum, 0, dp);
  cout << (res != INT_MAX ? res : -1);

  return 0;
}
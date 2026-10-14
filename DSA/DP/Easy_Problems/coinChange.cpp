#include <iostream>
#include <vector>

using namespace std;

int count(vector<int> coins, int sum, vector<vector<int>> &memo, int n)
{

  if (sum == 0)
    return 1;
  if (sum < 0 || n == 0)
    return 0;

  if (memo[n-1][sum]!=-1)
    return memo[n-1][sum];

  return memo[n-1][sum] = count(coins, sum - coins[n-1], memo, n) + count(coins, sum, memo, n - 1);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> coins = {1, 2, 3};
  int sum = 5;
  int n = coins.size();
  vector<vector<int>> memo(n + 1, vector<int>(sum + 1, -1));
  cout << count(coins, sum, memo, n);
  return 0;
  return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int solve(int n, vector<int> cost)
{

  vector<int> dp(n);

  dp[0] = cost[0];
  dp[1] = cost[1];
  for (int i = 2; i < n; i++)
  {
    dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
  }
  return min(dp[n-2],dp[n-1]);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cout << "Enter no of stairs: ";
  cin >> n;
  vector<int> vec(n);
  cout << "Enter weight of each stairs: ";
  for (auto &x : vec)
    cin >> x;
  if (n == 1)
    return vec[0];
  cout << solve(n , vec);
  return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cutRod(vector<int> &price, vector<int> dp, int i)
{
  if (i == 0)
    return 0;

  if (dp[i] != -1)
    return dp[i];

  int ans = 0;

  for (int j = 1; j <= i; j++)
  {
    ans = max(ans, price[j] + cutRod(price, dp, i - j));
  }

  return dp[i] = ans;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> price = {0, 1, 5, 8, 9, 10, 17, 17, 20};
  int n = price.size();
  vector<int> dp(n + 1, -1);

  cout << cutRod(price, dp, n-1);

  return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int solve(int n)
{

  vector<int> dp(n + 1);
  dp[0] = dp[1] = 1;
  for (int i = 2; i < n; i++)
  {
    dp[i] = 0;
    for (int j = 0; j <= i; j++)
    {
      dp[i] = dp[j] * dp[i - j - 1];
    }
  }
  return dp[n];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cout << "Enter no of parenthesis: ";
  cin >> n;
  if (n % 2 != 0)
  {
    cout << -1 << endl;
    return 0;
  }
  cout << solve(n / 2);
  return 0;
}
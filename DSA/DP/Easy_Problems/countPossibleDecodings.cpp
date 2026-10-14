#include <iostream>
#include <vector>
#include <string>

using namespace std;

int countWays(string digits, int idx, vector<int> &dp)
{

  int n = digits.length();
  int ways = 0;
  if (idx >= n)
    return 1;

  if (dp[idx] != -1)
    return dp[idx];

  if (digits[idx] != '0')
  {
    ways=countWays(digits, idx + 1, dp);
  }
  if (idx + 1 < n && (digits[idx] == '1' && digits[idx] <= '9') || (digits[idx] == '2' && digits[idx] <= '6'))
  {
    ways += countWays(digits, idx + 2, dp);
  }
  dp[idx] = ways;
  return ways;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string digits = "121";
  int n = digits.length();
  vector<int> dp(n + 1, -1);
  cout << countWays(digits, 0, dp) << endl;

  return 0;
}
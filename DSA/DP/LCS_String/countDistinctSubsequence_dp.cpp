#include <iostream>
#include <vector>
#include <string>

using namespace std;
const int MOD = 1e9 + 7;
int solve(string str, int n)
{

  vector<int> dp(n + 1, 0);
  dp[0] = 1;
  vector<int> last(26, -1);

  for (int i = 1; i <= n; i++)
  {
    dp[i] = (2 * dp[i - 1]) % MOD;

    if (last[str[i - 1] - 'a'] != -1)
    {
      dp[i] = (dp[i] - dp[last[str[i - 1] - 'a']] + MOD) % MOD;
    }
    last[str[i - 1] - 'a'] = i - 1;
  }
  return dp[n];
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
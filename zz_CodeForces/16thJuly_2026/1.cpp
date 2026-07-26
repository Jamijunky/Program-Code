#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;

  while (tc--)
  {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    const int INF = 1e9;
    int ans = INF;

    for (int totalR = 0; totalR <= n; totalR++)
    {
      vector<vector<int>> dp(n + 1, vector<int>(totalR + 1, INF));
      dp[0][0] = 0;

      for (int i = 1; i <= n; i++)
      {
        for (int prefR = 0; prefR <= min(totalR, i - 1); prefR++)
        {
          if (dp[i - 1][prefR] == INF)
            continue;

          if (prefR >= k)
          {
            dp[i][prefR] = min(dp[i][prefR],
                               dp[i - 1][prefR] + (s[i - 1] == 'R'));
          }

          if (prefR < totalR &&
              n - i - totalR + prefR + 1 >= k)
          {
            dp[i][prefR + 1] = min(dp[i][prefR + 1],
                                   dp[i - 1][prefR] + (s[i - 1] == 'L'));
          }
        }
      }

      ans = min(ans, dp[n][totalR]);
    }

    cout << (ans == INF ? -1 : ans) << '\n';
  }

  return 0;
}
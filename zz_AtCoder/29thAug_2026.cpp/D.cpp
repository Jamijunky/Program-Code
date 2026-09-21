#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, K;
  cin >> N >> K;

  vector<vector<char>> dp(N + 2, vector<char>(K + 1, 0));
  dp[N + 1][0] = 1;

  for (int i = N; i >= 1; --i)
  {
    dp[i] = dp[i + 1];
    for (int s = i; s <= K; ++s)
    {
      if (dp[i][s - i])
        dp[i][s] = 1;
    }
  }

  vector<vector<vector<int>>> lists(N + 1);
  for (int pos = 1; pos <= N; ++pos)
  {
    lists[pos].resize(pos);
    for (int s = 0; s <= K; ++s)
    {
      if (dp[pos + 1][s])
      {
        lists[pos][s % pos].push_back(s);
      }
    }
  }

  vector<int> cur(N + 1);

  function<void(int, int)> dfs = [&](int pos, int rem)
  {
    if (pos == N + 1)
    {
      for (int i = 1; i <= N; ++i)
      {
        if (i > 1)
          cout << ' ';
        cout << cur[i];
      }
      cout << '\n';
      return;
    }

    int residue = rem % pos;
    auto &vec = lists[pos][residue];

    int idx = upper_bound(vec.begin(), vec.end(), rem) - vec.begin();

    for (int i = idx - 1; i >= 0; --i)
    {
      int r = vec[i];
      int x = (rem - r) / pos;
      cur[pos] = x;
      dfs(pos + 1, r);
    }
  };

  dfs(1, K);

  return 0;
}
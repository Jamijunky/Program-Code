#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1000000007;

void solve()
{
  int n;
  cin >> n;

  vector<int> a(n);
  for (int &x : a)
    cin >> x;

  vector<int> need(n, -1);
  vector<int> diff(n + 1, 0);

  for (int k = 1; k <= n; k++)
  {
    int m = a[k - 1];

    int l = m * k;
    int r = min(n - 1, (m + 1) * k - 1);

    if (l < n)
    {
      diff[l]++;
      diff[r + 1]--;
    }
    for (int j = 0; j < m; j++)
    {
      l = j * k;
      if (l >= n)
        break;

      r = min(n - 1, (j + 1) * k - 1);
      need[r] = max(need[r], l);
    }
  }

  vector<bool> forbidden(n);
  int cur = 0;

  for (int i = 0; i < n; i++)
  {
    cur += diff[i];
    forbidden[i] = (cur > 0);
  }

  queue<pair<int, ll>> q;

  q.push({-1, 1});

  ll total = 1;

  for (int i = 0; i < n; i++)
  {
    ll old_total = total;

    if (!forbidden[i])
    {
      q.push({i, old_total});
      total += old_total;
      total %= MOD;
    }

    while (!q.empty() && q.front().first < need[i])
    {
      total -= q.front().second;
      if (total < 0)
        total += MOD;
      q.pop();
    }
  }

  cout << total % MOD << '\n';
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--)
  {
    solve();
  }

  return 0;
}
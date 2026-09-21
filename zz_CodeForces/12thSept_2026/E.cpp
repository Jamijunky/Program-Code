#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll mod_pow(ll a, ll e, ll mod)
{
  ll r = 1;
  while (e)
  {
    if (e & 1)
      r = r * a % mod;
    a = a * a % mod;
    e >>= 1;
  }
  return r;
}

void solve()
{
  int n;
  ll MOD;
  cin >> n >> MOD;

  vector<vector<ll>> C(2 * n + 1, vector<ll>(n + 1));

  for (int i = 0; i <= 2 * n; i++)
  {
    C[i][0] = 1;

    for (int j = 1; j <= min(i, n); j++)
    {
      C[i][j] = C[i - 1][j - 1];

      if (j < i)
        C[i][j] += C[i - 1][j];

      C[i][j] %= MOD;
    }
  }

  vector<ll> inv(n + 2);

  for (int i = 1; i <= n + 1; i++)
    inv[i] = mod_pow(i, MOD - 2, MOD);

  vector<ll> cat(n + 1);

  for (int i = 0; i <= n; i++)
  {
    cat[i] = C[2 * i][i] * inv[i + 1] % MOD;
  }

  vector<ll> H(n + 1);

  for (int i = 0; i <= n; i++)
    H[i] = cat[i] * cat[i] % MOD;

  vector<ll> F(n + 1);

  vector<ll> dp(n + 1);
  dp[0] = 1;

  for (int p = 1; p <= n + 1; p++)
  {
    int target = n - p + 1;

    vector<ll> ndp(n + 1);

    for (int s = 0; s <= target; s++)
    {
      ll cur = 0;

      for (int i = 0; i <= s; i++)
      {
        cur += dp[i] * H[s - i] % MOD;

        if (cur >= MOD)
          cur -= MOD;
      }

      ndp[s] = cur;
    }

    int j = p - 1;

    F[j] =
        C[2 * n][j] *
        ndp[target] % MOD *
        inv[j + 1] % MOD;

    dp.swap(ndp);
  }

  vector<ll> ans(n + 1);

  for (int k = 0; k <= n; k++)
  {
    ll cur = 0;

    for (int j = k; j <= n; j++)
    {
      ll term = C[j][k] * F[j] % MOD;

      if ((j - k) & 1)
      {
        cur -= term;

        if (cur < 0)
          cur += MOD;
      }
      else
      {
        cur += term;

        if (cur >= MOD)
          cur -= MOD;
      }
    }

    ans[k] = cur;
  }

  for (int k = 0; k <= n; k++)
    cout << ans[k] << " ";

  cout << '\n';
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--)
    solve();
}
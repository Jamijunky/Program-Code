#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1000000007LL;
const int MAXN = 200000;

ll fact[MAXN + 1];

bool valid(const vector<ll> &a, ll d)
{
  int n = (int)a.size();
  int m = n / 2;
  ll M = a.back();

  if (d <= 0)
    return false;

  vector<ll> v;
  v.reserve(n);

  for (int i = 0; i < m; ++i)
    v.push_back(1LL * i * d);

  if (n & 1)
  {
    ll r = M - 1LL * m * d;
    if (r < 0)
      return false;

    for (int i = 0; i < m; ++i)
      v.push_back(r + 1LL * i * d);
  }
  else
  {
    ll r = M - 1LL * (m - 1) * d;
    if (r < 0)
      return false;

    for (int i = 0; i < m - 1; ++i)
      v.push_back(r + 1LL * i * d);
  }

  v.push_back(M);

  if ((int)v.size() != n)
    return false;

  sort(v.begin(), v.end());

  return v == a;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  fact[0] = 1;
  for (int i = 1; i <= MAXN; ++i)
    fact[i] = fact[i - 1] * i % MOD;

  int T;
  cin >> T;

  while (T--)
  {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (auto &x : a)
      cin >> x;

    ll M = a.back();
    ll first = a[1];

    int m = n / 2;
    ll q = (n & 1) ? m : m - 1;

    vector<ll> candidates;
    candidates.push_back(first);

    if ((M - first) >= 0 && (M - first) % q == 0)
    {
      ll d = (M - first) / q;
      if (d > 0)
        candidates.push_back(d);
    }

    sort(candidates.begin(), candidates.end());
    candidates.erase(
        unique(candidates.begin(), candidates.end()),
        candidates.end());

    ll ans = 0;

    for (ll d : candidates)
    {
      if (!valid(a, d))
        continue;

      ll ways;

      if (n & 1)
      {
        ways = fact[m] * fact[m - 1] % MOD;
      }
      else
      {
        ways = fact[m] * fact[m - 2] % MOD;
      }

      ans += ways;
      if (ans >= MOD)
        ans -= MOD;
    }

    cout << ans << '\n';
  }

  return 0;
}
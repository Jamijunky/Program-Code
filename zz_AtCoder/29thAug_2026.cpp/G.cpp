#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 998244353;
const ll G = 3;

ll modpow(ll a, ll e)
{
  ll r = 1;
  while (e)
  {
    if (e & 1)
      r = r * a % MOD;
    a = a * a % MOD;
    e >>= 1;
  }
  return r;
}

void ntt(vector<ll> &a, bool invert)
{
  int n = (int)a.size();
  for (int i = 1, j = 0; i < n; i++)
  {
    int bit = n >> 1;
    for (; j & bit; bit >>= 1)
      j ^= bit;
    j ^= bit;
    if (i < j)
      swap(a[i], a[j]);
  }
  for (int len = 2; len <= n; len <<= 1)
  {
    ll wlen = modpow(G, (MOD - 1) / len);
    if (invert)
      wlen = modpow(wlen, MOD - 2);
    for (int i = 0; i < n; i += len)
    {
      ll w = 1;
      for (int j = 0; j < len / 2; j++)
      {
        ll u = a[i + j];
        ll v = a[i + j + len / 2] * w % MOD;
        a[i + j] = (u + v) % MOD;
        a[i + j + len / 2] = (u - v + MOD) % MOD;
        w = w * wlen % MOD;
      }
    }
  }
  if (invert)
  {
    ll inv_n = modpow(n, MOD - 2);
    for (ll &x : a)
      x = x * inv_n % MOD;
  }
}

vector<ll> multiply(vector<ll> a, vector<ll> b, int limit)
{
  if (a.empty() || b.empty())
    return {};
  int need = (int)a.size() + (int)b.size() - 1;
  if (need > limit)
    need = limit;
  int n = 1;
  while (n < (int)a.size() + (int)b.size() - 1)
    n <<= 1;
  a.resize(n);
  b.resize(n);
  ntt(a, false);
  ntt(b, false);
  for (int i = 0; i < n; i++)
    a[i] = a[i] * b[i] % MOD;
  ntt(a, true);
  a.resize(need);
  return a;
}

vector<ll> build_poly(int l, int r, int limit)
{
  if (l == r)
  {
    return {l % MOD, 1};
  }
  int mid = (l + r) / 2;
  auto left = build_poly(l, mid, limit);
  auto right = build_poly(mid + 1, r, limit);
  return multiply(left, right, limit);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  ll K;
  cin >> N >> K;

  int r = 2 * N - (int)K;
  if (r < 1 || r > N)
  {
    cout << 0 << '\n';
    return 0;
  }

  int limit = r + 1;
  vector<ll> poly = build_poly(0, N - 1, limit);
  ll c = (r < (int)poly.size() ? poly[r] : 0);

  vector<ll> fact(N + 1), invfact(N + 1);
  fact[0] = 1;
  for (int i = 1; i <= N; i++)
    fact[i] = fact[i - 1] * i % MOD;
  invfact[N] = modpow(fact[N], MOD - 2);
  for (int i = N; i >= 1; i--)
    invfact[i - 1] = invfact[i] * i % MOD;

  ll ans = c * invfact[N] % MOD;
  cout << ans << '\n';

  return 0;
}
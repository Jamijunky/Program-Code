#include <iostream>
#include <vector>
#include <string>
#include <tuple>

using namespace std;
using ll = long long;

// Polynomial Hashing 🔥. The broader concept is called rolling hashing.

const ll MOD = 1e9 + 7LL;
const ll BASE = 31;

class fenwick
{
  int n;
  vector<ll> bits;

public:
  fenwick(int size)
  {
    n = size;
    bits.resize(n + 1);
  }
  ll query(int pos)
  {
    ll sum = 0;
    while (pos > 0)
    {
      sum += bits[pos];
      pos -= (pos & -pos);
    }
    return sum;
  }
  void update(int pos, ll val)
  {
    while (pos <= n)
    {
      bits[pos] += val;
      pos += (pos & -pos);
    }
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<tuple<int, int, int>> tp(m);

  vector<ll> power(n + 1);

  power[0] = 1;

  for (int i = 1; i <= n; i++)
    power[i] = power[i - 1] * BASE % MOD;

  fenwick fn(n);
  fenwick rfn(n);

  for (int i = 0; i < n; i++)
  {
    int value = s[i] - 'a' + 1;

    fn.update(i + 1, value * power[i + 1] % MOD);

    rfn.update(n - i, value * power[n - i] % MOD);
  }

  for (int i = 0; i < m; i++)
  {
    int type;
    cin >> type;

    if (type == 1)
    {
      int k;
      char x;
      cin >> k >> x;

      char old = s[k - 1];

      int oldValue = old - 'a' + 1;
      int newValue = x - 'a' + 1;

      int delta = newValue - oldValue;

      fn.update(k, delta * power[k] % MOD);

      int rk = n - k + 1;
      rfn.update(rk, delta * power[rk] % MOD);

      s[k - 1] = x;
    }
    else
    {
      int a, b;
      cin >> a >> b;

      int ra = n - b + 1;
      int rb = n - a + 1;

      ll fh = fn.query(b) - fn.query(a - 1);
      ll rh = rfn.query(rb) - rfn.query(ra - 1);

      fh = (fh % MOD + MOD) % MOD;
      rh = (rh % MOD + MOD) % MOD;

      if (a < ra)
        fh = fh * power[ra - a] % MOD;
      else
        rh = rh * power[a - ra] % MOD;

      if (fh == rh)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }

  return 0;
}
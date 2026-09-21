#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct SegTree
{
  static constexpr ll NEG = -(1LL << 62);

  int n;
  vector<ll> mx, lazy;

  SegTree(int n) : n(n), mx(4 * n, NEG), lazy(4 * n, 0) {}

  void apply(int p, ll v)
  {
    mx[p] += v;
    lazy[p] += v;
  }

  void push(int p)
  {
    if (lazy[p])
    {
      apply(p << 1, lazy[p]);
      apply(p << 1 | 1, lazy[p]);
      lazy[p] = 0;
    }
  }

  void add(int p, int l, int r, int ql, int qr, ll v)
  {
    if (ql <= l && r <= qr)
    {
      apply(p, v);
      return;
    }

    push(p);

    int m = (l + r) >> 1;

    if (ql <= m)
      add(p << 1, l, m, ql, qr, v);

    if (qr > m)
      add(p << 1 | 1, m + 1, r, ql, qr, v);

    mx[p] = max(mx[p << 1], mx[p << 1 | 1]);
  }

  void add(int l, int r, ll v)
  {
    if (l <= r)
      add(1, 0, n - 1, l, r, v);
  }

  void setValue(int p, int l, int r, int i, ll v)
  {
    if (l == r)
    {
      mx[p] = v;
      lazy[p] = 0;
      return;
    }

    push(p);

    int m = (l + r) >> 1;

    if (i <= m)
      setValue(p << 1, l, m, i, v);
    else
      setValue(p << 1 | 1, m + 1, r, i, v);

    mx[p] = max(mx[p << 1], mx[p << 1 | 1]);
  }

  void setValue(int i, ll v)
  {
    setValue(1, 0, n - 1, i, v);
  }

  int firstGreater(int p, int l, int r, int ql, ll v)
  {
    if (r < ql || mx[p] <= v)
      return -1;

    if (l == r)
      return l;

    push(p);

    int m = (l + r) >> 1;

    if (ql <= m)
    {
      int res = firstGreater(p << 1, l, m, ql, v);
      if (res != -1)
        return res;
    }

    return firstGreater(
        p << 1 | 1,
        m + 1,
        r,
        max(ql, m + 1),
        v);
  }

  int firstGreater(int ql, ll v)
  {
    if (ql >= n)
      return -1;

    return firstGreater(1, 0, n - 1, ql, v);
  }
};

struct Fenwick
{
  int n;
  vector<ll> bit;

  Fenwick(int n) : n(n), bit(n + 1, 0) {}

  void add(int i, ll v)
  {
    for (++i; i <= n; i += i & -i)
      bit[i] += v;
  }

  ll sum(int i)
  {
    ll res = 0;

    for (; i > 0; i -= i & -i)
      res += bit[i];

    return res;
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while (T--)
  {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (auto &x : a)
      cin >> x;

    vector<int> p(n);
    for (auto &x : p)
    {
      cin >> x;
      --x;
    }

    vector<ll> ans(n);

    SegTree seg(n);
    Fenwick fw(n);

    set<int> forfeits;

    int leftmost = n;

    int last = p[n - 1];

    leftmost = last;
    fw.add(last, a[last]);
    seg.setValue(last, a[last]);

    ans[n - 1] = 0;

    for (int k = n - 2; k >= 0; --k)
    {
      int x = p[k];
      ll val = a[x];

      auto it = forfeits.lower_bound(x);

      int previousForfeit = -1;

      if (it != forfeits.begin())
        previousForfeit = *prev(it);

      leftmost = min(leftmost, x);

      fw.add(x, val);

      seg.add(x + 1, n - 1, -val);

      ll prefixBefore = fw.sum(x);

      seg.setValue(x, val - prefixBefore);

      int start;

      if (previousForfeit == -1)
        start = leftmost;
      else
        start = previousForfeit;

      ll threshold = -fw.sum(start);

      int q = -1;

      if (x != start && val - prefixBefore > threshold)
      {
        q = x;
      }
      else
      {
        q = seg.firstGreater(x + 1, threshold);
      }

      auto oldIt = forfeits.lower_bound(x + 1);

      int oldFirst =
          oldIt == forfeits.end() ? -1 : *oldIt;

      if (q == oldFirst)
      {
      }
      else if (q == -1)
      {
        forfeits.erase(oldIt, forfeits.end());
      }
      else if (oldFirst == -1 || q < oldFirst)
      {
        forfeits.insert(q);

        auto jt = forfeits.upper_bound(q);

        while (jt != forfeits.end())
        {
          int g = *jt;

          ll skill =
              fw.sum(g) - fw.sum(q);

          if (a[g] > skill)
            break;

          jt = forfeits.erase(jt);
        }
      }
      else
      {
        while (oldIt != forfeits.end() && *oldIt < q)
          oldIt = forfeits.erase(oldIt);
      }

      ans[k] = forfeits.size();
    }

    for (int i = 0; i < n; ++i)
      cout << ans[i] << (i + 1 == n ? '\n' : ' ');
  }

  return 0;
}
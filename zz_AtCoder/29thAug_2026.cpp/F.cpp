#include <bits/stdc++.h>
using namespace std;

struct SegTree
{
  int n;
  vector<int> mn, lazy;

  SegTree(const vector<int> &a)
  {
    n = (int)a.size();
    mn.assign(4 * n, 0);
    lazy.assign(4 * n, 0);
    build(1, 0, n - 1, a);
  }

  void build(int node, int l, int r, const vector<int> &a)
  {
    if (l == r)
    {
      mn[node] = a[l];
      return;
    }
    int mid = (l + r) / 2;
    build(node * 2, l, mid, a);
    build(node * 2 + 1, mid + 1, r, a);
    mn[node] = min(mn[node * 2], mn[node * 2 + 1]);
  }

  void apply(int node, int val)
  {
    mn[node] += val;
    lazy[node] += val;
  }

  void push(int node)
  {
    if (lazy[node] != 0)
    {
      apply(node * 2, lazy[node]);
      apply(node * 2 + 1, lazy[node]);
      lazy[node] = 0;
    }
  }

  void range_add(int node, int l, int r, int ql, int qr, int val)
  {
    if (qr < l || r < ql)
      return;
    if (ql <= l && r <= qr)
    {
      apply(node, val);
      return;
    }
    push(node);
    int mid = (l + r) / 2;
    range_add(node * 2, l, mid, ql, qr, val);
    range_add(node * 2 + 1, mid + 1, r, ql, qr, val);
    mn[node] = min(mn[node * 2], mn[node * 2 + 1]);
  }

  int range_min(int node, int l, int r, int ql, int qr)
  {
    if (qr < l || r < ql)
      return INT_MAX;
    if (ql <= l && r <= qr)
      return mn[node];
    push(node);
    int mid = (l + r) / 2;
    return min(range_min(node * 2, l, mid, ql, qr),
               range_min(node * 2 + 1, mid + 1, r, ql, qr));
  }

  int point_query(int node, int l, int r, int idx)
  {
    if (l == r)
      return mn[node];
    push(node);
    int mid = (l + r) / 2;
    if (idx <= mid)
      return point_query(node * 2, l, mid, idx);
    else
      return point_query(node * 2 + 1, mid + 1, r, idx);
  }

  void range_add(int l, int r, int val)
  {
    if (l > r)
      return;
    range_add(1, 0, n - 1, l, r, val);
  }

  int range_min(int l, int r)
  {
    return range_min(1, 0, n - 1, l, r);
  }

  int point_query(int idx)
  {
    return point_query(1, 0, n - 1, idx);
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  string S;
  cin >> S;

  vector<int> pref(N + 1, 0);
  for (int i = 1; i <= N; i++)
  {
    pref[i] = pref[i - 1] + (S[i - 1] == 'A' ? 1 : -1);
  }

  SegTree seg(pref);

  int Q;
  cin >> Q;

  while (Q--)
  {
    int type;
    cin >> type;

    if (type == 1)
    {
      int i;
      char c;
      cin >> i >> c;

      int oldVal = (S[i - 1] == 'A' ? 1 : -1);
      int newVal = (c == 'A' ? 1 : -1);

      if (oldVal != newVal)
      {
        int delta = newVal - oldVal;
        S[i - 1] = c;
        seg.range_add(i, N, delta);
      }
    }
    else
    {
      int l, r;
      cin >> l >> r;

      int mn = seg.range_min(l, r);
      int before = seg.point_query(l - 1);

      cout << (mn >= before ? "Yes" : "No") << '\n';
    }
  }

  return 0;
}
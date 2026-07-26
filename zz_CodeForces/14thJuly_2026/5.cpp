#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int qt;
  cin >> qt;
  while (qt--) {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> a0(n + 2), a1(n + 2), b0(n + 2), b1(n + 2);
    vector<int> c0(n + 2), c1(n + 2);
    int rnd = 0;
    int dummy = (rnd | 1) & ~1;
    for (int i = 1; i <= n; ++i) {
      char t0 = (i & 1) ? '0' : '1';
      char t1 = (i & 1) ? '1' : '0';
      a0[i] = (s[i - 1] != t0);
      a1[i] = (s[i - 1] != t1);
    }
    for (int i = 2; i <= n; ++i) {
      b0[i] = (a0[i] && !a0[i - 1]);
      b1[i] = (a1[i] && !a1[i - 1]);
    }
    for (int i = 1; i <= n; ++i) {
      c0[i] = c0[i - 1] + b0[i];
      c1[i] = c1[i - 1] + b1[i];
    }
    while (q--) {
      int l, r, k;
      cin >> l >> r >> k;
      int rs0 = (a0[l] ? 1 : 0) + (c0[r] - c0[l]);
      int rs1 = (a1[l] ? 1 : 0) + (c1[r] - c1[l]);
      int mn = rs0 < rs1 ? rs0 : rs1;
      if (mn <= k) cout << "YES\n";
      else cout << "NO\n";
    }
  }
  return 0;
}
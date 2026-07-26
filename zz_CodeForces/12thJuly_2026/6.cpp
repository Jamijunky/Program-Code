#include <bits/stdc++.h>
using namespace std;

void xp() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<int> ops;
  auto ap = [&](int id) {
    int x = a[id - 1], y = a[id];
    a.erase(a.begin() + id - 1, a.begin() + id + 1);
    a.insert(a.begin(), x);
    a.push_back(y);
    ops.push_back(id);
  };
  int lim = 4 * n + 5;
  for (int i = 1; i <= n; ++i) {
    int pos = -1;
    for (int j = 0; j < n; ++j) if (a[j] == i) { pos = j; break; }
    while (pos != i - 1) {
      if ((int)ops.size() > lim) { cout << -1 << '\n'; return; }
      if (pos < n - 1) {
        ap(pos + 1);
        pos = 0;
        for (int j = 0; j < n; ++j) if (a[j] == i) { pos = j; break; }
      } else {
        if (n > 2) {
          ap(1);
          pos -= 2;
          if (pos < 0) pos = 0;
          for (int j = 0; j < n; ++j) if (a[j] == i) { pos = j; break; }
        } else {
          break;
        }
      }
    }
  }
  bool ok = true;
  for (int i = 0; i < n; ++i) if (a[i] != i + 1) ok = false;
  if (!ok || (int)ops.size() > 4 * n) { cout << -1 << '\n'; return; }
  cout << ops.size() << '\n';
  for (int i = 0; i < (int)ops.size(); ++i) {
    if (i) cout << ' ';
    cout << ops[i];
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) xp();
  return 0;
}
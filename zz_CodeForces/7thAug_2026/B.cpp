#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9;
const ll LINF = 1e18;

void Solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) cin >> x;

  vector<int> col, len;
  for (int x : a) {
    if (col.empty() || col.back() != x) {
      col.push_back(x);
      len.push_back(1);
    } else {
      len.back()++;
    }
  }

  int m = (int)col.size();
  int extra = 0;

  for (int i = 0; i + 1 < m; ++i) {
    if (len[i] >= 2 && len[i + 1] >= 2) {
      extra = 2;
      break;
    }
  }

  if (extra == 0) {
    for (int i = 0; i < m; ++i) {
      if (len[i] < 2) continue;
      bool ok = false;
      if (i + 1 < m) {
        if (i + 2 >= m || col[i] != col[i + 2]) ok = true;
      }
      if (!ok && i - 1 >= 0) {
        if (i - 2 < 0 || col[i] != col[i - 2]) ok = true;
      }
      if (ok) {
        extra = 1;
        break;
      }
    }
  }

  cout << m + extra << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

#ifndef ONLINE_JUDGE
  freopen("IO/input.txt", "r", stdin);
  freopen("IO/output.txt", "w", stdout);
#endif

  int t = 1;
  cin >> t;
  while (t--) {
    Solve();
  }

  return 0;
}
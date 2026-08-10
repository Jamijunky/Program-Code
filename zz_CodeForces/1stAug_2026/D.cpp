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
  int n, q;
  cin >> n >> q;
  string s, t;
  cin >> s >> t;
  
  vector<int> prefA(n + 1, 0), prefB(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    prefA[i + 1] = prefA[i] + (s[i] == '0' && t[i] == '1');
    prefB[i + 1] = prefB[i] + (s[i] == '1' && t[i] == '0');
  }
  
  while (q--) {
    int l, r;
    cin >> l >> r;
    int a = prefA[r] - prefA[l - 1];
    int b = prefB[r] - prefB[l - 1];
    cout << (2 * max(a, b) <= r - l + 1 ? "YES\n" : "NO\n");
  }
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
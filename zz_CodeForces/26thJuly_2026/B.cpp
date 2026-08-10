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
  int n, k;
  cin >> n >> k;

  if (k == n - 1) {
    cout << -1 << '\n';
    return;
  }

  int runs = n - k;                 // number of blocks of equal characters
  int zeroRuns = (runs + 1) / 2;    // runs starting with '0' (ceil(runs/2))
  int oneRuns = runs - zeroRuns;    // runs starting with '1'

  int zeros = (n + 1) / 2;          // count of '0' (ceil(n/2))
  int ones = n - zeros;             // count of '1'

  int extraZeros = zeros - zeroRuns;
  int extraOnes = ones - oneRuns;

  string ans;
  ans.reserve(n);

  for (int i = 0; i < runs; ++i) {
    char c = (i & 1) ? '1' : '0';
    int len = 1;

    // add the extra characters to the first run of each type
    if (i == 0) len += extraZeros;
    else if (i == 1) len += extraOnes;

    ans.append(len, c);
  }

  cout << ans << '\n';
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
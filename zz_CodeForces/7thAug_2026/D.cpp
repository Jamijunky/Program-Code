#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9;
const ll LINF = 1e18;

string construct_string(ll N, ll p) {
  string res = "";
  res.reserve(N);
  ll rem_p = p;

  for (ll j = 1; j <= N; ++j) {
    ll w = N - j + 1;
    ll rem_len = N - j;
    ll max_rem = (rem_len * (rem_len + 1)) / 2;

    if (rem_p - w >= 0 && rem_p - w <= max_rem) {
      res += 'X';
      rem_p -= w;
    } else {
      res += 'Y';
    }
  }
  return res;
}

void Solve() {
  ll x, y;
  if (!(cin >> x >> y)) return;

  ll max_N = (sqrt(1.0 + 8.0 * (x + y)) - 1.0) / 2.0;

  ll best_dist = LINF;
  ll best_N = 0;
  ll best_p = 0;

  ll start_N = max(0LL, max_N - 5);

  for (ll N = start_N; N <= max_N; ++N) {
    ll S = N * (N + 1) / 2;
    ll p_min = max(0LL, S - y);
    ll p_max = min(S, x);

    if (p_min <= p_max) {
      ll ideal_p = round((ld)(x - y + S) / 2.0);
      ll p = max(p_min, min(p_max, ideal_p));
      ll q = S - p;

      ll dist = (x - p) * (x - p) + (y - q) * (y - q);
      if (dist < best_dist) {
        best_dist = dist;
        best_N = N;
        best_p = p;
      }
    }
  }

  cout << construct_string(best_N, best_p) << "\n";
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
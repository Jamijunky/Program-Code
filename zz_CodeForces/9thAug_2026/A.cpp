#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9;
const ll LINF = 1e18;

void Solve()
{
  int n;
  ll k;
  if (!(cin >> n >> k))
    return;

  string s;
  cin >> s;

  int N = 2 * n;
  int red_score = 0;
  int blue_score = 0;

  for (int i = 0; i < N; ++i)
  {
    if (s[i] == '1')
    {
      int next_idx = (i + 1) % N;
      int final_idx = i;

      if (s[next_idx] == '0')
      {
        final_idx = next_idx;
      }
      if (final_idx % 2 == 1)
      {
        red_score++;
      }
      else
      {
        blue_score++;
      }
    }
  }

  cout << red_score << " " << blue_score << "\n";
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

#ifndef ONLINE_JUDGE
  freopen("IO/input.txt", "r", stdin);
  freopen("IO/output.txt", "w", stdout);
#endif

  int t = 1;
  cin >> t;

  while (t--)
  {
    Solve();
  }

  return 0;
}
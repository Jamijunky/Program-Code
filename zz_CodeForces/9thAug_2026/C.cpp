#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9;
const ll LINF = 1e18;

string mode;

void Solve()
{
  int n;
  cin >> n;

  vector<string> grid(n);
  for (int i = 0; i < n; ++i)
  {
    cin >> grid[i];
  }

  if (mode == "first")
  {
    int rx, cx;
    cin >> rx >> cx;
    --rx;
    --cx;

    ll Sr = 0, Sc = 0;
    for (int r = 0; r < n; ++r)
    {
      for (int c = 0; c < n; ++c)
      {
        if (grid[r][c] == '#')
        {
          Sr = (Sr + (r - rx + n) % n) % n;
          Sc = (Sc + (c - cx + n) % n) % n;
        }
      }
    }

    int Dr = (n - Sr % n) % n;
    int Dc = (n - Sc % n) % n;

    if (Dr == 0 && Dc == 0)
    {
      cout << "1 1 1 1\n";
      return;
    }

    bool swapped = false;
    for (int r = 0; r < n && !swapped; ++r)
    {
      for (int c = 0; c < n && !swapped; ++c)
      {
        if (grid[r][c] == '#')
        {
          int nr = (r + Dr) % n;
          int nc = (c + Dc) % n;
          if (grid[nr][nc] == '.')
          {
            cout << r + 1 << " " << c + 1 << " " << nr + 1 << " " << nc + 1 << "\n";
            swapped = true;
          }
        }
      }
    }
  }
  else
  {
    vector<int> row_cnt(n, 0), col_cnt(n, 0);
    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        if (grid[i][j] == '#')
        {
          row_cnt[i]++;
          col_cnt[j]++;
        }
      }
    }

    int target_r = -1, target_c = -1;

    for (int r = 0; r < n; ++r)
    {
      ll Sr = 0;
      for (int i = 0; i < n; ++i)
      {
        Sr = (Sr + (ll)row_cnt[i] * ((i - r + n) % n)) % n;
      }
      if (Sr == 0)
      {
        target_r = r;
        break;
      }
    }

    for (int c = 0; c < n; ++c)
    {
      ll Sc = 0;
      for (int j = 0; j < n; ++j)
      {
        Sc = (Sc + (ll)col_cnt[j] * ((j - c + n) % n)) % n;
      }
      if (Sc == 0)
      {
        target_c = c;
        break;
      }
    }

    cout << target_r + 1 << " " << target_c + 1 << "\n";
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

#ifndef ONLINE_JUDGE
  freopen("IO/input.txt", "r", stdin);
  freopen("IO/output.txt", "w", stdout);
#endif

  if (cin >> mode)
  {
    int t = 1;
    cin >> t;

    while (t--)
    {
      Solve();
    }
  }

  return 0;
}
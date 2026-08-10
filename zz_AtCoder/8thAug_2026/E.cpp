#include <bits/stdc++.h>
using namespace std;

int N, L;
vector<vector<vector<long double>>> dp;

long double solve(int life, int c, int u)
{
  if (life == 0 || c + u == 0)
    return 0.0L;
  long double &res = dp[life][c][u];
  if (res >= 0.0L)
    return res;

  int M = c + 2 * u;
  long double best = 0.0L;

  if (c > 0)
  {
    long double best_second = -1e100L;

    if (c >= 2)
    {
      long double val = 1.0L + solve(life - 1, c - 1, u);
      best_second = max(best_second, val);
    }

    if (u > 0)
    {
      long double denom = 2.0L * u;
      long double val = 0.0L;

      val += (1.0L / denom) * (1.0L + solve(life, c - 1, u));

      if (c - 1 > 0)
      {
        val += ((long double)(c - 1) / denom) *
               (1.0L + solve(life - 1, c - 1, u));
      }

      if (2 * u - c > 0)
      {
        val += ((long double)(2 * u - c) / denom) *
               solve(life - 1, c + 1, u - 1);
      }

      best_second = max(best_second, val);
    }

    best = max(best, best_second);
  }

  if (u > 0)
  {
    long double best_second = -1e100L;

    if (c > 0)
    {
      long double val = 1.0L + solve(life - 1, c, u - 1);
      best_second = max(best_second, val);
    }

    {
      long double denom = 2.0L * u - 1.0L;
      if (denom > 0)
      {
        long double val = 0.0L;

        val += (1.0L / denom) * (1.0L + solve(life, c, u - 1));

        if (c > 0)
        {
          val += ((long double)c / denom) *
                 (1.0L + solve(life - 1, c, u - 1));
        }

        if (u - 1 > 0)
        {
          val += ((long double)(2 * (u - 1)) / denom) *
                 solve(life - 1, c + 2, u - 2);
        }

        best_second = max(best_second, val);
      }
    }

    best = max(best, best_second);
  }

  res = best;
  return res;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> L;

  long double sumA = 0.0L;
  for (int i = 0; i < N; ++i)
  {
    long double a;
    cin >> a;
    sumA += a;
  }

  dp.assign(L + 1, vector<vector<long double>>(N + 1, vector<long double>(N + 1, -1.0L)));

  long double expected_pairs = solve(L, 0, N);
  long double ans = (sumA / (long double)N) * expected_pairs;

  cout << fixed << setprecision(10) << (double)ans << '\n';

  return 0;
}
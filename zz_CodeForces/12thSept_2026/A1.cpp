#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n;
  cin >> n;

  vector<int> a(n + 1);
  for (int k = 1; k <= n; k++)
    cin >> a[k];

  vector<int> diff(n + 1, 0);

  for (int k = 1; k <= n; k++)
  {
    int m = a[k];

    int l = m * k;
    int r = min(n - 1, (m + 1) * k - 1);

    if (l < n)
    {
      diff[l]++;
      if (r + 1 < n)
        diff[r + 1]--;
    }
  }

  vector<bool> forbidden(n);
  int cur = 0;

  for (int i = 0; i < n; i++)
  {
    cur += diff[i];
    forbidden[i] = (cur > 0);
  }

  vector<int> prev(n, -1);

  for (int i = 0, last = -1; i < n; i++)
  {
    if (!forbidden[i])
      last = i;
    prev[i] = last;
  }

  vector<pair<int, int>> intervals;

  for (int k = 1; k <= n; k++)
  {
    int m = a[k];

    for (int j = 0; j < m; j++)
    {
      int l = j * k;
      int r = min(n - 1, (j + 1) * k - 1);

      intervals.push_back({r, l});
    }
  }

  sort(intervals.begin(), intervals.end());

  vector<int> B;
  int lastChosen = -1;

  for (auto [r, l] : intervals)
  {
    if (lastChosen >= l)
      continue;

    int x = prev[r];

    if (x < l)
      continue;

    B.push_back(x);
    lastChosen = x;
  }

  cout << B.size() << '\n';

  for (int x : B)
    cout << x << ' ';

  cout << '\n';
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}
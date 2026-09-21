#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n;
  cin >> n;

  vector<int> a(n + 1), b(n + 1);

  for (int i = 1; i <= n; i++)
    cin >> a[i];

  for (int i = 1; i <= n; i++)
    cin >> b[i];

  for (int i = 1; i <= n; i++)
  {
    if (a[i] > b[i])
    {
      cout << -1 << '\n';
      return;
    }
  }

  vector<int> active(n + 1, 0);
  vector<int> vertices;

  for (int i = 1; i <= n; i++)
  {
    if (a[i] < b[i])
    {
      active[i] = 1;
      vertices.push_back(i);
    }
  }

  if (vertices.empty())
  {
    cout << "0 1\n\n";
    return;
  }

  vector<int> done(n + 1, 0);
  vector<int> ans;

  int p = vertices[0];
  int finished = 0;

  while (finished < (int)vertices.size())
  {
    if (active[p] && !done[p])
    {
      while (a[p] < b[p])
      {
        ++a[p];
        ans.push_back(1);
      }

      done[p] = 1;
      ++finished;

      p = a[p];
      ans.push_back(2);

      if (finished == (int)vertices.size())
        break;
    }

    vector<int> par(n + 1, -1);
    par[p] = 0;

    set<int> unseen;
    for (int i = 1; i <= n; i++)
    {
      if (i != p)
        unseen.insert(i);
    }

    queue<int> q;
    q.push(p);

    while (!q.empty())
    {
      int v = q.front();
      q.pop();

      int l, r;

      if (a[v] == b[v])
      {
        l = r = b[v];
      }
      else
      {
        l = a[v];
        r = b[v] - 1;
      }

      auto it = unseen.lower_bound(l);

      while (it != unseen.end() && *it <= r)
      {
        int x = *it;

        par[x] = v;
        q.push(x);

        it = unseen.erase(it);
      }
    }

    int target = -1;

    for (int x : vertices)
    {
      if (!done[x] && par[x] != -1)
      {
        target = x;
        break;
      }
    }

    if (target == -1)
    {
      cout << -1 << '\n';
      return;
    }

    vector<int> path;

    int cur = target;

    while (cur != p)
    {
      path.push_back(cur);
      cur = par[cur];
    }

    path.push_back(p);
    reverse(path.begin(), path.end());

    for (int i = 0; i + 1 < (int)path.size(); i++)
    {
      int v = path[i];
      int x = path[i + 1];

      while (a[v] < x)
      {
        ++a[v];
        ans.push_back(1);
      }

      if (a[v] != x)
      {
        cout << -1 << '\n';
        return;
      }

      ans.push_back(2);
      p = x;
    }
  }

  if (a != b)
  {
    cout << -1 << '\n';
    return;
  }

  if ((int)ans.size() > 2 * n * n)
  {
    cout << -1 << '\n';
    return;
  }

  cout << ans.size() << ' ' << vertices[0] << '\n';

  for (int x : ans)
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
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while (T--)
  {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < M; i++)
    {
      int a, b;
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    vector<int> color(N + 1, -1), parent(N + 1, -1), depth(N + 1, 0);
    queue<int> q;

    color[1] = 0;
    parent[1] = 0;
    depth[1] = 0;
    q.push(1);

    bool found = false;
    int u_conf = -1, v_conf = -1;

    while (!q.empty() && !found)
    {
      int u = q.front();
      q.pop();

      for (int v : adj[u])
      {
        if (color[v] == -1)
        {
          color[v] = color[u] ^ 1;
          parent[v] = u;
          depth[v] = depth[u] + 1;
          q.push(v);
        }
        else if (color[v] == color[u])
        {
          u_conf = u;
          v_conf = v;
          found = true;
          break;
        }
      }
    }

    if (!found)
    {
      cout << -1 << '\n';
      continue;
    }

    int u = u_conf, v = v_conf;
    vector<int> left, right;

    while (depth[u] > depth[v])
    {
      left.push_back(u);
      u = parent[u];
    }
    while (depth[v] > depth[u])
    {
      right.push_back(v);
      v = parent[v];
    }

    while (u != v)
    {
      left.push_back(u);
      right.push_back(v);
      u = parent[u];
      v = parent[v];
    }

    left.push_back(u);
    reverse(right.begin(), right.end());

    vector<int> cycle;
    cycle.insert(cycle.end(), left.begin(), left.end());
    cycle.insert(cycle.end(), right.begin(), right.end());

    cout << cycle.size() << '\n';
    for (int i = 0; i < (int)cycle.size(); i++)
    {
      if (i)
        cout << ' ';
      cout << cycle[i];
    }
    cout << '\n';
  }

  return 0;
}
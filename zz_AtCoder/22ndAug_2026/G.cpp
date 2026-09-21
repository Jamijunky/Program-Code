#include <bits/stdc++.h>
using namespace std;

struct Dinic
{
  struct Edge
  {
    int to, rev;
    long long cap;
  };
  int n;
  vector<vector<Edge>> g;
  vector<int> level, it;

  Dinic(int n) : n(n), g(n), level(n), it(n) {}

  void addEdge(int from, int to, long long cap)
  {
    if (cap <= 0)
      return;
    g[from].push_back({to, (int)g[to].size(), cap});
    g[to].push_back({from, (int)g[from].size() - 1, 0});
  }

  bool bfs(int s, int t)
  {
    fill(level.begin(), level.end(), -1);
    queue<int> q;
    level[s] = 0;
    q.push(s);
    while (!q.empty())
    {
      int v = q.front();
      q.pop();
      for (auto &e : g[v])
      {
        if (e.cap > 0 && level[e.to] < 0)
        {
          level[e.to] = level[v] + 1;
          q.push(e.to);
        }
      }
    }
    return level[t] >= 0;
  }

  long long dfs(int v, int t, long long f)
  {
    if (v == t)
      return f;
    for (int &i = it[v]; i < (int)g[v].size(); i++)
    {
      Edge &e = g[v][i];
      if (e.cap > 0 && level[v] < level[e.to])
      {
        long long ret = dfs(e.to, t, min(f, e.cap));
        if (ret > 0)
        {
          e.cap -= ret;
          g[e.to][e.rev].cap += ret;
          return ret;
        }
      }
    }
    return 0;
  }

  long long maxFlow(int s, int t)
  {
    long long flow = 0;
    const long long INF = 1e18;
    while (bfs(s, t))
    {
      fill(it.begin(), it.end(), 0);
      while (true)
      {
        long long f = dfs(s, t, INF);
        if (!f)
          break;
        flow += f;
      }
    }
    return flow;
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int H, W;
  cin >> H >> W;

  vector<string> S(H);
  for (int i = 0; i < H; i++)
    cin >> S[i];

  vector<int> id(H * W, -1);
  vector<int> w;
  int V = 0;

  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      if (S[i][j] != '#')
      {
        id[i * W + j] = V++;
        w.push_back(S[i][j] == '+' ? 1 : -1);
      }
    }
  }

  const long long INF = 1e18;
  int SRC = V, SNK = V + 1;
  Dinic dinic(V + 2);

  long long sumPos = 0;

  for (int v = 0; v < V; v++)
  {
    if (w[v] > 0)
    {
      dinic.addEdge(SRC, v, w[v]);
      sumPos += w[v];
    }
    else
    {
      dinic.addEdge(v, SNK, -w[v]);
    }
  }

  int dr[3] = {0, 0, 1};
  int dc[3] = {-1, 1, 0};

  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      if (id[i * W + j] == -1)
        continue;
      int u = id[i * W + j];
      for (int d = 0; d < 3; d++)
      {
        int ni = i + dr[d];
        int nj = j + dc[d];
        if (ni < 0 || ni >= H || nj < 0 || nj >= W)
          continue;
        if (id[ni * W + nj] == -1)
          continue;
        int v = id[ni * W + nj];
       
        dinic.addEdge(v, u, INF);
      }
    }
  }

  long long flow = dinic.maxFlow(SRC, SNK);
  long long ans = sumPos - flow;

  cout << ans << '\n';

  return 0;
}
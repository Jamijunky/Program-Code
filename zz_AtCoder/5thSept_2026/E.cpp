#include <bits/stdc++.h>
using namespace std;

struct DSU
{
  vector<int> p, sz;
  DSU(int n = 0) : p(n), sz(n, 1)
  {
    iota(p.begin(), p.end(), 0);
  }
  int find(int x)
  {
    return p[x] == x ? x : p[x] = find(p[x]);
  }
  void unite(int a, int b)
  {
    a = find(a);
    b = find(b);
    if (a == b)
      return;
    if (sz[a] < sz[b])
      swap(a, b);
    p[b] = a;
    sz[a] += sz[b];
  }
};

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

    DSU dsu1(N), dsu2(N), dsu3(N);

    for (int i = 0; i < M; i++)
    {
      int u, v, l;
      cin >> u >> v >> l;
      --u;
      --v;
      if (l == 1)
        dsu1.unite(u, v);
      else if (l == 2)
        dsu2.unite(u, v);
      else
        dsu3.unite(u, v);
    }

    auto get_comp = [&](DSU &dsu)
    {
      vector<int> root(N);
      for (int i = 0; i < N; i++)
        root[i] = dsu.find(i);
      vector<int> vals = root;
      sort(vals.begin(), vals.end());
      vals.erase(unique(vals.begin(), vals.end()), vals.end());
      vector<int> comp(N);
      for (int i = 0; i < N; i++)
      {
        comp[i] = lower_bound(vals.begin(), vals.end(), root[i]) - vals.begin();
      }
      return comp;
    };

    vector<int> c1 = get_comp(dsu1);
    vector<int> c2 = get_comp(dsu2);
    vector<int> c3 = get_comp(dsu3);

    vector<pair<int, int>> pairs(N);
    for (int i = 0; i < N; i++)
      pairs[i] = {c2[i], c3[i]};

    vector<pair<int, int>> upairs = pairs;
    sort(upairs.begin(), upairs.end());
    upairs.erase(unique(upairs.begin(), upairs.end()), upairs.end());

    vector<int> pid(N);
    for (int i = 0; i < N; i++)
    {
      pid[i] = lower_bound(upairs.begin(), upairs.end(), pairs[i]) - upairs.begin();
    }

    int C1 = *max_element(c1.begin(), c1.end()) + 1;
    int P = (int)upairs.size();

    vector<pair<int, int>> edges;
    edges.reserve(N);
    for (int i = 0; i < N; i++)
    {
      edges.emplace_back(c1[i], pid[i]);
    }
    sort(edges.begin(), edges.end());
    edges.erase(unique(edges.begin(), edges.end()), edges.end());

    vector<vector<int>> adjC1(C1), adjP(P);
    for (auto &e : edges)
    {
      adjC1[e.first].push_back(e.second);
      adjP[e.second].push_back(e.first);
    }

    int start = c1[0];
    vector<char> visC1(C1, 0), visP(P, 0);
    queue<int> q;
    visC1[start] = 1;
    q.push(start);

    while (!q.empty())
    {
      int c = q.front();
      q.pop();
      for (int p : adjC1[c])
      {
        if (!visP[p])
        {
          visP[p] = 1;
          for (int nc : adjP[p])
          {
            if (!visC1[nc])
            {
              visC1[nc] = 1;
              q.push(nc);
            }
          }
        }
      }
    }

    vector<int> ans;
    for (int i = 0; i < N; i++)
    {
      if (visC1[c1[i]])
        ans.push_back(i + 1);
    }

    cout << ans.size() << '\n';
    for (int i = 0; i < (int)ans.size(); i++)
    {
      if (i)
        cout << ' ';
      cout << ans[i];
    }
    cout << '\n';
  }

  return 0;
}
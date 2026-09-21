#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> shortestPathCompute(vector<vector<int>>& adj, int from, int to)
{
    int n = adj.size();
    vector<int> parent(n, -1);
    vector<bool> visited(n, false);
    queue<int> q;

    visited[from] = true;
    q.push(from);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        if (u == to)
            break;

        for (int v : adj[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    if (!visited[to])
        return {};

    vector<int> path;

    for (int v = to; v != -1; v = parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());

    return path;
}

int main()
{
    int V = 8, E = 10;
    int S = 2, D = 6;

    vector<vector<int>> edges = {
        {0, 1}, {1, 2}, {0, 3}, {3, 4}, {4, 7},
        {3, 7}, {6, 7}, {4, 5}, {4, 6}, {5, 6}
    };

    vector<vector<int>> adj(V);

    for (auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<int> shortestPath = shortestPathCompute(adj, S, D);

    for (int v : shortestPath)
        cout << v << " ";

    return 0;
}
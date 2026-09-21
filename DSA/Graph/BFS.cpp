#include <iostream>

#include <vector>

using namespace std;

vector<int> BFS(vector<vector<int>> &adj)
{
  int n = adj.size();
  vector<int> visited(n, false);
  vector<int> result;

  int currPos = 0;
  queue<int> q;
  visited[currPos] = false;
  q.push(currPos);

  while (!q.empty())
  {

      int curr = q.front();
      q.pop();
      result.push_back(curr);

      for (int i : adj[curr])
      {
        if (!visited[i])
        {
          visited[i] = true;
          q.push(i);
        }
      }
    }

    return result;
  }

  void addEdge(vector<vector<int>> & adj, int u, int v)
  {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int main()
  {
    int V = 6;
    vector<vector<int>> adj(V);

    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 0, 3);
    addEdge(adj, 4, 5);

    vector<int> result = BFS(adj);
    for (int i : result)
    {
      cout << i << " ";
    }

    return 0;
  }
#include <iostream>
#include <vector>

using namespace std;

void getDFS(vector<vector<int>> &adj, int pos, vector<bool> &visited, vector<int> &result)
{
  visited[pos] = true;
  result.push_back(pos);

  for (int i : adj[pos])
  {
    if (visited[i] == false)
      getDFS(adj, i, visited, result);
  }
}

vector<int> dfs(vector<vector<int>> & adj)
{
  vector<bool> visited(adj.size(), false);
  vector<int> result;
  getDFS(adj, 0, visited, result);
  return result;
}

void addEdge(vector<vector<int>> &adj, int u, int v)
{
  adj[u].push_back(v);
  adj[v].push_back(u);
}

int main()
{
  int V = 5;
  vector<vector<int>> adj(V);

  addEdge(adj, 1, 2);
  addEdge(adj, 1, 0);
  addEdge(adj, 2, 0);
  addEdge(adj, 2, 3);
  addEdge(adj, 2, 4);

  vector<int> result = dfs(adj);
  for(int i:result)
  cout<<result[i]<<",";

  return 0;
}
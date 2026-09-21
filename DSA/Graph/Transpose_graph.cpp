#include <iostream>
#include <vector>

using namespace std;

void display(vector<int> transpose[], vector<int> adj[], int v)
{
  for (int i = 0; i < v; i++)
  {
    cout << i << "--->";
    for (int j = 0; j < adj[i].size(); j++)
    {
      cout << adj[i][j] << " ";
      cout << endl;
    }
  }
}

void addEdge(vector<int> adj[], int from, int to)
{
  adj[from].push_back(to);
}

void getTranspose(vector<int> adj[], vector<int> transpose[], int v)
{
  for (int i = 0; i < v; i++)
    for (int j = 0; j < adj[i].size(); j++)
      addEdge(transpose, adj[i][j], i);
}

int main()
{
  int v = 5;
  vector<int> adj[v];
  addEdge(adj, 0, 1);
  addEdge(adj, 0, 4);
  addEdge(adj, 0, 3);
  addEdge(adj, 2, 0);
  addEdge(adj, 3, 2);
  addEdge(adj, 4, 1);
  addEdge(adj, 4, 3);

  vector<int> transpose[v];
  getTranspose(adj, transpose, v);
  display(transpose, adj, v);

  return 0;
}
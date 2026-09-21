#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> makeMatrix(int V, vector<vector<int>> edges)
{
  vector<vector<int>> adjMatrix(V, vector<int>(V, 0));

  for (auto i : edges)
  {
    int u = i[0];
    int v = i[1];
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1; // remove this line for directed graph
  }
  return adjMatrix;
}

int main()
{

  int V = 3;

  vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}};

  vector<vector<int>> adjMatrix = makeMatrix(V, edges);
  cout << "Adjacency Matrix Representation:" << endl;
  for (int i = 0; i < V; i++)
  {
    for (int j = 0; j < V; j++)
      cout << adjMatrix[i][j] << " ";
    cout << endl;
  }

  return 0;
}
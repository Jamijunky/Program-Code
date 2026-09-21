#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<int, vector<int>> makeList(int V, vector<vector<int>> edges)
{
  map<int, vector<int>> adjList;
  for (auto i : edges)
  {
    int u = i[0];
    int v = i[1]; 

    adjList[u].push_back(v);
    adjList[v].push_back(u); // remove this for undirected graph
  }

  return adjList;
}

int main()
{
  int V = 3;

  vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}};

  map<int, vector<int>> adjList = makeList(V, edges);
  for (auto i : adjList)
  {
    cout << i.first << "--->";
     for (int j : i.second)
    {
      cout << j << " ";
    }
    cout << endl;
  }

  return 0;
}
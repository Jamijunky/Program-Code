#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> dijkstra(vector<vector<pair<int,int>>> adj,int src){
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
  for(auto idx : adj){
    for(auto i : adj[idx])
    pq[i.first].push(i.second);
  }
}

int main()
{

  int src = 0;

  vector<vector<pair<int, int>>> adj(5);
  adj[0] = {{1, 4}, {2, 8}};
  adj[1] = {{0, 4}, {4, 6}, {2, 3}};
  adj[2] = {{0, 8}, {3, 2}, {1, 3}};
  adj[3] = {{2, 2}, {4, 10}};
  adj[4] = {{1, 6}, {3, 10}};

  vector<int> weight=dijkstra(adj,src);

  return 0;
}
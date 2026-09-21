#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> Order(vector<vector<int>> adj, vector<int> inDegree, int n)
{
    queue<int> q;
    vector<int> topologicalOrder;

    for (int i = 0; i < n; i++)
    {
        if (inDegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int top = q.front();
        q.pop();

        topologicalOrder.push_back(top);

        for (int next : adj[top])
        {
            inDegree[next]--;

            if (inDegree[next] == 0)
                q.push(next);
        }
    }

    return topologicalOrder;
}

void addEdge(vector<vector<int>> &adj, int from, int to, vector<int> &inDegree)
{
    adj[from].push_back(to);
    inDegree[to]++;
}

int main()
{
    int n = 6;

    vector<vector<int>> adj(n);
    vector<int> inDegree(n, 0);

    addEdge(adj, 0, 1, inDegree);
    addEdge(adj, 1, 2, inDegree);
    addEdge(adj, 2, 3, inDegree);
    addEdge(adj, 4, 5, inDegree);
    addEdge(adj, 5, 1, inDegree);
    addEdge(adj, 5, 2, inDegree);

    vector<int> topologicalOrder = Order(adj, inDegree, n);

    for (int vertex : topologicalOrder)
        cout << vertex << " ";

    cout << endl;

    return 0;
}
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int cost[10][10];
    int dist[10][10];

    // Input cost matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
            dist[i][j] = cost[i][j];
        }
    }

    int updated;

    do {
        updated = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (dist[i][j] > cost[i][k] + dist[k][j]) {
                        dist[i][j] = cost[i][k] + dist[k][j];
                        updated = 1;
                    }
                }
            }
        }

    } while (updated);

    // Output routing tables
    for (int i = 0; i < n; i++) {
        cout << "Routing table for node " << i << ":\n";
        for (int j = 0; j < n; j++) {
            cout << "To node " << j << " distance " << dist[i][j] << "\n";
        }
        cout << "\n";
    }

    return 0;
}
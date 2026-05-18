#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n, m;

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter number of resources: ";
    cin >> m;

    vector<vector<int>> alloc(n, vector<int>(m));
    vector<vector<int>> max(n, vector<int>(m));
    vector<vector<int>> need(n, vector<int>(m));
    vector<int> avail(m);

    cout << "\nEnter Allocation Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> alloc[i][j];
        }
    }

    cout << "\nEnter Max Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> max[i][j];
        }
    }

    cout << "\nEnter Available Resources:\n";
    for (int i = 0; i < m; i++) {
        cin >> avail[i];
    }

    // Calculate Need Matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    vector<bool> finish(n, false);
    vector<int> safeSeq;
    vector<int> work = avail;

    int count = 0;

    while (count < n) {

        bool found = false;

        for (int i = 0; i < n; i++) {

            if (!finish[i]) {

                bool canExecute = true;

                for (int j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        canExecute = false;
                        break;
                    }
                }

                if (canExecute) {

                    for (int j = 0; j < m; j++) {
                        work[j] += alloc[i][j];
                    }

                    safeSeq.push_back(i);
                    finish[i] = true;
                    found = true;
                    count++;
                }
            }
        }

        if (!found) {
            break;
        }
    }

    if (count == n) {

        cout << "\nSystem is in SAFE state.\n";
        cout << "Safe Sequence: ";

        for (int i = 0; i < n; i++) {
            cout << "P" << safeSeq[i];
            if (i != n - 1)
                cout << " -> ";
        }

        cout << endl;

    } else {

        cout << "\nSystem is NOT in safe state (Deadlock Possible).\n";
    }

    return 0;
}
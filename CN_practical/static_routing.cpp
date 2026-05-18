#include <iostream>
using namespace std;

struct Route {
    int destination;
    int nextHop;
};

int main() {
    int n;

    cout << "Enter number of routes: ";
    cin >> n;

    Route table[20];

    // Input routing table
    for (int i = 0; i < n; i++) {
        cout << "Enter destination and next hop for route " << i + 1 << ": ";
        cin >> table[i].destination >> table[i].nextHop;
    }

    int dest;
    cout << "\nEnter destination node to route packet: ";
    cin >> dest;

    bool found = false;

    // Search routing table
    for (int i = 0; i < n; i++) {
        if (table[i].destination == dest) {
            cout << "Packet forwarded to next hop node: "
                 << table[i].nextHop;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Destination not found in routing table.";
    }

    return 0;
}
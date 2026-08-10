#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<int> A(N + 1, 0);
    set<int> positive;
    int xorsum = 0;

    string line;
    getline(cin, line); 

    while (Q--) {
        getline(cin, line);
        stringstream ss(line);
        int type;
        ss >> type;

        if (type == 1) {
            int x;
            ss >> x;
            int old = A[x];
            if (old == 0) positive.insert(x);
            int nw = old + 1;
            A[x] = nw;
            xorsum ^= old ^ nw;
        } else {  
            for (auto it = positive.begin(); it != positive.end(); ) {
                int idx = *it;
                int old = A[idx];
                int nw = old - 1;
                A[idx] = nw;
                xorsum ^= old ^ nw;

                if (nw == 0) {
                    it = positive.erase(it);
                } else {
                    ++it;
                }
            }
        }

        cout << xorsum << '\n';
    }

    return 0;
}
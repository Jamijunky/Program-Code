#include <bits/stdc++.h>
using namespace std;

void Solve() {
    int n;
    cin >> n;

    vector<int> l(n + 1), r(n + 1), u(n + 1), v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i] >> u[i] >> v[i];
    }

    auto can = [&](int m) -> bool {
        int prev = 0;
        for (int j = 1; j <= m; j++) {
            int i = prev + 1;
            bool found = false;
            while (i <= n) {
                // check if element i can be placed at rank j
                bool left_ok = (j < l[i] || j > r[i]);
                if (left_ok) {
                    int right_rank = m - j + 1;
                    bool right_ok = (right_rank < u[i] || right_rank > v[i]);
                    if (right_ok) {
                        found = true;
                        break;
                    }
                }
                i++;
            }
            if (!found) return false;
            prev = i;
        }
        return true;
    };

    for (int m = n; m >= 0; m--) {
        if (m == 0) {
            cout << 0 << '\n';
            return;
        }
        if (can(m)) {
            cout << m << '\n';
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("IO/input.txt", "r", stdin);
    freopen("IO/output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--) {
        Solve();
    }
    return 0;
}
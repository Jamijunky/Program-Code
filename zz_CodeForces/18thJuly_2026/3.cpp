#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (int &x : a) cin >> x;
        for (int &x : b) cin >> x;

        if (a == b) {
            cout << 0 << '\n';
            continue;
        }

        long long common_one = 0, common_zero = 0, removed = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] == 1 && b[i] == 0) removed++;
            else if (a[i] == 1 && b[i] == 1) common_one++;
            else if (a[i] == 0 && b[i] == 0) common_zero++;
        }

        if (removed & 1) {
            cout << 1 << '\n';
            continue;
        }

        vector<int> c1_vals = common_one > 0 ? vector<int>{0, 1} : vector<int>{0};
        vector<int> c2_vals = common_zero > 0 ? vector<int>{0, 1} : vector<int>{0};
        vector<int> a_vals = removed > 0 ? vector<int>{0, 1} : vector<int>{0};

        int removed_parity = removed & 1;
        bool ok = false;

        for (int c1 : c1_vals) {
            for (int c2 : c2_vals) {
                for (int A : a_vals) {
                    if ((c1 ^ A) == 1 && (c2 ^ removed_parity ^ A) == 1) {
                        ok = true;
                    }
                }
            }
        }

        cout << (ok ? 2 : -1) << '\n';
    }

    return 0;
}
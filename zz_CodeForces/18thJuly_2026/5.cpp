#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        auto get_answer = [&]() -> int {
            vector<pair<int, int>> vp(n);
            for (int i = 0; i < n; ++i) vp[i] = {a[i], i};
            sort(vp.begin(), vp.end());

            vector<int> pi(n);
            for (int r = 0; r < n; ++r) {
                pi[vp[r].second] = r;
            }

            int max_xor = 0;
            for (int i = 0; i < n; ++i) {
                max_xor = max(max_xor, i ^ pi[i]);
            }

            if (max_xor == 0) return 0;
            return 1 << (31 - __builtin_clz(max_xor));
        };

        cout << get_answer() << '\n';

        while (q--) {
            int idx, x;
            cin >> idx >> x;
            --idx;
            a[idx] = x;
            cout << get_answer() << '\n';
        }
    }

    return 0;
}
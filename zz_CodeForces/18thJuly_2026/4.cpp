#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q; // q = 0 in easy version

        vector<pair<int, int>> p;
        p.reserve(n);

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            p.emplace_back(x, i);
        }

        sort(p.begin(), p.end());

        int ans = 0;

        for (int l = 0; l < n; ) {
            int r = l;
            while (r < n && p[r].first == p[l].first) r++;

            int startPos = l;

            for (int offset = 0; offset < r - l; offset++) {
                int idx = p[l + offset].second;
                int target = startPos + offset;

                int x = idx ^ target;
                int cost = 0;

                if (x) {
                    cost = 1 << (31 - __builtin_clz((unsigned)x));
                }

                if (cost > ans) ans = cost;
            }

            l = r;
        }

        cout << ans << '\n';
    }

    return 0;
}
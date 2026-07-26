#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        long long k;
        cin >> n >> k;

        // smallest power of two >= n
        int L = 1;
        while (L < n) L <<= 1;

        if ((k ^ n) >= L) {
            cout << "NO\n";
            continue;
        }

        // n == 1
        if (n == 1) {
            if (k == 1) cout << "YES\n0\n";
            else cout << "NO\n";
            continue;
        }

        // small n: brute force
        if (n <= 8) {
            vector<int> p(n);
            iota(p.begin(), p.end(), 0);
            bool found = false;
            do {
                int cur = 0;
                int mex = 0;
                vector<int> seen(n + 1, 0);
                for (int i = 0; i < n; ++i) {
                    seen[p[i]] = 1;
                    while (seen[mex]) mex++;
                    cur ^= mex;
                }
                if (cur == k) {
                    cout << "YES\n";
                    for (int i = 0; i < n; ++i) {
                        cout << p[i] << (i + 1 == n ? '\n' : ' ');
                    }
                    found = true;
                    break;
                }
            } while (next_permutation(p.begin(), p.end()));
            if (!found) cout << "NO\n";
            continue;
        }

        // construction for large n
        vector<int> pos(n, -1);
        long long x = k ^ n;

        auto fill_rest = [&](int p0, int p1, int p2) {
            vector<int> used(n, 0);
            if (p0 != -1) { pos[0] = p0; used[p0] = 1; }
            if (p1 != -1) { pos[p1] = p1; used[p1] = 1; }
            if (p2 != -1) { pos[p2] = p2; used[p2] = 1; }
            int cur = 0;
            for (int i = 0; i < n; ++i) {
                if (pos[i] != -1) continue;
                while (used[cur]) cur++;
                pos[i] = cur;
                used[cur] = 1;
            }
        };

        if (n & (n - 1)) { // n not power of two
            if (x == 0) {
                // records 0..n-2, gaps 1
                pos[n - 1] = 0;
                for (int i = 0; i < n - 1; ++i) pos[i] = i + 1;
            } else if (x < n) {
                // records {0, x}
                pos[0] = 3;
                pos[x] = 4;
                fill_rest(3, 4, -1);
            } else {
                // find a,b with a^b = x, a<b<n
                bool ok = false;
                for (int a = 1; a < n; ++a) {
                    int b = a ^ x;
                    if (b < n && b > a) {
                        pos[0] = 3;
                        pos[a] = 4;
                        pos[b] = 5;
                        fill_rest(3, 4, 5);
                        ok = true;
                        break;
                    }
                }
                if (!ok) {
                    // fallback: should not happen for valid input
                    cout << "NO\n";
                    continue;
                }
            }
        } else { // n is power of two
            if (k == n) {
                // identity
                for (int i = 0; i < n; ++i) pos[i] = i;
            } else {
                long long y = k ^ n;
                pos[y] = 0;
                int cur = 1;
                for (int i = 0; i < n; ++i) {
                    if (i == y) continue;
                    pos[i] = cur++;
                }
            }
        }

        // build permutation from positions
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[pos[i]] = i;
        }

        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << (i + 1 == n ? '\n' : ' ');
        }
    }

    return 0;
}
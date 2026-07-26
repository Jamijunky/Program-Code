#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int64> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int64 sum_f2 = 0;
        for (int i = 0; i + 1 < n; i++) {
            int64 x = a[i], y = a[i + 1];
            int64 r = y % x;
            sum_f2 += min(r, x - r);
        }

        // total sum of gcd over all subarrays
        int64 total_gcd = 0;
        vector<pair<int64, int64>> cur; // (gcd, count)
        for (int r = 0; r < n; r++) {
            vector<pair<int64, int64>> nxt;
            for (auto [g, cnt] : cur) {
                int64 ng = std::gcd(g, a[r]);
                if (nxt.empty() || nxt.back().first != ng)
                    nxt.push_back({ng, cnt});
                else
                    nxt.back().second += cnt;
            }
            // add new subarray of length 1
            if (nxt.empty() || nxt.back().first != a[r])
                nxt.push_back({a[r], 1});
            else
                nxt.back().second += 1;
            cur = move(nxt);
            for (auto [g, cnt] : cur)
                total_gcd += g * cnt;
        }

        int64 sum_len1 = 0;
        for (int64 x : a) sum_len1 += x;

        int64 sum_len2 = 0;
        for (int i = 0; i + 1 < n; i++)
            sum_len2 += std::gcd(a[i], a[i + 1]);

        int64 sum_gcd_len_ge3 = total_gcd - sum_len1 - sum_len2;

        // sparse table for range gcd queries
        int LOG = 0;
        while ((1 << LOG) <= n) LOG++;
        vector<vector<int64>> st(LOG, vector<int64>(n));
        for (int i = 0; i < n; i++) st[0][i] = a[i];
        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i + (1 << k) <= n; i++) {
                st[k][i] = std::gcd(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
            }
        }
        auto range_gcd = [&](int l, int r) -> int64 {
            if (l > r) return 0;
            int len = r - l + 1;
            int k = 31 - __builtin_clz(len);
            return std::gcd(st[k][l], st[k][r - (1 << k) + 1]);
        };

        int64 sum_gcd_equal_first = 0;
        for (int l = 0; l < n; l++) {
            int64 v = a[l];
            // find first p > l with a[p] % v != 0
            int low = l + 1, high = n - 1, p = n;
            while (low <= high) {
                int mid = (low + high) / 2;
                int64 g = range_gcd(l + 1, mid);
                if (g % v != 0) {
                    p = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // if no such p, p remains n
            int64 cnt = max(0LL, (int64)p - l - 2);
            sum_gcd_equal_first += v * cnt;
        }

        int64 ans = sum_f2 + sum_gcd_len_ge3 - sum_gcd_equal_first;
        cout << ans << '\n';
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    const long long NEG = -(1LL << 60);

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<long long> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];

        vector<char> can(n + 2, 0);
        for (int i = 0; i < m; i++) {
            int b;
            cin >> b;
            can[b] = 1;
        }

        long long dp[2] = {0, NEG}; 

        for (int i = n; i >= 1; i--) {
            long long ndp[2] = {NEG, NEG};

            for (int s = 0; s < 2; s++) {
                if (dp[s] <= NEG / 2) continue;

                long long sign = (s == 0 ? 1 : -1);

                if (can[i]) {
                    ndp[s] = max(ndp[s], dp[s] + a[i] * sign);

                    ndp[1 - s] = max(ndp[1 - s], dp[s] - a[i] * sign);
                } else {
                    ndp[s] = max(ndp[s], dp[s] + a[i] * sign);
                }
            }

            dp[0] = ndp[0];
            dp[1] = ndp[1];
        }

        cout << max(dp[0], dp[1]) << '\n';
    }

    return 0;
}
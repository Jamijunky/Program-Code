#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n, k, m;
        cin >> n >> k >> m;

        if (m < k) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        for (long long i = 1; i <= n; i++) {
            long long x = (i % k == 0 ? m - k + 1 : 1);
            cout << x << (i == n ? '\n' : ' ');
        }
    }

    return 0;
}
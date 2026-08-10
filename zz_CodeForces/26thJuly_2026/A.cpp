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

        long long mxEven = LLONG_MIN, mnOdd = LLONG_MAX;

        for (int i = 1; i <= n; ++i) {
            long long x;
            cin >> x;

            if (i & 1) mnOdd = min(mnOdd, x);
            else mxEven = max(mxEven, x);
        }

        bool ok = (n % 2 == 0 && mxEven < mnOdd && mnOdd - mxEven >= 2);

        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}
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

        vector<long long> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];

        long long carry = 0;
        long long prev = 0;
        bool ok = true;

        for (int i = 1; i < n; i++) {
            long long cur = a[i] + carry;
            long long need = prev + 1;
            if (cur < need) {
                ok = false;
                break;
            }
            carry = cur - need;
            prev = need;
        }

        if (ok) {
            long long last = a[n] + carry;
            if (last <= prev) ok = false;
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}
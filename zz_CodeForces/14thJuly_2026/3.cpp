#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;

        int g = std::gcd(x, y);
        bool ok = true;

        for (int i = 1; i <= n; ++i) {
            int p;
            cin >> p;
            if ((p - i) % g != 0) ok = false;
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;

        long long ans = 0;

        for (long long cost = 1; cost <= n; cost <<= 1) {
            long long take = min(k, n / cost);
            ans += take;
            n -= take * cost;
        }

        cout << ans << '\n';
    }

    return 0;
}
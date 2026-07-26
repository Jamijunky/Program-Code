#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, d;
        cin >> n >> d;

        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        long long neighSum = 0;
        for (int k = 1; k <= d; k++) {
            neighSum += a[k];
            neighSum += a[n - k];
        }

        long long ans = 0;
        int center = 0;

        for (int i = 0; i < n; i++) {
            long long val = 2LL * d * a[i] - neighSum;
            if (val > 0) ans += val;

            if (i != n - 1) {
                neighSum -= a[(center - d + n) % n];
                neighSum -= a[(center + 1) % n];
                neighSum += a[center];
                neighSum += a[(center + d + 1) % n];
                center++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
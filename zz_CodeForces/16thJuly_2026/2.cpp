#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        long long c;
        cin >> n >> c;

        vector<long long> a(n);
        long long sum_all = 0;
        int cnt_less = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum_all += a[i];
            if (a[i] < c) cnt_less++;
        }

        int k = min(cnt_less, n / 2);

        sort(a.begin(), a.end());

        long long sum_smallest = 0;
        for (int i = 0; i < k; i++) {
            sum_smallest += a[i];
        }

        long long ans = sum_all - sum_smallest - c * (n - k);
        cout << ans << '\n';
    }

    return 0;
}
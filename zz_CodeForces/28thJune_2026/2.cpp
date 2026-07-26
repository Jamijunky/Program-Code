#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        long long ans = 0;
        for (int b = 1; b <= N; ++b) {
            long long cnt = N / b;
            ans += cnt * cnt;
        }
        cout << ans << '\n';
    }
    return 0;
}
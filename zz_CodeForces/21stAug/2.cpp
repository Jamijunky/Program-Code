#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> result;

        long long ten = 10;
        while (ten <= n) {
            long long denom = ten + 1;
            if (n % denom == 0) {
                long long x = n / denom;
                result.push_back(x);
            }
            ten *= 10;
        }

        cout << result.size() << "\n";
        if (!result.empty()) {
            sort(result.begin(), result.end());
            for (auto x : result) cout << x << " ";
            cout << "\n";
        }
    }
    return 0;
}

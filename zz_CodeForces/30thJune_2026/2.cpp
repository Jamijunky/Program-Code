#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        long long X;
        cin >> X;

        // Special case: 10^8 has 9 digits, so 10^9 + 1 is too large (> 10^9)
        if (X == 100000000LL) {
            cout << 10 << '\n';
            continue;
        }

        int len = to_string(X).size();

        // Y = 10^len + 1
        // Example: X = 73, len = 2, Y = 101
        string Y = "1" + string(len - 1, '0') + "1";

        cout << Y << '\n';
    }

    return 0;
}
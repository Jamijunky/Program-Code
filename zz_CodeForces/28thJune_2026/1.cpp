#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int rounds;
    cin >> rounds;

    while (rounds--) {
        int len, fee;
        cin >> len >> fee;

        vector<int> left(len), right(len);
        long long delta = 0;
        bool plain = true;

        for (int &v : left) cin >> v;
        for (int &v : right) cin >> v;

        for (int k = 0; k < len; k++) {
            delta += left[k] - right[k];
            if (left[k] < right[k]) plain = false;
        }

        if (delta < 0) {
            cout << -1 << '\n';
            continue;
        }

        auto alpha = left, beta = right;
        sort(alpha.begin(), alpha.end());
        sort(beta.begin(), beta.end());

        bool remix = true;
        for (int k = 0; k < len; k++) {
            if (alpha[k] < beta[k]) {
                remix = false;
                break;
            }
        }

        long long best = (1LL << 60);

        if (plain) best = min(best, delta);
        if (remix) best = min(best, delta + fee);

        cout << (best == (1LL << 60) ? -1 : best) << '\n';
    }
}
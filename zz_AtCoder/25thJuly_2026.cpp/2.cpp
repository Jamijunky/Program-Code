#include <bits/stdc++.h>
using namespace std;

int main() {
    int M, D;
    string S;
    cin >> M >> D >> S;

    vector<int> diff(M + 1, 0);

    for (int i = 0; i < M; ++i) {
        if (S[i] == 'G') {
            int l = max(0, i - D);
            int r = min(M - 1, i + D);
            ++diff[l];
            --diff[r + 1];
        }
    }

    int ans = 0, cur = 0;
    for (int i = 0; i < M; ++i) {
        cur += diff[i];
        if (cur == 0) ++ans;
    }

    cout << ans << '\n';
    return 0;
}
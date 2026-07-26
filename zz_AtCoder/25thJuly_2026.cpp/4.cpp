#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int n = (int)S.size();
    long long ans = 0;

    for (int c = 0; c < 2 * n - 1; ++c) {
        int l = c / 2;
        int r = (c + 1) / 2;
        int mism = 0;

        while (l >= 0 && r < n) {
            if (S[l] != S[r]) ++mism;
            if (mism > 1) break;
            ++ans;
            --l;
            ++r;
        }
    }

    cout << ans << '\n';
    return 0;
}
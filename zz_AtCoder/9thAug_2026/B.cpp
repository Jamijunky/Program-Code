#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
using i128 = __int128_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    vector<int64> pow2(41);
    pow2[0] = 1;
    for (int i = 1; i <= 40; i++) pow2[i] = pow2[i - 1] * 2;

    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<int64> A(M);
        for (int i = 0; i < M; i++) cin >> A[i];

        i128 s = 0;       
        int64 ans = 0;

        for (int i = M - 1; i >= 0; i--) {
            s = (i128)A[i] + 2 * s;

            int64 need = (int64)((s + N - 1) / N);
            i128 cand = (i128)need * pow2[i];

            if (cand > ans) ans = (int64)cand;
        }

        cout << ans << '\n';
    }

    return 0;
}
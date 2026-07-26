#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const long long MOD = 998244353;

    int N;
    cin >> N;

    vector<long long> A(N + 1);
    for (int i = 1; i <= N; ++i) cin >> A[i];

    vector<long long> inv(N + 1), H(N + 1), PH(N + 1);

    inv[1] = 1;
    for (int i = 2; i <= N; ++i) {
        inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
    }

    for (int i = 1; i <= N; ++i) {
        H[i] = (H[i - 1] + inv[i]) % MOD;
        PH[i] = (PH[i - 1] + H[i]) % MOD;
    }

    long long ans = 0;
    for (int i = 1; i <= N; ++i) {
        int x = i - 1;
        int y = N - i;
        long long C = (PH[N] - PH[x] - PH[y]) % MOD;
        if (C < 0) C += MOD;
        ans = (ans + A[i] * C) % MOD;
    }

    cout << ans << '\n';
    return 0;
}
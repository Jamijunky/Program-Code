#include <iostream>

using namespace std;

const long long MOD = 998244353;

long long modpow(long long a, long long e) {
    long long res = 1;
    while (e > 0) {
        if (e & 1) res = res * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        long long n, m, r, c;
        cin >> n >> m >> r >> c;

        long long k = (r - 1) * m + (c - 1) * n - (r - 1) * (c - 1);

        cout << modpow(2, k) << '\n';
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 998244353;

ll modpow(ll a, ll e) {
    a %= MOD;
    if (a < 0) a += MOD;
    ll r = 1;
    while (e > 0) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    vector<pair<int,int>> q(t);
    int maxN = 0;

    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;
        q[i] = {n, m};
        maxN = max(maxN, n);
    }

    vector<ll> fact(maxN + 1), invfact(maxN + 1);
    fact[0] = 1;
    for (int i = 1; i <= maxN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    invfact[maxN] = modpow(fact[maxN], MOD - 2);
    for (int i = maxN; i >= 1; i--) {
        invfact[i - 1] = invfact[i] * i % MOD;
    }

    auto C = [&](int n, int r) -> ll {
        if (r < 0 || r > n) return 0;
        return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
    };

    for (auto [n, m] : q) {
        if (n == 1) {
            cout << 0 << '\n';
            continue;
        }

        int k = n - m; // |U|

        ll F = modpow(n - 1, n); // s = 0 term

        ll neg = (1 - n) % MOD;
        if (neg < 0) neg += MOD;

        for (int s = 1; s <= k; s++) {
            ll ways = C(k, s);

            ll a = n - s - 1;
            ll b = 1 - n + s;

            ll term = ways;
            term = term * modpow(a, n - s) % MOD;
            term = term * modpow(b, s - 1) % MOD;
            term = term * neg % MOD;

            F += term;
            if (F >= MOD) F -= MOD;
        }

        ll chooseStart = C(n, m);
        ll ans = chooseStart * F % MOD;
        cout << ans << '\n';
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9;
const ll LINF = 1e18;

const int MOD = 998244353;
const int MAXN = 1000000 + 5;

ll fact[MAXN], invfact[MAXN];

ll modpow(ll a, ll e) {
    ll r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

ll C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
}

void Solve() {
    int n;
    string s;
    cin >> n >> s;

    int zeros = 0, ones = 0;
    for (char c : s) {
        if (c == '0') zeros++;
        else ones++;
    }

    if (zeros == 0 || ones == 0) {
        cout << 1 << '\n';
        return;
    }

    int runs0 = 0, runs1 = 0;
    if (s[0] == '0') runs0 = 1;
    else runs1 = 1;

    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            if (s[i] == '0') runs0++;
            else runs1++;
        }
    }

    ll ans = C(zeros - 1, runs0 - 1) * C(ones - 1, runs1 - 1) % MOD;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("IO/input.txt", "r", stdin);
    freopen("IO/output.txt", "w", stdout);
#endif

    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    invfact[MAXN - 1] = modpow(fact[MAXN - 1], MOD - 2);
    for (int i = MAXN - 2; i >= 0; i--) {
        invfact[i] = invfact[i + 1] * (i + 1) % MOD;
    }

    int t = 1;
    cin >> t;

    while (t--) {
        Solve();
    }

    return 0;
}
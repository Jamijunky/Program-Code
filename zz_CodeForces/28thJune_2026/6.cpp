#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXK = 200000;
const ll MOD = 1000000007LL;

ll modpow(ll a, ll e) {
    ll r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int MAX = MAXK + 5;
    vector<ll> fact(2 * MAX + 5), invfact(2 * MAX + 5);
    fact[0] = 1;
    for (int i = 1; i < (int)fact.size(); i++) fact[i] = fact[i - 1] * i % MOD;
    invfact[fact.size() - 1] = modpow(fact[fact.size() - 1], MOD - 2);
    for (int i = (int)fact.size() - 2; i >= 0; i--) invfact[i] = invfact[i + 1] * (i + 1) % MOD;

    vector<ll> catalan(MAX + 5);
    for (int i = 0; i <= MAX; i++) {
        // Catalan_i = C(2i, i) / (i + 1)
        catalan[i] = fact[2 * i] * invfact[i] % MOD * invfact[i] % MOD;
        catalan[i] = catalan[i] * modpow(i + 1, MOD - 2) % MOD;
    }

    int T;
    cin >> T;

    while (T--) {
        ll n;
        int k;
        cin >> n >> k;

        int N = k + 1;
        int lgN = 0;
        while ((1 << (lgN + 1)) <= N) lgN++;

        int R = min(lgN, (int)n - 1);
        if (R < 0) R = 0;

        vector<int> cnt(R + 1, 0);
        int m;

        if (R >= lgN) {
            m = __builtin_popcount((unsigned)N);
            for (int i = 0; i <= R; i++) {
                if ((N >> i) & 1) cnt[i] = 1;
            }
        } else {
            int pw = 1 << R;
            int q = N / pw;
            int rem = N % pw;
            m = q + __builtin_popcount((unsigned)rem);
            cnt[R] = q;
            for (int i = 0; i < R; i++) {
                if ((rem >> i) & 1) cnt[i] = 1;
            }
        }

        // Need at least two direct firings: both children of student 1
        if (m < 2) {
            m = 2;
            fill(cnt.begin(), cnt.end(), 0);
            int j = lgN - 1;
            cnt[j] = 2;
        }

        ll ways = catalan[m - 1];
        ways = ways * fact[m] % MOD;
        for (int c : cnt) {
            ways = ways * invfact[c] % MOD;
        }

        cout << ways << '\n';
    }

    return 0;
}
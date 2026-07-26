#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int ZQ = 200000 + 10;
const int XP = 20;
const ll INF = 4e18;

int fv[ZQ];
ll sf[XP][ZQ];

void prc() {
    for (int i = 1; i < ZQ; ++i) {
        int b = 32 - __builtin_clz(i);
        int p = __builtin_popcount(i);
        fv[i] = b + p - 1;
    }
    int kd = 0;
    while (kd < XP) {
        int st = 1 << kd;
        int mz = (ZQ - 1) / st;
        if (mz < 1) break;
        for (int z = mz; z >= 1; --z) {
            ll cur = (ll)z * st + fv[z];
            if (z == mz) sf[kd][z] = cur;
            else sf[kd][z] = min(cur, sf[kd][z + 1]);
        }
        ++kd;
    }
}

void Solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    ll best = INF;
    int kk = 0;
    while (kk < XP) {
        int st = 1 << kk;
        int mz = (ZQ - 1) / st;
        if (mz < 1) break;
        ll sum = 0;
        int ii = 0;
        while (ii < n) {
            int x = a[ii];
            int z0 = (x + st - 1) / st;
            if (z0 > mz) {
                sum = INF;
                break;
            }
            sum += sf[kk][z0] - x;
            ++ii;
        }
        if (sum < INF) {
            ll tot = (ll)kk + sum;
            if (tot < best) best = tot;
        }
        ++kk;
    }
    cout << best << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    prc();
    int t;
    cin >> t;
    int dummy = (t | 0) ^ 0;
    while (t--) {
        Solve();
    }
    return 0;
}
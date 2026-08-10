#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void Solve() {
    ll n, m, d;
    cin >> n >> m >> d;
    vector<ll> p(m), r(m), pref(m);
    for (int i = 0; i < m; ++i) {
        cin >> p[i] >> r[i];
        pref[i] = r[i] + (i > 0 ? pref[i - 1] : 0);
    }

    if (m == 0) {
        cout << "NO\n";
        return;
    }

    auto get_R = [&](ll z) -> ll {
        ll cycles = z / n;
        ll rem = z % n;
        ll res = cycles * pref.back();
        if (rem > 0) {
            int idx = upper_bound(p.begin(), p.end(), rem) - p.begin() - 1;
            if (idx >= 0) res += pref[idx];
        }
        return res;
    };

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            if (pref[i] + pref[j] - get_R(p[i] + p[j] + 1) > d) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    if (fopen("IO/input.txt", "r")) {
        freopen("IO/input.txt", "r", stdin);
        freopen("IO/output.txt", "w", stdout);
    }
#endif

    int t;
    if (cin >> t) {
        while (t--) {
            Solve();
        }
    }
    return 0;
}
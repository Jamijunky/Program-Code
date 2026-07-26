#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9;
const ll LINF = 1e18;

void Solve() {
    int x;
    cin >> x;

    if (x == 2) {
        cout << -1 << '\n';
        return;
    }

    if (x == 1) {
        cout << 1 << '\n';
        return;
    }

    cout << 1 << ' ' << 2 << ' ' << 3;
    ll v = 3;
    int y = 4;
    while (y <= x) {
        v <<= 1;
        cout << ' ' << v;
        y++;
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("IO/input.txt", "r", stdin);
    freopen("IO/output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;

    while (t--) {
        Solve();
    }

    return 0;
}
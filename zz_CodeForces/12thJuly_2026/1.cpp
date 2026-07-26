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

    vector<int> yz(x + 1);
    int a1 = 2, b2 = 1;

    int c3 = 1;
    while (c3 <= x) {
        yz[c3] = a1;
        a1 += 2;
        c3 += 2;
    }

    c3 = 2;
    while (c3 <= x) {
        yz[c3] = b2;
        b2 += 2;
        c3 += 2;
    }

    int d4 = 1;
    while (d4 <= x) {
        cout << yz[d4] << (d4 == x ? '\n' : ' ');
        d4++;
    }
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
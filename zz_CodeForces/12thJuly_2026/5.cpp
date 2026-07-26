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
    int x = 1;
    cout << x << endl;
    
    int o;
    if (!(cin >> o)) return;
    if (o == -1) exit(0);
    
    int m0 = 0;
    int m1 = 0;
    
    if (o != x) {
        int idx = 0;
        while (((o >> idx) & 1) == ((x >> idx) & 1)) {
            idx++;
        }
        m1 = (1 << idx);
    } else {
        m1 = 1000000007; // Large odd marker
    }
    
    cout << m0 << " " << m1 << endl;
    
    int r;
    if (!(cin >> r)) return;
    if (r == -1) exit(0);
    
    int v0 = r ^ m0;
    int v1 = r ^ m1;
    
    bool valid0 = ((v0 & x) == o) || ((v0 | x) == o);
    bool valid1 = ((v1 & x) == o) || ((v1 | x) == o);
    
    int b = 0;
    if (valid0 && valid1) {
        if (v0 == 0) {
            b = 0;
        } else {
            b = 1;
        }
    } else if (valid0) {
        b = 0;
    } else {
        b = 1;
    }
    
    cout << b << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    (void)freopen("IO/input.txt", "r", stdin);
    (void)freopen("IO/output.txt", "w", stdout);
#endif
    int t = 1;
    if (cin >> t) {
        while (t--) {
            Solve();
        }
    }
    return 0;
}
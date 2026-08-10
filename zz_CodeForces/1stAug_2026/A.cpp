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
    string s;
    cin >> s;

    int z = s.find('0');
    string a = s;
    a.erase(z, 1);

    int L = a.rfind('0');              
    int bob = a.find('1');               

    if (L != (int)string::npos) {
        for (int i = 0; i < L; ++i) {
            if (a[i] == '1') {
                bob = i;
                break;
            }
        }
    }

    a.erase(bob, 1);
    cout << a << '\n';
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
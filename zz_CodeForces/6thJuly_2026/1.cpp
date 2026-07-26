#include <bits/stdc++.h>
using namespace std;

void solve() {
    int k;
    cin >> k;

    int three = 0;
    int two = 0;

    for (int i = 0; i < k; i++) {
        long long x;
        cin >> x;
        if (x >= 3) three = 1;
        if (x >= 2) two++;
    }

    if (three || two >= 2) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}
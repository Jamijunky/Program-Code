#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 1);
    vector<int> one(n + 1), three(n + 1);
    vector<int> A(n + 1), B(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        one[i] = one[i - 1] + (a[i] == 1);
        three[i] = three[i - 1] + (a[i] == 3);

        A[i] = one[i] - (i - one[i]);      // ones - (twos + threes)
        B[i] = i - 2 * three[i];           // (ones + twos) - threes
    }

    const int INF = 1e9;
    int mn = INF;

    for (int r = 2; r <= n - 1; r++) {
        int l = r - 1;
        if (A[l] >= 0) mn = min(mn, B[l]);

        if (mn <= B[r]) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}
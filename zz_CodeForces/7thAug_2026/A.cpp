#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000 + 5;
vector<bool> isPrime;

void Solve() {
    int n;
    cin >> n;
    cout << (isPrime[n + 1] ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    isPrime.assign(MAXN + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= MAXN; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAXN; j += i) {
                isPrime[j] = false;
            }
        }
    }

    int t;
    cin >> t;
    while (t--) {
        Solve();
    }

    return 0;
}
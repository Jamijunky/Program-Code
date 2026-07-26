#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000000;
int spf[MAXN + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // smallest prime factor sieve
    for (int i = 2; i <= MAXN; i++) spf[i] = i;
    for (int i = 2; i * i <= MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= MAXN; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        int omega = 0;   // distinct prime factors
        int Omega = 0;   // total prime factors with multiplicity

        while (N > 1) {
            int p = spf[N];
            omega++;
            while (N % p == 0) {
                N /= p;
                Omega++;
            }
        }

        cout << Omega + omega - 1 << '\n';
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int q; cin >> q;

    while (q--) {
        long long k; cin >> k;
        long long d = 1, p = 1;

        while (k > 9 * p * d) {
            k -= 9 * p * d;
            p *= 10;
            d++;
        }

        k--;
        long long n = p + k / d;
        cout << to_string(n)[k % d] << '\n';
    }
}
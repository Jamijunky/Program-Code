#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int q = N / 3;
    int r = N % 3;

    for (int k = 0; k < q; ++k) {
        int b = 3 * k;
        cout << b + 1 << '\n'
             << b + 2 << '\n'
             << "Fizz\n";
    }

    if (r >= 1) cout << 3 * q + 1 << '\n';
    if (r >= 2) cout << 3 * q + 2 << '\n';

    return 0;
}
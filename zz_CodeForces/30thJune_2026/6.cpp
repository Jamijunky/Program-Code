#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        string s;
        cin >> n >> s;

        int totalZeros = 0;
        for (char c : s) {
            if (c == '0') totalZeros++;
        }

        int onesSeen = 0, zerosSeen = 0;
        bool aliceWins = false;

        for (char c : s) {
            if (c == '0') {
                // For a 0, its degree = number of 1s before it.
                // It must be even.
                if (onesSeen % 2 != 0) {
                    aliceWins = true;
                    break;
                }
                zerosSeen++;
            } else { // c == '1'
                // For a 1, its degree = number of 0s after it.
                // This equals totalZeros - zerosSeen.
                // Need totalZeros - zerosSeen even => zerosSeen % 2 == totalZeros % 2.
                if (zerosSeen % 2 != totalZeros % 2) {
                    aliceWins = true;
                    break;
                }
                onesSeen++;
            }
        }

        cout << (aliceWins ? "Alice" : "Bob") << '\n';
    }

    return 0;
}
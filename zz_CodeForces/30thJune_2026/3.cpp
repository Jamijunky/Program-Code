#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        string S;
        cin >> N >> S;

        int zeros = 0, ones = 0;
        for (char c : S) {
            if (c == '0') zeros++;
            else ones++;
        }

        // All characters are the same
        if (zeros == 0 || ones == 0) {
            cout << 1 << '\n';
            continue;
        }

        // Check if the string is sorted (all 0s then all 1s)
        string sorted0 = string(zeros, '0') + string(ones, '1');
        // Check if it's sorted in reverse (all 1s then all 0s)
        string sorted1 = string(ones, '1') + string(zeros, '0');

        if (S == sorted0 || S == sorted1) {
            cout << 2 << '\n';
        } else {
            cout << 1 << '\n';
        }
    }
    return 0;
}
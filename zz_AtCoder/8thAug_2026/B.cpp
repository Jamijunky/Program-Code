#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> freq(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        int c;
        cin >> c;
        ++freq[c];
    }

    int max_freq = *max_element(freq.begin(), freq.end());
    cout << N - max_freq << '\n';

    return 0;
}
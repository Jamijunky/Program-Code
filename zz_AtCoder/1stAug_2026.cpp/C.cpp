#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string S;
    cin >> N >> S;

    vector<int> ans(N, N);
    int idx = 0;
    for (int i = 0; i < N; ++i) {
        if (S[i] == 'x') {
            ans[idx++] = i + 1;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << ans[i] << '\n';
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int rank_perm(const vector<int>& p) {
    int n = (int)p.size();
    vector<int> fact(n + 1, 1);
    for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;

    vector<bool> used(n + 1, false);
    int rank = 0;
    for (int i = 0; i < n; ++i) {
        int x = p[i];
        int smaller = 0;
        for (int y = 1; y < x; ++y)
            if (!used[y]) ++smaller;
        rank += smaller * fact[n - 1 - i];
        used[x] = true;
    }
    return rank;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> P(N), Q(N);
    for (int &x : P) cin >> x;
    for (int &x : Q) cin >> x;

    if (P == Q) {
        cout << 0 << '\n';
    } else if (P < Q) {
        cout << rank_perm(Q) - rank_perm(P) - 1 << '\n';
    } else {
        cout << 0 << '\n';
    }

    return 0;
}
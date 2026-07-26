#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAXA = 1000000;
    vector<char> isSquare(MAXA + 1, 0);
    for (int i = 1; i * i <= MAXA; i++) {
        isSquare[i * i] = 1;
    }

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> A(N + 1);
        for (int i = 1; i <= N; i++) cin >> A[i];

        vector<vector<int>> g(N + 1);
        for (int i = 0; i < N - 1; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        // Root the tree at 1.
        vector<int> parent(N + 1, 0), order;
        order.reserve(N);
        parent[1] = -1;
        order.push_back(1);

        for (int idx = 0; idx < (int)order.size(); idx++) {
            int v = order[idx];
            for (int to : g[v]) {
                if (to == parent[v]) continue;
                parent[to] = v;
                order.push_back(to);
            }
        }

        // Subtree sizes.
        vector<int> sub(N + 1, 1);
        for (int idx = N - 1; idx >= 0; idx--) {
            int v = order[idx];
            sub[v] = 1;
            for (int to : g[v]) {
                if (parent[to] == v) {
                    sub[v] += sub[to];
                }
            }
        }

        long long ans = 0;

        for (int v = 1; v <= N; v++) {
            // Median vertex must have a square value.
            if (!isSquare[A[v]]) continue;

            long long S1 = 0, S2 = 0, S3 = 0;

            for (int to : g[v]) {
                long long sz;

                if (parent[to] == v) {
                    sz = sub[to]; // child subtree component
                } else {
                    sz = N - sub[v]; // parent side component
                }

                S1 += sz;
                S2 += sz * sz;
                S3 += sz * sz * sz;
            }

            // e2 = sum s_i * s_j
            // e3 = sum s_i * s_j * s_k
            long long e2 = (S1 * S1 - S2) / 2;
            long long e3 = (S1 * S1 * S1 - 3 * S1 * S2 + 2 * S3) / 6;

            ans += e2 + e3;
        }

        cout << ans << '\n';
    }

    return 0;
}
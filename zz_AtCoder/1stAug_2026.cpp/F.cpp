#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, sz;
    DSU(int n) : parent(n), sz(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    const int MAXA = 1000000;
    vector<int> A(N);
    vector<int> idxOf(MAXA + 1, -1);

    int maxA = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        idxOf[A[i]] = i;
        maxA = max(maxA, A[i]);
    }

    DSU dsu(N);
    long long ans = 0;

    for (int d = maxA; d >= 1; --d) {
        int root = -1;
        for (int mult = d; mult <= maxA; mult += d) {
            int v = idxOf[mult];
            if (v != -1) {
                if (root == -1) {
                    root = v;
                } else {
                    if (dsu.unite(root, v)) {
                        ans += d;
                    }
                }
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
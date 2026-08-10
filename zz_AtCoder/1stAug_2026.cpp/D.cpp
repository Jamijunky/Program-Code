#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    unordered_set<long long> edgeSet;
    edgeSet.reserve(M * 2);
    long long base = N + 1LL;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        edgeSet.insert(1LL * a * base + b);
    }

    vector<pair<int, int>> edges;
    edges.reserve(edgeSet.size());
    for (long long key : edgeSet) {
        int a = key / base;
        int b = key % base;
        edges.emplace_back(a, b);
    }

    int m = (int)edges.size();

    if (m == 0) {
        cout << 1LL * N * (N - 1) / 2 << '\n';
        return 0;
    }

    vector<int> deg(N + 1, 0);
    for (auto [u, v] : edges) {
        deg[u]++;
        deg[v]++;
    }

    auto hasEdge = [&](int u, int v) -> bool {
        if (u > v) swap(u, v);
        return edgeSet.find(1LL * u * base + v) != edgeSet.end();
    };

    int a = edges[0].first, b = edges[0].second;

    pair<int, int> eA = {-1, -1}, eB = {-1, -1};
    bool foundA = false, foundB = false;

    for (auto [u, v] : edges) {
        if (!foundA && u != a && v != a) {
            eA = {u, v};
            foundA = true;
        }
        if (!foundB && u != b && v != b) {
            eB = {u, v};
            foundB = true;
        }
        if (foundA && foundB) break;
    }

    long long ans = 0;

    for (int x = 1; x <= N; ++x) {
        if (deg[x] == m) {
            ans += (N - x);
            continue;
        }

        pair<int, int> e1;
        if (x != a && x != b) {
            e1 = {a, b};
        } else if (x == a) {
            e1 = eA;
        } else {
            e1 = eB;
        }

        int cand[2] = {e1.first, e1.second};

        for (int y : cand) {
            if (y <= x) continue;
            long long common = hasEdge(x, y) ? 1 : 0;
            if (m - deg[x] - deg[y] + common == 0) {
                ans++;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
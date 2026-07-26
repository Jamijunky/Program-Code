#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        struct Restriction { int o, i, j; };
        vector<Restriction> restrictions(m);

        for (int k = 0; k < m; k++) {
            cin >> restrictions[k].o >> restrictions[k].i >> restrictions[k].j;
            restrictions[k].i--;
            restrictions[k].j--;
        }

        vector<int> sign(n, 0); // 0 = unknown, 1 = P (non-negative), 2 = N (negative)

        for (auto &r : restrictions) {
            if (r.i == r.j) {
                sign[r.i] = (r.o == 1 ? 1 : 2);
            }
        }

        vector<vector<pair<int, int>>> adj(n);
        bool possible = true;

        for (auto &r : restrictions) {
            int u = r.i, v = r.j;
            if (u == v) continue;

            int su = sign[u], sv = sign[v];

            if (su == 1 && sv == 1) {
                if (r.o == 2) possible = false;
            } else if (su == 2 && sv == 2) {
                if (r.o == 1) possible = false;
            } else if (su == 1 && sv == 2) {
                int p = u, n_ = v;
                if (r.o == 1) {
                    // p >= n_  => n_ -> p (weight 0)
                    adj[n_].push_back({p, 0});
                } else {
                    // p < n_   => p -> n_ (weight 1)
                    adj[p].push_back({n_, 1});
                }
            } else if (su == 2 && sv == 1) {
                int p = v, n_ = u;
                if (r.o == 1) {
                    adj[n_].push_back({p, 0});
                } else {
                    adj[p].push_back({n_, 1});
                }
            }
        }

        if (!possible) {
            cout << "NO\n";
            continue;
        }

        // Kahn's algorithm to detect cycle and get topological order
        vector<int> indeg(n, 0);
        for (int i = 0; i < n; i++) {
            for (auto &e : adj[i]) {
                indeg[e.first]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) q.push(i);
        }

        vector<int> topo;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            topo.push_back(u);
            for (auto &e : adj[u]) {
                int v = e.first;
                if (--indeg[v] == 0) q.push(v);
            }
        }

        if ((int)topo.size() != n) {
            cout << "NO\n";
            continue;
        }

        vector<long long> dist(n, 0);
        for (int i = 0; i < n; i++) {
            if (sign[i] == 2) dist[i] = 1; // negative => y_i >= 1
        }

        for (int u : topo) {
            for (auto &e : adj[u]) {
                int v = e.first, w = e.second;
                dist[v] = max(dist[v], dist[u] + w);
            }
        }

        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            if (sign[i] == 1) cout << dist[i] << (i + 1 == n ? '\n' : ' ');
            else cout << -dist[i] << (i + 1 == n ? '\n' : ' ');
        }
    }

    return 0;
}
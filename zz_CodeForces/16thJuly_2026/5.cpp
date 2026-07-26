#include <bits/stdc++.h>
using namespace std;

vector<int> kosaraju(int n, const vector<vector<int>>& adj, const vector<vector<int>>& radj) {
    vector<int> comp(n, -1);
    vector<char> vis(n, 0);
    vector<int> order;
    order.reserve(n);

    for (int i = 0; i < n; ++i) {
        if (vis[i]) continue;
        vector<pair<int, int>> st; // {node, next index}
        st.push_back({i, 0});
        vis[i] = 1;
        while (!st.empty()) {
            int u = st.back().first;
            int &idx = st.back().second;
            if (idx < (int)adj[u].size()) {
                int v = adj[u][idx++];
                if (!vis[v]) {
                    vis[v] = 1;
                    st.push_back({v, 0});
                }
            } else {
                order.push_back(u);
                st.pop_back();
            }
        }
    }

    int cid = 0;
    for (int k = n - 1; k >= 0; --k) {
        int u = order[k];
        if (comp[u] != -1) continue;
        vector<int> stack2;
        stack2.push_back(u);
        comp[u] = cid;
        while (!stack2.empty()) {
            int x = stack2.back();
            stack2.pop_back();
            for (int v : radj[x]) {
                if (comp[v] == -1) {
                    comp[v] = cid;
                    stack2.push_back(v);
                }
            }
        }
        ++cid;
    }
    return comp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<tuple<int, int, int>> restrictions; // o, i, j (0-indexed)
        restrictions.reserve(m);

        int N = 2 * n;
        vector<vector<int>> adj2(N), radj2(N);

        for (int k = 0; k < m; ++k) {
            int o, i, j;
            cin >> o >> i >> j;
            --i; --j;
            restrictions.emplace_back(o, i, j);

            if (o == 1) {
                // s_i or s_j
                adj2[i + n].push_back(j);
                radj2[j].push_back(i + n);
                adj2[j + n].push_back(i);
                radj2[i].push_back(j + n);
            } else {
                // !s_i or !s_j
                adj2[i].push_back(j + n);
                radj2[j + n].push_back(i);
                adj2[j].push_back(i + n);
                radj2[i + n].push_back(j);
            }
        }

        vector<int> comp2 = kosaraju(N, adj2, radj2);

        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (comp2[i] == comp2[i + n]) {
                ok = false;
                break;
            }
        }

        if (!ok) {
            cout << "NO\n";
            continue;
        }

        vector<int> sign(n); // 1 = positive, 0 = negative
        for (int i = 0; i < n; ++i) {
            sign[i] = (comp2[i] > comp2[i + n]) ? 1 : 0;
        }

        int V = n + 1;
        vector<vector<int>> adj0(V), radj0(V);
        vector<tuple<int, int, int>> edges_mag; // u, v, w

        // lower bounds
        for (int i = 0; i < n; ++i) {
            int v = i + 1;
            edges_mag.emplace_back(0, v, 0);
            adj0[0].push_back(v);
            radj0[v].push_back(0);

            if (sign[i] == 0) { // negative => v_i >= 1
                edges_mag.emplace_back(0, v, 1);
                // weight 1 edges are not in adj0
            }
        }

        // magnitude constraints from restrictions
        for (auto &r : restrictions) {
            int o = get<0>(r), i = get<1>(r), j = get<2>(r);
            if (sign[i] == sign[j]) continue;

            int p = sign[i] ? i : j; // positive index
            int q = sign[i] ? j : i; // negative index

            if (o == 1) {
                // v_q <= v_p  =>  v_p >= v_q  =>  edge q+1 -> p+1 weight 0
                edges_mag.emplace_back(q + 1, p + 1, 0);
                adj0[q + 1].push_back(p + 1);
                radj0[p + 1].push_back(q + 1);
            } else {
                // v_p < v_q  =>  v_q >= v_p + 1  =>  edge p+1 -> q+1 weight 1
                edges_mag.emplace_back(p + 1, q + 1, 1);
                // weight 1 not in adj0
            }
        }

        vector<int> comp0 = kosaraju(V, adj0, radj0);
        int C = *max_element(comp0.begin(), comp0.end()) + 1;

        vector<vector<pair<int, int>>> dag(C);
        vector<int> indeg(C, 0);

        for (auto &e : edges_mag) {
            int u = get<0>(e), v = get<1>(e), w = get<2>(e);
            int cu = comp0[u], cv = comp0[v];
            if (cu != cv) {
                dag[cu].push_back({cv, w});
                indeg[cv]++;
            }
        }

        queue<int> q;
        for (int c = 0; c < C; ++c)
            if (indeg[c] == 0) q.push(c);

        const long long NEG = -(1LL << 60);
        vector<long long> dist(C, NEG);
        dist[comp0[0]] = 0;

        int processed = 0;
        bool cycle = false;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ++processed;

            if (dist[u] != NEG) {
                for (auto &e : dag[u]) {
                    int v = e.first, w = e.second;
                    if (dist[v] < dist[u] + w)
                        dist[v] = dist[u] + w;
                }
            }

            for (auto &e : dag[u]) {
                int v = e.first;
                if (--indeg[v] == 0)
                    q.push(v);
            }
        }

        if (processed != C) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            long long val = dist[comp0[i + 1]];
            if (sign[i] == 0) val = -val;
            cout << val << (i + 1 == n ? '\n' : ' ');
        }
    }

    return 0;
}
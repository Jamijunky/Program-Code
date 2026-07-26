#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<vector<int>> children(n + 1);
        for (int i = 2; i <= n; ++i) {
            int p;
            cin >> p;
            children[p].push_back(i);
        }

        int LOG = 1;
        while ((1 << LOG) <= n) ++LOG;

        vector<vector<int>> up(LOG, vector<int>(n + 1));
        vector<int> depth(n + 1, 0), tin(n + 1), tout(n + 1);
        vector<vector<int>> depthNodes(n + 1);

        int timer = 0;
        vector<int> parent(n + 1, 1);
        vector<int> it(n + 1, 0);
        vector<int> st;
        st.reserve(n);
        st.push_back(1);

        while (!st.empty()) {
            int v = st.back();

            if (it[v] == 0) {
                tin[v] = ++timer;
                depthNodes[depth[v]].push_back(v);
            }

            if (it[v] < (int)children[v].size()) {
                int u = children[v][it[v]++];
                depth[u] = depth[v] + 1;
                parent[u] = v;
                st.push_back(u);
            } else {
                tout[v] = timer;
                st.pop_back();
            }
        }

        for (int i = 1; i <= n; ++i) up[0][i] = parent[i];
        for (int j = 1; j < LOG; ++j) {
            for (int i = 1; i <= n; ++i) {
                up[j][i] = up[j - 1][up[j - 1][i]];
            }
        }

        auto lca = [&](int a, int b) {
            if (depth[a] < depth[b]) swap(a, b);
            int diff = depth[a] - depth[b];
            for (int j = 0; j < LOG; ++j) {
                if (diff & (1 << j)) a = up[j][a];
            }
            if (a == b) return a;
            for (int j = LOG - 1; j >= 0; --j) {
                if (up[j][a] != up[j][b]) {
                    a = up[j][a];
                    b = up[j][b];
                }
            }
            return up[0][a];
        };

        long long ans = 0;
        int maxDepth = 0;
        for (int i = 1; i <= n; ++i) maxDepth = max(maxDepth, depth[i]);

        for (int d = 0; d <= maxDepth; ++d) {
            if (depthNodes[d].empty()) continue;

            vector<int> nodes = depthNodes[d];
            sort(nodes.begin(), nodes.end(), [&](int a, int b) {
                return tin[a] < tin[b];
            });

            vector<int> vtree = nodes;
            for (int i = 0; i + 1 < (int)nodes.size(); ++i) {
                vtree.push_back(lca(nodes[i], nodes[i + 1]));
            }

            sort(vtree.begin(), vtree.end());
            vtree.erase(unique(vtree.begin(), vtree.end()), vtree.end());

            ans += (long long)vtree.size();
        }

        cout << ans << '\n';
    }

    return 0;
}
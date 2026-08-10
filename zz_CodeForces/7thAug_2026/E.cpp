#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 998244353;
const int G = 3;

ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

ll modInverse(ll n) {
    return power(n, MOD - 2);
}

void ntt(vector<ll>& a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
        if (i < j)
            swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        ll wlen = power(G, (MOD - 1) / len);
        if (invert)
            wlen = modInverse(wlen);
        for (int i = 0; i < n; i += len) {
            ll w = 1;
            for (int j = 0; j < len / 2; j++) {
                ll u = a[i + j];
                ll v = (a[i + j + len / 2] * w) % MOD;
                a[i + j] = (u + v >= MOD ? u + v - MOD : u + v);
                a[i + j + len / 2] = (u - v < 0 ? u - v + MOD : u - v);
                w = (w * wlen) % MOD;
            }
        }
    }
    if (invert) {
        ll n_inv = modInverse(n);
        for (ll& x : a)
            x = (x * n_inv) % MOD;
    }
}

struct BFSResult {
    int farthest;
    vector<int> dist;
    vector<int> parent;
};

BFSResult bfs(int start_node, int n, const vector<vector<int>>& adj) {
    BFSResult res;
    res.dist.assign(n + 1, -1);
    res.parent.assign(n + 1, -1);
    queue<int> q;

    q.push(start_node);
    res.dist[start_node] = 0;
    res.farthest = start_node;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (res.dist[u] > res.dist[res.farthest]) {
            res.farthest = u;
        }

        for (int v : adj[u]) {
            if (res.dist[v] == -1) {
                res.dist[v] = res.dist[u] + 1;
                res.parent[v] = u;
                q.push(v);
            }
        }
    }
    return res;
}

vector<int> get_depth_set(int root, int forbidden, int n, int L, const vector<vector<int>>& adj) {
    vector<int> depth(n + 1, -1);
    vector<int> parent(n + 1, -1);
    vector<int> order;
    order.reserve(n);

    queue<int> q;
    q.push(root);
    depth[root] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for (int v : adj[u]) {
            if (v != parent[u] && v != forbidden) {
                depth[v] = depth[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    vector<bool> has_S(n + 1, false);
    vector<int> cnt(n + 1, 0);

    for (int i = (int)order.size() - 1; i >= 0; i--) {
        int u = order[i];
        if (depth[u] == L) {
            has_S[u] = true;
        }
        int p = parent[u];
        if (p != -1 && has_S[u]) {
            has_S[p] = true;
            cnt[p]++;
        }
    }

    vector<int> A_set;
    A_set.push_back(L);
    for (int u : order) {
        if (cnt[u] >= 2) {
            A_set.push_back(depth[u]);
        }
    }

    sort(A_set.begin(), A_set.end());
    A_set.erase(unique(A_set.begin(), A_set.end()), A_set.end());
    return A_set;
}

void Solve() {
    int n;
    if (!(cin >> n)) return;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    BFSResult res1 = bfs(1, n, adj);
    BFSResult resA = bfs(res1.farthest, n, adj);

    int B = resA.farthest;
    int D = resA.dist[B];
    int L = (D - 1) / 2;

    vector<int> path;
    int curr = B;
    while (curr != -1) {
        path.push_back(curr);
        curr = resA.parent[curr];
    }

    int u_0 = path[L];
    int v_0 = path[L + 1];

    vector<int> A_u = get_depth_set(u_0, v_0, n, L, adj);
    vector<int> A_v = get_depth_set(v_0, u_0, n, L, adj);

    vector<bool> is_cand(2 * L + 2, false);

    if (L <= 500) {
        for (int x : A_u) {
            for (int y : A_v) {
                is_cand[x + y + 1] = true;
            }
        }
    } else {
        int sz = 1;
        while (sz <= 2 * L) sz <<= 1;
        vector<ll> poly1(sz, 0), poly2(sz, 0);
        for (int x : A_u) poly1[x] = 1;
        for (int y : A_v) poly2[y] = 1;

        ntt(poly1, false);
        ntt(poly2, false);
        for (int i = 0; i < sz; i++) {
            poly1[i] = (poly1[i] * poly2[i]) % MOD;
        }
        ntt(poly1, true);

        for (int i = 0; i <= 2 * L; i++) {
            if (poly1[i] > 0) {
                is_cand[i + 1] = true;
            }
        }
    }

    vector<int> ans;
    for (int k = 1; k <= 2 * L + 1; k++) {
        if (is_cand[k]) {
            ans.push_back(k);
        }
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i] << (i + 1 == (int)ans.size() ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    if (cin >> t) {
        while (t--) {
            Solve();
        }
    }
    return 0;
}
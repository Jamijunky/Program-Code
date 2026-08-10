#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int n;
    vector<int> cnt, best;
    const int NEG = -1e9;

    SegTree(int n) : n(n), cnt(4 * n, 0), best(4 * n, NEG) {}

    void update(int node, int l, int r, int pos, int delta) {
        if (l == r) {
            cnt[node] += delta;
            if (cnt[node] > 0)
                best[node] = l - 1;      
            else
                best[node] = NEG;
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid)
            update(node << 1, l, mid, pos, delta);
        else
            update(node << 1 | 1, mid + 1, r, pos, delta);

        cnt[node] = cnt[node << 1] + cnt[node << 1 | 1];
        best[node] = max(best[node << 1],
                         best[node << 1 | 1] - cnt[node << 1]);
    }

    void add(int pos) {
        update(1, 0, n - 1, pos, +1);
    }

    void remove(int pos) {
        update(1, 0, n - 1, pos, -1);
    }

    int query() const {
        return best[1];
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> p(n), pos(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        pos[p[i]] = i;
    }

    vector<pair<int, int>> edges;
    for (int v = 1; v < n; ++v) {
        int a = pos[v], b = pos[v + 1];
        if (a > b) swap(a, b);
        edges.emplace_back(a, b);
    }

    const int MAXV = 2 * n;          
    SegTree seg(MAXV);

    vector<vector<pair<int, int>>> events(n);  

    for (auto [a, b] : edges) {
        seg.add(b);                     

        events[a].emplace_back(0, b);
        events[a].emplace_back(1, a + n);

        // transition at L = b: a+n → b+n
        events[b].emplace_back(0, a + n);
        events[b].emplace_back(1, b + n);
    }

    int bad = 0;
    for (int L = 0; L < n; ++L) {
        int mx = seg.query();
        if (mx > L + 1)
            ++bad;

        for (auto [type, val] : events[L]) {
            if (type == 0)
                seg.remove(val);
            else
                seg.add(val);
        }
    }

    cout << n - bad << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
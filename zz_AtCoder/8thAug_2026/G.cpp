#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 300005;

struct Node {
    int min_val;
    ll sum_pmin;
} tree[4 * MAXN];

ll calc(int node, int l, int r, int v) {
    if (l == r) {
        return min(v, tree[node].min_val);
    }
    int mid = l + (r - l) / 2;
    if (v <= tree[2 * node].min_val) {
        return 1LL * v * (mid - l + 1) + calc(2 * node + 1, mid + 1, r, v);
    } else {
        ll right_contrib = tree[node].sum_pmin - tree[2 * node].sum_pmin;
        return calc(2 * node, l, mid, v) + right_contrib;
    }
}

void push_up(int node, int l, int r) {
    int mid = l + (r - l) / 2;
    tree[node].min_val = min(tree[2 * node].min_val, tree[2 * node + 1].min_val);
    tree[node].sum_pmin = tree[2 * node].sum_pmin + calc(2 * node + 1, mid + 1, r, tree[2 * node].min_val);
}

void update(int node, int l, int r, int idx, int val) {
    if (l == r) {
        tree[node].min_val = val;
        tree[node].sum_pmin = val;
        return;
    }
    int mid = l + (r - l) / 2;
    if (idx <= mid) {
        update(2 * node, l, mid, idx, val);
    } else {
        update(2 * node + 1, mid + 1, r, idx, val);
    }
    push_up(node, l, r);
}

void Solve() {
    int N;
    if (!(cin >> N)) return;

    vector<int> A(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    ll total_ans = 0;

    for (int r = 1; r <= N; r++) {
        if (A[r] <= N + 1) {
            update(1, 0, N + 1, A[r], r);
        }
        total_ans += tree[1].sum_pmin;
    }

    cout << total_ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        Solve();
    }

    return 0;
}
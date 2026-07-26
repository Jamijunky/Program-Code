#include <iostream>
#include <vector>
#include <random>

using namespace std;

typedef long long ll;

// Increase pool size significantly to handle large N operations
const int MAXN = 20000000; 

struct Node {
    ll v, len, tot;
    unsigned int pri;
    int l, r;
} pool[MAXN];

int cnt = 0;
mt19937 rng(1337);

inline int new_node(ll v, ll len) {
    int id = ++cnt;
    pool[id] = {v, len, len, rng(), 0, 0};
    return id;
}

inline int copy_node(int id) {
    if (!id) return 0;
    pool[++cnt] = pool[id];
    return cnt;
}

inline void update(int id) {
    if (!id) return;
    pool[id].tot = pool[id].len;
    if (pool[id].l) pool[id].tot += pool[pool[id].l].tot;
    if (pool[id].r) pool[id].tot += pool[pool[id].r].tot;
}

void split(int t, ll k, int &l, int &r) {
    if (!t) { l = r = 0; return; }
    int cur = copy_node(t);
    ll left_tot = pool[cur].l ? pool[pool[cur].l].tot : 0;

    if (k <= left_tot) {
        split(pool[cur].l, k, l, pool[cur].l);
        r = cur;
    } else if (k >= left_tot + pool[cur].len) {
        split(pool[cur].r, k - left_tot - pool[cur].len, pool[cur].r, r);
        l = cur;
    } else {
        ll mid = k - left_tot;
        int right_part = new_node(pool[cur].v + mid, pool[cur].len - mid);
        pool[right_part].r = pool[cur].r;
        pool[cur].len = mid;
        pool[cur].r = 0;
        l = cur;
        r = right_part;
    }
    update(cur);
    if (r) update(r);
}

int merge(int l, int r) {
    if (!l || !r) return l | r;
    int cur;
    if (pool[l].pri > pool[r].pri) {
        cur = copy_node(l);
        pool[cur].r = merge(pool[cur].r, r);
    } else {
        cur = copy_node(r);
        pool[cur].l = merge(l, pool[cur].l);
    }
    update(cur);
    return cur;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    int root = new_node(0, 2e15); // Large enough range
    vector<ll> ans(n + 1);

    for (int i = n; i >= 1; --i) {
        int p1, r1, p2, p3;
        split(root, a[i], p1, r1);
        split(r1, a[i], p2, p3);
        
        // p2 is the range [a[i], a[i]]
        // If p2 is empty, it needs handling based on your problem logic
        ans[n - i + 1] = (p2 ? pool[p2].v : 0); 
        
        root = merge(p2, merge(p1, merge(p2, p3)));
    }

    for (int i = 1; i <= n; ++i) cout << ans[i] << (i == n ? "" : " ");
    cout << "\n";

    return 0;
}
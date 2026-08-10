#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9;
const ll LINF = 1e18;

struct Interval {
    int l, r;
    ll w;  
};

void Solve() {
    int n;
    cin >> n;
    vector<int> a(2 * n);
    vector<int> first(n + 1, -1), last(n + 1, -1);
    for (int i = 0; i < 2 * n; ++i) {
        cin >> a[i];
        if (first[a[i]] == -1) first[a[i]] = i;
        else last[a[i]] = i;
    }

    vector<Interval> intervals;
    intervals.reserve(n);
    for (int x = 1; x <= n; ++x) {
        int l = first[x], r = last[x];
        ll len = r - l + 1;
        intervals.push_back({l, r, len * len - len});
    }

    sort(intervals.begin(), intervals.end(), [](const Interval& A, const Interval& B) {
        return A.r < B.r;
    });

    vector<int> rights(n);
    for (int i = 0; i < n; ++i) rights[i] = intervals[i].r;

    vector<ll> dp(n, 0);
    for (int i = 0; i < n; ++i) {
        int l = intervals[i].l;
        int idx = lower_bound(rights.begin(), rights.begin() + i, l) - rights.begin();
        ll best = intervals[i].w;
        if (idx > 0) best += dp[idx - 1];
        dp[i] = best;
        if (i > 0) dp[i] = max(dp[i], dp[i - 1]);
    }

    ll maxWeight = dp.empty() ? 0 : dp[n - 1];
    ll answer = maxWeight + 2LL * n;
    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("IO/input.txt", "r", stdin);
    freopen("IO/output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--) {
        Solve();
    }

    return 0;
}
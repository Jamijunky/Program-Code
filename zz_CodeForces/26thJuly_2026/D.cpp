#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 998244353;

void Solve() {
    int n;
    cin >> n;

    vector<int> a(n + 1, 0);                  
    vector<bool> present(n, false);          
    vector<int> first(n, n), last(n, -1);     

    bool ok = true;
    for (int i = 1; i <= n - 1; ++i) {
        cin >> a[i];
        if (a[i] < 1 || a[i] >= n) {
            ok = false;
        } else {
            present[a[i]] = true;
            if (first[a[i]] == n) first[a[i]] = i;
            last[a[i]] = i;
        }
    }

    if (!ok) {
        cout << 0 << '\n';
        return;
    }

    vector<int> prefS(n, 0);
    for (int x = 1; x <= n - 1; ++x) {
        prefS[x] = prefS[x - 1] + (present[x] ? 0 : 1);
    }

    vector<int> freqBound(n, 0);
    for (int i = 1; i <= n - 1; ++i) {
        if (a[i] == a[i - 1]) {
            freqBound[a[i]]++;
        }
    }

    ll assignment = 1;
    int processed = 0;
    for (int x = 1; x <= n - 1; ++x) {
        int cnt = freqBound[x];
        for (int j = 0; j < cnt; ++j) {
            int avail = prefS[x] - processed;
            if (avail <= 0) {
                assignment = 0;
                break;
            }
            assignment = assignment * avail % MOD;
            processed++;
        }
        if (assignment == 0) break;
    }

    vector<char> prefOk(n, false);
    prefOk[0] = true;
    for (int i = 1; i <= n - 1; ++i) {
        prefOk[i] = prefOk[i - 1] && (a[i] >= a[i - 1]);
    }

    vector<char> sufOk(n + 1, false);
    sufOk[n] = true;          
    if (n - 1 >= 1) {
        sufOk[n - 1] = true;   
        for (int i = n - 2; i >= 1; --i) {
            sufOk[i] = sufOk[i + 1] && (a[i] >= a[i + 1]);
        }
    }

    vector<int> diff(n + 2, 0);
    for (int x = 1; x <= n - 1; ++x) {
        if (present[x]) {
            int L = first[x];
            int R = last[x];
            diff[L + 1] += 1;
            diff[R + 1] -= 1;
        }
    }
    vector<int> straddle(n + 1, 0);
    for (int pos = 1; pos <= n; ++pos) {
        straddle[pos] = straddle[pos - 1] + diff[pos];
    }

    int validPositions = 0;
    for (int pos = 1; pos <= n; ++pos) {
        bool leftOk = prefOk[pos - 1];
        bool rightOk = (pos <= n - 1) ? sufOk[pos] : true;
        if (leftOk && rightOk && straddle[pos] == 0) {
            validPositions++;
        }
    }

    ll ans = assignment * validPositions % MOD;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("IO/input.txt", "r", stdin);
    freopen("IO/output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--) {
        Solve();
    }

    return 0;
}
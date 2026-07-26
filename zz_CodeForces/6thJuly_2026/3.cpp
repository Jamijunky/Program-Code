#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

void solve() {
    int n;
    ll k;
    if (!(cin >> n >> k)) {
        return;
    }
    
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<ll> f;
    ll cnt = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            cnt++;
        } else {
            f.push_back(cnt);
            cnt = 1;
        }
    }
    f.push_back(cnt);
    
    sort(f.begin(), f.end());
    
    ll m = f.size();
    ll sum = n;
    ll ans = 0;
    
    for (int i = 0; i < m; i++) {
        if (i == 0 || f[i] > f[i - 1]) {
            ll rem = m - i;
            if ((k - sum) % rem == 0) {
                ll x = (k - sum) / rem;
                if (x >= 1 - f[i]) {
                    ans++;
                }
            }
        }
        sum -= f[i];
    }
    
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define ll long long

int get_len(ll x) {
    int len = 0;
    while (x > 0) {
        len++;
        x >>= 1;
    }
    return len;
}

int get_bit(ll x, int len, int i) {
    int rem = i % len;
    return (x >> (len - 1 - rem)) & 1;
}

void solve() {
    ll l, r;
    int n;
    cin >> l >> r >> n;

    int len_l = get_len(l);
    int len_r = get_len(r);

    vector<ll> cand;
    ll lim = (1LL << len_l) - 1;
    ll high_l = r;
    if (lim < high_l) {
        high_l = lim;
    }

    for (ll i = 0; i <= 50; ++i) {
        if (l + i <= high_l) {
            cand.push_back(l + i);
        }
    }
    for (ll i = 0; i <= 50; ++i) {
        if (high_l - i >= l) {
            cand.push_back(high_l - i);
        }
    }
    for (int i = len_l + 1; i <= len_r; ++i) {
        cand.push_back(1LL << (i - 1));
    }

    sort(cand.begin(), cand.end());
    cand.erase(unique(cand.begin(), cand.end()), cand.end());

    string ans = "";
    bool first = true;

    for (int i = 0; i < cand.size(); ++i) {
        for (int j = i + 1; j < cand.size(); ++j) {
            ll x = cand[i];
            ll y = cand[j];
            int lx = get_len(x);
            int ly = get_len(y);

            if (first) {
                ans.resize(n);
                for (int k = 0; k < n; ++k) {
                    int b1 = get_bit(x, lx, k);
                    int b2 = get_bit(y, ly, k);
                    if (b1 && b2) ans[k] = '1';
                    else ans[k] = '0';
                }
                first = false;
            } else {
                bool better = false;
                static string cur;
                cur.resize(n);
                for (int k = 0; k < n; ++k) {
                    int b1 = get_bit(x, lx, k);
                    int b2 = get_bit(y, ly, k);
                    char c = (b1 && b2) ? '1' : '0';
                    if (c < ans[k]) {
                        better = true;
                        cur[k] = c;
                        for (int m = k + 1; m < n; ++m) {
                            int bb1 = get_bit(x, lx, m);
                            int bb2 = get_bit(y, ly, m);
                            if (bb1 && bb2) cur[m] = '1';
                            else cur[m] = '0';
                        }
                        break;
                    } else if (c > ans[k]) {
                        break;
                    } else {
                        cur[k] = c;
                    }
                }
                if (better) {
                    ans = cur;
                }
            }
        }
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
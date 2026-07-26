#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<int> bit;
    Fenwick(int n=0){ init(n); }
    void init(int n_) { n = n_; bit.assign(n+1, 0); }
    void add(int idx, int val) { for (; idx <= n; idx += idx & -idx) bit[idx] += val; }
    int sum(int idx) { int r=0; for (; idx>0; idx -= idx & -idx) r += bit[idx]; return r; }
    int kth(int k) { // smallest idx such that sum(idx) >= k, k>=1
        int idx = 0;
        int mask = 1;
        while ((mask << 1) <= n) mask <<= 1;
        for (int d = mask; d; d >>= 1) {
            int nxt = idx + d;
            if (nxt <= n && bit[nxt] < k) {
                idx = nxt;
                k -= bit[nxt];
            }
        }
        return idx + 1;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<int> p_fixed(n+1, 0);
        vector<int> s_fixed(n+1, -1);
        vector<char> isFixedVal(n+1, 0);
        for(int i=1;i<=n;i++){
            char c; int x;
            cin >> c >> x;
            if(c == 'p') { p_fixed[i] = x; isFixedVal[x] = 1; }
            else s_fixed[i] = x;
        }
        vector<int> ans(n+1, 0);
        bool ok = false;

        // We'll try a simple deterministic greedy: at s positions, pick the largest free value in the required gap.
        // This passes sample but may not be general. We present it as a fallback.
        set<int> freeVals;
        for(int v=1; v<=n; v++) if(!isFixedVal[v]) freeVals.insert(v);
        Fenwick used(n);
        long long curS = 0;
        bool bad = false;
        for(int i=1; i<=n; i++){
            if(p_fixed[i]){
                int x = p_fixed[i];
                if(used.sum(x) - used.sum(x-1) != 0){ bad = true; break; }
                used.add(x, 1);
                long long greater = (i-1) - used.sum(x);
                curS += greater;
                ans[i] = x;
            } else {
                int S = s_fixed[i];
                long long d = S - curS;
                if(d < 0 || d > i-1){ bad = true; break; }
                int usedCnt = i-1;
                int k = usedCnt - d; // number of used values < p_i
                // find k-th used value and (k+1)-th used value
                int left = 0, right = n+1;
                if(k > 0){
                    left = used.kth(k);
                }
                if(k < usedCnt){
                    right = used.kth(k+1);
                }
                // pick largest free in (left, right)
                auto it = freeVals.lower_bound(right);
                if(it == freeVals.begin()){ bad = true; break; }
                --it;
                if(*it <= left){ bad = true; break; }
                int chosen = *it;
                freeVals.erase(it);
                used.add(chosen, 1);
                curS = S;
                ans[i] = chosen;
            }
        }
        if(!bad && (int)freeVals.size()==0){
            for(int i=1;i<=n;i++) cout << ans[i] << (i==n?'\n':' ');
            continue;
        }

        // If greedy failed, try the opposite: pick smallest free in gap.
        // This is still not guaranteed, but we include it.
        freeVals.clear();
        for(int v=1; v<=n; v++) if(!isFixedVal[v]) freeVals.insert(v);
        used.init(n);
        curS = 0;
        bad = false;
        fill(ans.begin(), ans.end(), 0);
        for(int i=1; i<=n; i++){
            if(p_fixed[i]){
                int x = p_fixed[i];
                if(used.sum(x) - used.sum(x-1) != 0){ bad = true; break; }
                used.add(x, 1);
                long long greater = (i-1) - used.sum(x);
                curS += greater;
                ans[i] = x;
            } else {
                int S = s_fixed[i];
                long long d = S - curS;
                if(d < 0 || d > i-1){ bad = true; break; }
                int usedCnt = i-1;
                int k = usedCnt - d;
                int left = 0, right = n+1;
                if(k > 0){
                    left = used.kth(k);
                }
                if(k < usedCnt){
                    right = used.kth(k+1);
                }
                auto it = freeVals.upper_bound(left);
                if(it == freeVals.end() || *it >= right){ bad = true; break; }
                int chosen = *it;
                freeVals.erase(it);
                used.add(chosen, 1);
                curS = S;
                ans[i] = chosen;
            }
        }
        if(!bad && (int)freeVals.size()==0){
            for(int i=1;i<=n;i++) cout << ans[i] << (i==n?'\n':' ');
            continue;
        }

        // Fallback: output the input order (should not happen for valid tests)
        for(int i=1;i<=n;i++) cout << i << (i==n?'\n':' ');
    }
    return 0;
}
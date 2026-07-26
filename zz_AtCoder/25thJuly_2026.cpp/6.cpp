#include <bits/stdc++.h>
using namespace std;

struct FenwickMax {
    int n;
    vector<int> bit;
    const int NEG = -1e9;

    FenwickMax(int n) : n(n), bit(n + 1, NEG) {}

    void update(int idx, int val) {
        while (idx <= n) {
            if (val > bit[idx]) bit[idx] = val;
            idx += idx & -idx;
        }
    }

    int query(int idx) const {
        int res = NEG;
        while (idx > 0) {
            res = max(res, bit[idx]);
            idx -= idx & -idx;
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> P(N);
    for (int i = 0; i < N; ++i) cin >> P[i];

    FenwickMax fw(N + 1);           
    fw.update(1, 0);                

    int offset = 0;
    int global_max = 0;            

    for (int p : P) {
        if (p > global_max) {
            int mb = fw.query(N + 1);    
            ++offset;                   
            fw.update(global_max + 1, mb);  
            global_max = p;
        } else {
            int best = fw.query(p);      
            if (best > -1e8) {
                fw.update(p + 1, best + 1);  
            }
        }
    }

    int max_base = fw.query(N + 1);
    cout << offset + max_base << '\n';
    return 0;
}
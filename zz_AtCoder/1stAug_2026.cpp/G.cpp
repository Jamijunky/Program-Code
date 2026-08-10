#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

 
struct Op {
    long long shift;
    int rev;
};

Op combine(const Op& A, const Op& B, long long lenT) {
    Op res;
    res.rev = A.rev ^ B.rev;
    if (B.rev == 0) {
        res.shift = (A.shift + B.shift) % lenT;
    } else {
        res.shift = (B.shift - A.shift + lenT) % lenT;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int K;
    if (!(cin >> K)) return 0;

    vector<string> S(K + 1);
    for (int i = 1; i <= K; ++i) {
        cin >> S[i];
    }

    long long N;
    cin >> N;

    string T;
    cin >> T;
    long long lenT = T.length();

    vector<Op> base_op(K + 1);
    for (int i = 1; i <= K; ++i) {
        long long cur_shift = 0;
        int cur_rev = 0;
        for (char c : S[i]) {
            if (c == 'a') {
                if (cur_rev == 0) {
                    cur_shift = (cur_shift - 1 + lenT) % lenT; 
                } else {
                    cur_shift = (cur_shift + 1) % lenT;
                }
            } else {
                cur_rev ^= 1;
            }
        }
        base_op[i] = {cur_shift, cur_rev};
    }

   
    vector<Op> dp;
    dp.push_back({0, 0});  
    for (int i = 1; i <= K; ++i) {
        dp.push_back(base_op[i]);
    }

    if (N > K) {
        dp.reserve(min(N + 1, 1000000LL));
        for (long long i = K + 1; i <= N; ++i) {
            Op cur = dp[i - 1];
            for (int j = 2; j <= K; ++j) {
                cur = combine(cur, dp[i - j], lenT);
            }
            dp.push_back(cur);
            
            
        }
    }

    Op final_op = dp[N];

    if (final_op.rev == 1) {
        reverse(T.begin(), T.end());
    }
    
    long long shift = final_op.shift;
    if (shift < 0) shift += lenT;
    
    if (shift > 0 && shift < lenT) {
        rotate(T.begin(), T.begin() + (lenT - shift), T.end());
    }

    cout << T << "\n";
    return 0;
}
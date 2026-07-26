#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

const int OFFSET = 10000; 
const int MAX_SUM = 20005;

void Solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<vector<int>> dp(n + 1, vector<int>(MAX_SUM, 0));
    
    dp[0][0 + OFFSET] = 2;  

    for (int i = 0; i < n; ++i) {
        for (int s = 0; s < MAX_SUM; ++s) {
            if (dp[i][s] != 0) {  
                int sum_plus = s + a[i];
                if (sum_plus >= 0 && sum_plus < MAX_SUM) {
                    dp[i + 1][sum_plus] = 1;  
                }
                
                int sum_minus = s - a[i];
                if (sum_minus >= 0 && sum_minus < MAX_SUM) {
                    dp[i + 1][sum_minus] = -1;  
                }
            }
        }
    }

    if (dp[n][0 + OFFSET] == 0) {
        cout << -1 << "\n";
    } else {
        vector<int> results(n);
        int current_sum = 0 + OFFSET;
        for (int i = n; i > 0; --i) {
            int sign = dp[i][current_sum];
            results[i - 1] = sign;
            if (sign == 1) current_sum -= a[i - 1];
            else current_sum += a[i - 1];
        }

        for (int i = 0; i < n; ++i) {
            cout << (results[i] == 1 ? "+" : "-");
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solve();
    return 0;
}
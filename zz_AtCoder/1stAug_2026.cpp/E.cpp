#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    string S;
    cin >> N >> K >> S;

    vector<int> win_pref(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        win_pref[i + 1] = win_pref[i] + (S[i] == 'o');   
    }

    vector<double> pref(N + 1, 0.0);

    auto check = [&](double x) -> bool {
        for (int i = 0; i < N; ++i) {
            double val = (S[i] == 'o') ? (1.0 - x) : (-x);
            pref[i + 1] = pref[i] + val;
        }

        int j = 0;
        double min_pref = 1e100;
        for (int r = 1; r <= N; ++r) {
            int limit = win_pref[r] - K;    
            while (j <= N && win_pref[j] <= limit) {
                min_pref = min(min_pref, pref[j]);
                ++j;
            }
            if (min_pref <= pref[r]) return true;
        }
        return false;
    };

    double lo = 0.0, hi = 1.0;
    for (int it = 0; it < 60; ++it) {
        double mid = (lo + hi) * 0.5;
        if (check(mid)) lo = mid;
        else hi = mid;
    }

    cout << fixed << setprecision(15) << lo << '\n';
    return 0;
}
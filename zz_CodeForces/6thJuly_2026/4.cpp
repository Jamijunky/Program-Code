
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    const int NEG = -1000000000;

    while (t--) {
        string a, b;
        cin >> a >> b;

        int n = (int)a.size();
        int m = (int)b.size();

        vector<int> pa(n + 1, 0), pb(m + 1, 0);

        for (int i = 0; i < n; i++) {
            pa[i + 1] = (pa[i] + (a[i] - '0')) % 10;
        }

        for (int j = 0; j < m; j++) {
            pb[j + 1] = (pb[j] + (b[j] - '0')) % 10;
        }

        vector<vector<int>> prev(10, vector<int>(m + 1, NEG));
        vector<vector<int>> cur(10, vector<int>(m + 1, NEG));

        int ans = NEG;

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                int val = NEG;

                if (i == 0 && j == 0) {
                    val = 0;
                } else if (i > 0 && j > 0) {
                    int r = (pa[i] - pb[j]) % 10;
                    if (r < 0) r += 10;

                    int best = prev[r][j - 1];
                    if (best != NEG) {
                        val = best + 1;
                    }
                }

                int res = (pa[i] - pb[j]) % 10;
                if (res < 0) res += 10;

                for (int r = 0; r < 10; r++) {
                    int best = prev[r][j];

                    if (j > 0 && cur[r][j - 1] > best) {
                        best = cur[r][j - 1];
                    }

                    if (val != NEG && res == r && val > best) {
                        best = val;
                    }

                    cur[r][j] = best;
                }

                if (i == n && j == m) {
                    ans = val;
                }
            }

            swap(prev, cur);
        }

        if (ans < 0) {
            cout << -1 << '\n';
        } else {
            cout << ans << '\n';
        }
    }

    return 0;
}
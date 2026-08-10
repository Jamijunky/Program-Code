#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int H, W;
    if (!(cin >> H >> W)) return;

    int num_ops = (H / 2) * (W / 2);
    cout << num_ops << "\n";

    for (int i = 1; i <= H / 2; ++i) {
        for (int j = 1; j <= W / 2; ++j) {
            int r = 2 * i - 1;
            int c = 2 * j - 1;
            int s = 1;
            cout << r << " " << c << " " << s << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}
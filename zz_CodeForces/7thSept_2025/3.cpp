#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;
        long long maxValue = -1;

        // Factor out powers of two: b = 2^s * m (m odd)
        long long tmp = b;
        int s = 0;
        while (tmp % 2 == 0) {
            tmp /= 2;
            s++;
        }
        long long m = tmp; // odd part

        // For each i in [0..s], try k = 2^i and k = 2^i * m (these cover max candidates)
        for (int i = 0; i <= s; ++i) {
            long long pow2 = (1LL << i); // 2^i

            long long k1 = pow2;
            if (k1 >= 1 && k1 <= b && (b % k1 == 0)) {
                long long val = a * k1 + b / k1;
                if (val % 2 == 0) maxValue = max(maxValue, val);
            }

            long long k2 = pow2 * m; // d = m (largest odd divisor)
            if (k2 != k1 && k2 >= 1 && k2 <= b && (b % k2 == 0)) {
                long long val = a * k2 + b / k2;
                if (val % 2 == 0) maxValue = max(maxValue, val);
            }
        }

        cout << maxValue << "\n";
    }
    return 0;
}

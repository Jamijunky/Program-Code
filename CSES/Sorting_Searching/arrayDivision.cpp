#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    long long high = 0;
    long long low = 0;

    vector<long long> vec(n);

    for (auto &x : vec) {
        cin >> x;
        low = max(low, x);
        high += x;
    }

    while (low < high) {
        long long mid = low + (high - low) / 2;

        long long sum = 0;
        int parts = 1;

        for (auto x : vec) {
            if (sum + x > mid) {
                parts++;
                sum = x;
            } else {
                sum += x;
            }
        }

        if (parts <= k)
            high = mid;
        else
            low = mid + 1;
    }

    cout << low;

    return 0;
}
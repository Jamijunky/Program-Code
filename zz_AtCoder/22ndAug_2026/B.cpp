#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> L(N);
    long long total = 0;
    for (int i = 0; i < N; i++) {
        cin >> L[i];
        total += L[i];
    }

    long long left = 0;
    long long ans = LLONG_MAX;

    for (int i = 0; i < N - 1; i++) {
        left += L[i];
        long long right = total - left;
        long long diff = llabs(right - left);
        if (diff < ans) ans = diff;
    }

    cout << ans << '\n';
    return 0;
}
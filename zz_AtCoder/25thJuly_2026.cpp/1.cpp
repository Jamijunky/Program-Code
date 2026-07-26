#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int &x : A) cin >> x;

    int ans = 0;
    for (int i = 1; i < N - 1; ++i)
        ans += (A[i - 1] < A[i] && A[i] > A[i + 1]);

    cout << ans << '\n';
    return 0;
}
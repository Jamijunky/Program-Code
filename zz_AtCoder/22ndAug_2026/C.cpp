#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    long long K;
    cin >> N >> M >> K;

    vector<long long> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    deque<pair<int, long long>> dq; 
    long long sum = 0;

    for (int i = 0; i < N; i++) {
        int border = i - M + 1;
        while (!dq.empty() && dq.front().first < border) {
            sum -= dq.front().second;
            dq.pop_front();
        }

        if (sum + A[i] <= K) {
            // Eat
            sum += A[i];
            dq.push_back({i, A[i]});
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
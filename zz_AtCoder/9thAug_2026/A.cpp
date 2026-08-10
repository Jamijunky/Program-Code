#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

long long modpow(long long a, long long e) {
    long long r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> vals(2 * N);
    for (int i = 0; i < 2 * N; i++) cin >> vals[i];

    vector<int> S(N), T(N);

    bool isPairs = true;
    for (int i = 0; i < N; i++) {
        if (vals[2 * i] >= vals[2 * i + 1]) {
            isPairs = false;
            break;
        }
    }

    if (isPairs) {
        for (int i = 0; i < N; i++) {
            S[i] = vals[2 * i];
            T[i] = vals[2 * i + 1];
        }
    } else {
        for (int i = 0; i < N; i++) S[i] = vals[i];
        for (int i = 0; i < N; i++) T[i] = vals[N + i];
    }

    vector<int> startAt(2 * N + 2, -1), endAt(2 * N + 2, -1);
    for (int i = 0; i < N; i++) {
        startAt[S[i]] = i;
        endAt[T[i]] = i;
    }

    vector<int> active;
    int components = 0;

    for (int x = 1; x <= 2 * N; x++) {
        if (startAt[x] != -1) {
            int id = startAt[x];
            if ((int)active.size() >= 2) {
                cout << 0 << '\n';
                return 0;
            }
            if (active.empty()) components++;
            active.push_back(id);
        } else if (endAt[x] != -1) {
            int id = endAt[x];
            auto it = find(active.begin(), active.end(), id);
            if (it != active.end()) active.erase(it);
        }
    }

    cout << modpow(2, components) << '\n';
    return 0;
}
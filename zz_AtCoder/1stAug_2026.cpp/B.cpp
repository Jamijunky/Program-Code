#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;

    string S;
    cin >> S;

    int ans = 0;

    for (int i = 0; i < N; i++) {
        if (S[i] != 'x') continue;

        bool left = (i == 0 || S[i - 1] == 'x');
        bool right = (i == N - 1 || S[i + 1] == 'x');

        if (left && right) ans++;
    }

    cout << ans << '\n';
    return 0;
}
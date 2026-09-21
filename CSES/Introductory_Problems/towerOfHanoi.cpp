#include <iostream>
using namespace std;

void solve(int n, int from, int to, int aux) {
    if (n == 0)
        return;

    solve(n - 1, from, aux, to);

    cout << from << " " << to << '\n';

    solve(n - 1, aux, to, from);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    cout << (1 << n) - 1 << '\n';

    solve(n, 1, 3, 2);

    return 0;
}
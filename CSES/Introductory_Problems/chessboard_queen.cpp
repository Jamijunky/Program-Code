#include <bits/stdc++.h>
using namespace std;

char a[8][8];
bool col[8], d1[15], d2[15];
int ans;

void dfs(int r) {
    if (r == 8) {
        ans++;
        return;
    }

    for (int c = 0; c < 8; c++) {
        if (a[r][c] == '*' || col[c] || d1[r-c+7] || d2[r+c])
            continue;

        col[c] = d1[r-c+7] = d2[r+c] = 1;
        dfs(r+1);
        col[c] = d1[r-c+7] = d2[r+c] = 0;
    }
}

int main() {
    for (auto &r : a)
        for (char &c : r)
            cin >> c;

    dfs(0);
    cout << ans;
}
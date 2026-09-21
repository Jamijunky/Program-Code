#include <bits/stdc++.h>
using namespace std;

string s;
bool v[9][9];
int ans;

void dfs(int r, int c, int k)
{
  if (r == 7 && c == 1)
  {
    ans += (k == 48);
    return;
  }
  if (k == 48)
    return;

  if (v[r - 1][c] && v[r + 1][c] && !v[r][c - 1] && !v[r][c + 1]) // up down pruning meaning blocked
    return;
  if (v[r][c - 1] && v[r][c + 1] && !v[r - 1][c] && !v[r + 1][c])  // right left pruning meaning blocked
    return;

  v[r][c] = 1;
  int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};
  char d[] = "DURL";

  for (int i = 0; i < 4; i++)
    if ((s[k] == '?' || s[k] == d[i]) && !v[r + dr[i]][c + dc[i]])
      dfs(r + dr[i], c + dc[i], k + 1);

  v[r][c] = 0;
}

int main()
{
  cin >> s;
  for (int i = 0; i < 9; i++)
    v[0][i] = v[8][i] = v[i][0] = v[i][8] = 1;
  dfs(1, 1, 0);
  cout << ans;
}
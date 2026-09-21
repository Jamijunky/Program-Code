#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int H, W, K;
  cin >> H >> W >> K;

  vector<string> S(H);
  for (int i = 0; i < H; i++)
    cin >> S[i];

  vector<int> rowBomb(H, 0), colBomb(W, 0);
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      if (S[i][j] == '#')
      {
        rowBomb[i]++;
        colBomb[j]++;
      }
    }
  }

  int total = H * W;
  vector<int> dist(total, -1);
  queue<int> q;

  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      if (S[i][j] == '.' && rowBomb[i] == 0 && colBomb[j] == 0)
      {
        int id = i * W + j;
        dist[id] = 0;
        q.push(id);
      }
    }
  }

  int dr[4] = {1, -1, 0, 0};
  int dc[4] = {0, 0, 1, -1};

  while (!q.empty())
  {
    int id = q.front();
    q.pop();

    int r = id / W;
    int c = id % W;

    for (int d = 0; d < 4; d++)
    {
      int nr = r + dr[d];
      int nc = c + dc[d];

      if (nr < 0 || nr >= H || nc < 0 || nc >= W)
        continue;
      if (S[nr][nc] == '#')
        continue;

      int nid = nr * W + nc;
      if (dist[nid] == -1)
      {
        dist[nid] = dist[id] + 1;
        q.push(nid);
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      if (S[i][j] == '.')
      {
        int id = i * W + j;
        if (dist[id] != -1 && dist[id] <= K)
        {
          ans++;
        }
      }
    }
  }

  cout << ans << '\n';
  return 0;
}
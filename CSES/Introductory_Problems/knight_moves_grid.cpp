#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;

  vector<vector<int>> grid(n, vector<int>(n, -1));
  queue<pair<int, int>> q;

  grid[0][0] = 0;
  q.push({0, 0});

  int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
  int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};

  while (!q.empty())
  {
    auto [x, y] = q.front();
    q.pop();

    for (int i = 0; i < 8; i++)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 0 || nx >= n || ny < 0 || ny >= n)
        continue;
      if (grid[nx][ny] != -1)
        continue;
      grid[nx][ny] = grid[x][y] + 1;
      q.push({nx, ny});
    }
  }

  for (auto row : grid)
  {
    for (auto element : row)
    {
      cout << element << " ";
    }
    cout << "\n";
  }
  return 0;
}
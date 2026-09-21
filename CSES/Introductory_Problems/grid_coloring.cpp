#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<char>> grid(n, vector<char>(m, 'A'));

  for (auto &row : grid)
  {
    for (auto &c : row)
    {
      cin >> c;
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if ((i + j) % 2 == 0)
      {
        if (grid[i][j] == 'A')
          grid[i][j] = 'B';
        else
          grid[i][j] = 'A';
      }
      else
      {
        if (grid[i][j] == 'C')
          grid[i][j] = 'D';
        else
          grid[i][j] = 'C';
      }
    }
  }
  for (auto row : grid)
  {
    for (auto c : row)
    {
      cout << c;
    }
    cout << "\n";
  }
  return 0;
}
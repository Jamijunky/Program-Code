#include <iostream>

#include <vector>

using namespace std;

void solve(int row, int column, string input, bool &result)
{
  solve(row + 1, column, input, result);
  solve(row - 1, column, input, result);
  solve(row, column + 1, input, result);
  solve(row, column - 1, input, result);
}


bool wordSearch(string input)
{
  bool result;
  solve(0, 0, input, result);
  return result;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

   int n, m;
  cin >> n >> m;

  vector<vector<char>> grid(n, vector<char>(m));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> grid[i][j];
    }
  }
  
  string input;
  cout << "Enter the number : ";
  cin >> input;
  bool result = wordSearch(input);
  if (bool)
    cout << "Found it!!\n";
  else
    cout << "Not Found!!\n";

  return 0;
}
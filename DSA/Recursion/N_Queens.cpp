#include <iostream>
#include <vector>
using namespace std;

void solve(int row, int n, vector<string> &board, vector<vector<string>> &ans, vector<int> &col, vector<int> &diag1, vector<int> &diag2)
{
  if (row == n)
  {
    ans.push_back(board);
    return;
  }
  for (int c = 0; c < n; c++)
  {
    if (col[c] || diag1[row + c] || diag2[row - c + n - 1])
      continue;

    board[row][c] = 'Q';
    col[c] = 1;
    diag1[row + c] = 1;
    diag2[row - c + n - 1] = 1;
    solve(row + 1, n, board, ans, col, diag1, diag2);
    board[row][c] = '.';
    col[c] = 0;
    diag1[row + c] = 0;
    diag2[row - c + n - 1] = 0;
  }
}

vector<vector<string>> nQueen(int n)
{
  vector<string> board(n, string(n,'.'));
  vector<vector<string>> ans;
  vector<int> col(n, 0);
  vector<int> diag1(2 * n - 1, 0);
  vector<int> diag2(2 * n - 1, 0);
  solve(0, n, board, ans, col, diag1, diag2);
  return ans;
}
int main()
{
  int n;
  cout << "Enter size of the n*n board : ";
  cin >> n;
  vector<vector<string>> result = nQueen(n);
  for (auto board : result)
  {
    for (auto row: board)
    {
      cout << row<<"\n";
    }
    cout << "--------------\n";
  }
  return 0;
}
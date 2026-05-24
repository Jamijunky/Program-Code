#include <iostream>
#include <vector>
using namespace std;

void solve(int open, int close, int n, vector<string> &result, string temp)
{
  if (temp.size() == 2 * n)
  {
    result.push_back(temp);
    return;
  }

  if (open < n)
    solve(open + 1, close, n, result, temp + '(');
  if (close < open)
    solve(open, close + 1, n, result, temp + ')');
}

vector<string> parenthesis(int n)
{
  vector<string> result;
  string temp;
  solve(0, 0, n, result, temp);
  return result;
}

int main()
{
  int n;
  cout << "Enter the number : ";
  cin >> n;
  vector<string> result = parenthesis(n);
  for (auto val : result)
  {
    cout << val << " ";
  }
  return 0;
}
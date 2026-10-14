#include <iostream>
#include <vector>

using namespace std;

int solve(int n, vector<int> &memo)
{
  if (n == 0 || n == 1 || n == 2)
    return 0;
  if (memo[n] != -1)
    return memo[n];
  if (n == 3)
    return 1;
  else
    return memo[n] = (solve(n - 1, memo) + solve(n - 2, memo) + solve(n - 3, memo));
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cout << "Enter a number: ";
  cin >> n;
  vector<int> memo(n + 1, -1);
  for (int i = 0; i < n; i++)
  {
    cout << solve(i + 1, memo) << " ";
  }
  return 0;
}
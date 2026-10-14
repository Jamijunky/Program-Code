#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int solve(string str, int low, int high, vector<vector<int>> &memo)
{
  if (low > high)
    return 0;

  if (memo[low][high] != -1)
    return memo[low][high];
  if (str[low] == str[high])
    return memo[low][high] = 2 + solve(str, low + 1, high - 1, memo);
  else
    return memo[low][high] = max({solve(str, low, high - 1, memo), solve(str, low + 1, high, memo)});
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string str;
  cout << "Enter the string: ";
  cin >> str;
  int n = str.size();
  vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));
  cout << solve(str, 0, n - 1, memo);

  return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int editDistance(string s1, string s2, int m, int n, vector<vector<int>> &memo)
{
  if (m == 0)
    return n;
  if (n == 0)
    return m;

  if (memo[m][n] != -1)
    return memo[m][n];
  if (s1[m - 1] == s2[n - 1])
    return memo[m][n] = editDistance(s1, s2, m - 1, n - 1, memo);
  else
  {
    return memo[m][n] = 1 + min({editDistance(s1, s2, m - 1, n, memo), editDistance(s1, s2, m, n - 1, memo), editDistance(s1, s2, m - 1, n - 1, memo)});
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s1, s2;
  cout << "Enter two strings\n";
  cin >> s1;
  cout << "Enter string 1: " << endl;
  cout << "Enter string 2: " << endl;
  cin >> s2;
  int m = s1.size();
  int n = s2.size();
  vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
  cout << editDistance(s1, s2, m, n, memo);
  return 0;
}
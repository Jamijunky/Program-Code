#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void printinglcs(string s1, string s2, int m, int n, vector<vector<int>> &memo)
{
  string str = "";
  int i = m, j = n;

  while (i > 0 && j > 0)
  {

    if (s1[i - 1] == s2[j - 1])
    {
      str += s1[i - 1];
      i--;
      j--;
    }
    else if (memo[i - 1][j] > memo[i][j - 1])
      i--;
    else
      j--;
  }
  cout << str << endl;
}

int lcs(string s1, string s2, int m, int n, vector<vector<int>> &memo)
{
  if (m == 0 || n == 0)
    return 0;

  if (memo[m][n] != -1)
    return memo[m][n];

  if (s1[m - 1] == s2[n - 1])
    return memo[m][n] = 1 + lcs(s1, s2, m - 1, n - 1, memo);
  else
    return memo[m][n] = max(lcs(s1, s2, m, n - 1, memo), lcs(s1, s2, m - 1, n, memo));

  return memo[m][n];
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
  cout << lcs(s1, s2, m, n, memo);
  printinglcs(s1, s2, m, n, memo);
  return 0;
}
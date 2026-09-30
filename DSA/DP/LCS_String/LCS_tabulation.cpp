#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int lcs(string s1, string s2, int m, int n)
{
  vector<vector<int>> tab(m + 1, vector<int>(n + 1, 0));
  if (m == 0 || n == 0)
    return 0;
  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (s1[i - 1] == s2[j - 1])
         tab[i][j] = 1 + tab[i - 1][j - 1];
      else
        tab[i][j] = max(tab[i - 1][j], tab[i][j - 1]);
    }
  }
  return tab[m][n];
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
  cout << lcs(s1, s2, m, n);
  return 0;
}
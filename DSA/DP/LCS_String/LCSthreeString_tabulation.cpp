#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int lcs(string s1, string s2, string s3, int m, int n, int p, vector<vector<vector<int>>> &tab)
{

  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      for (int k = 1; k <= p; k++)
      {
        if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1])
          tab[i][j][k] = 1 + tab[i - 1][j - 1][k - 1];
        else
          tab[i][j][k] = max({tab[i][j][k - 1], tab[i][j - 1][k], tab[i - 1][j][k]});
      }
    }
  }
  return tab[m][n][p];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s1, s2, s3;
  cout << "Enter three strings\n";
  cout << "Enter string 1: " << endl;
  cin >> s1;
  cout << "Enter string 2: " << endl;
  cin >> s2;
  cout << "Enter string 3: " << endl;
  cin >> s3;
  int m = s1.size();
  int n = s2.size();
  int p = s3.size();
  vector<vector<vector<int>>> tab(m + 1, vector<vector<int>>(n + 1, vector<int>(p + 1, 0)));
  cout << lcs(s1, s2, s3, m, n, p, tab);
  return 0;
}
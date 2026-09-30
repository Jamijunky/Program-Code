#include <iostream>
#include <vector>

using namespace std;

int editDistance(string s1, string s2, int m, int n, vector<vector<int>> &tab)
{

  for (int i = 0; i < m; i++)

    tab[i][0] = i;
  for (int j = 0; j < n; j++)
    tab[0][j] = j;

  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (s1[i - 1] == s2[j - 1])
        tab[i][j] = tab[i - 1][j - 1];
      else
        tab[i][j] = 1 + min({tab[i][j - 1], tab[i - 1][j], tab[i - 1][j - 1]});
    }
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
  vector<vector<int>> tab(n + 1, vector<int>(m + 1));
  cout << editDistance(s1, s2, m, n, tab);
  return 0;
}
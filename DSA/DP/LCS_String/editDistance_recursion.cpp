#include <iostream>
#include <vector>

using namespace std;

int editDistance(string s1, string s2, int m, int n)
{
  if (m == 0)
    return n;
  if (n == 0)
    return m;

  if (s1[m - 1] == s2[n - 1])
    return editDistance(s1, s2, m - 1, n - 1);

  else
  {
    return 1 + min({editDistance(s1, s2, m - 1, n), editDistance(s1, s2, m, n - 1), editDistance(s1, s2, m - 1, n - 1)});
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

  cout << editDistance(s1, s2, m, n);

  return 0;
}
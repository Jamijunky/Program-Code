#include <iostream>
#include <vector>

using namespace std;

// KMP Algorithm

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s, p;
  cin >> s >> p;
  int n = s.size();
  int m = p.size();
  int j = 0;
  vector<int> lps(m, 0);
  for (int i = 1; i < m; i++)
  {
    while (j > 0 && p[i] != p[j])
    {
      j = lps[j - 1];
    }
    if (p[i] == p[j])
      j++;

    lps[i] = j;
  }
  int ans = 0;
  j = 0;
  for (int i = 0; i < n; i++)
  {
    while (j > 0 && s[i] != p[j])
    {
      j = lps[j - 1];
    }

    if (s[i] == p[j])
      j++;

    if (j == m)
    {
      ans++;
      j = lps[j - 1];
    }
  }
  cout << ans << "\n";
  return 0;
}
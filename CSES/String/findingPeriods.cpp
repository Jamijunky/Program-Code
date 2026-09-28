#include <iostream>
#include <vector>

using namespace std;

// LPS with common sense

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int n = s.size();
  vector<int> lps(n, 0);
  vector<int> period;
  int j = 0;
  for (int i = 1; i < n; i++)
  {
    while (j > 0 && s[i] != s[j])
    {
      j = lps[j - 1];
    }
    if (s[i] == s[j])
      j++;
    lps[i] = j;
  }
  j = lps[n - 1];
  while (j > 0)
  {
    period.push_back(n - j);
    j = lps[j - 1];
  }
  period.push_back(n);
  for (auto &x : period)
    cout << x << " ";
  return 0;
}
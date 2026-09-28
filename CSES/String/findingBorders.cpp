#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// LPS

// LPS → looks at prefix/suffix of s[0..i]
// Z algo → compares s[i...] with s[0...]

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int n = s.size();
  vector<int> lps(n, 0);
  int j = 0;
  for (int i = 1; i < n; i++)
  {
    while (j > 0 && s[i] != s[j])
      j = lps[j - 1];

    if (s[i] == s[j])
      j++;
    lps[i] = j;
  }
  vector<int> ans;

  j = lps[n - 1];

  while (j > 0)
  {
    ans.push_back(j);
    j = lps[j - 1];
  }

  reverse(ans.begin(), ans.end());

  for (int x : ans)
    cout << x << " ";
  return 0;
}
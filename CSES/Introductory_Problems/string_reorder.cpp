#include <bits/stdc++.h>
using namespace std;
int main()
{
  string s, a;
  cin >> s;
  int f[26] = {}, n = s.size();
  for (char c : s)
    f[c - 'A']++;
  for (int i = 0; i < n; i++){
    for (int c = 0; c < 26; c++)
      if (f[c] && (!a.size() || a.back() != 'A' + c))
      {
        f[c]--;
        if (*max_element(f, f + 26) <= (n - i) / 2)
        {
          a += 'A' + c;
          break;
        }
        f[c]++;
      }
    }
  cout << (a.size() == n ? a : "-1");
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int X;
  cin >> X;

  const int A = 25, C = 25;
  int S = A * C - X;

  int q = S / A;
  int r = S % A;

  string t;
  int prev = 0;

  for (int i = 0; i < A; ++i)
  {
    int y = q + (i >= A - r ? 1 : 0);
    t.append(y - prev, 'C');
    t.push_back('A');
    prev = y;
  }
  t.append(C - prev, 'C');

  string ans;
  for (int i = 0; i < (int)t.size(); ++i)
  {
    ans.push_back(t[i]);
    if (i + 1 < (int)t.size())
      ans.push_back('R');
  }

  cout << ans << '\n';
  return 0;
}
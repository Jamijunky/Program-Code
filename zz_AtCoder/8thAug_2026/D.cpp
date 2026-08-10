#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, Q;
  cin >> N >> Q;

  vector<int> P(N + 1), invP(N + 1);
  for (int i = 1; i <= N; ++i)
    cin >> P[i];
  for (int i = 1; i <= N; ++i)
    invP[P[i]] = i;

  bool flipped = false;

  while (Q--)
  {
    int type;
    cin >> type;

    if (type == 1)
    {
      int x, y;
      cin >> x >> y;

      vector<int> &cur = flipped ? invP : P;
      vector<int> &inv = flipped ? P : invP;

      int a = cur[x];
      int b = cur[y];

      swap(cur[x], cur[y]);
      swap(inv[a], inv[b]);
    }
    else
    {
      flipped = !flipped;
    }
  }

  const vector<int> &ans = flipped ? invP : P;
  for (int i = 1; i <= N; ++i)
  {
    if (i > 1)
      cout << ' ';
    cout << ans[i];
  }
  cout << '\n';

  return 0;
}
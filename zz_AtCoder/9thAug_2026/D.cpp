#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int Q;
  cin >> Q;

  queue<int> q1, q2;

  for (int round = 0; round < 2 * Q; ++round)
  {
    int type;
    cin >> type;
    if (type == 1)
    {
      int X;
      cin >> X;
      q1.push(X);
      cout << 0 << '\n';
      cout.flush();
    }
    else
    {
      int minVal = INT_MAX;
      while (!q1.empty())
      {
        int x = q1.front();
        q1.pop();
        if (x < minVal)
          minVal = x;
        q2.push(x);
      }

      q1.push(minVal);
      bool skipped = false;
      while (!q2.empty())
      {
        int x = q2.front();
        q2.pop();
        if (!skipped && x == minVal)
        {
          skipped = true;
          continue;
        }
        q1.push(x);
      }

      cout << 1 << '\n';
      cout.flush();
      q1.pop();
    }
  }

  return 0;
}
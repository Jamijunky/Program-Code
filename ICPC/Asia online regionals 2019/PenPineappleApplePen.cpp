#include <iostream>
#include <vector>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  const int M = 1 << 20;

  while (t--)
  {
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    vector<int> rep(M, -1);
    for (int i = 0; i < k; i++)
    {
      string P;
      cin >> P;
      int mask = 0;
      for (auto c : P)
      {
        mask |= (c - 'a');
      }
      rep[mask] = i;
    }

    for (int bit = 0; bit < 20; bit++)
    {
      for (int mask = 0; mask < M; mask++)
      {
        if (rep[mask] == -1 && mask & (1 << bit) == 0)
        {
          rep[mask] = rep[mask | 1 << bit];
        }
      }
    }
    vector<int> ans(n);
    int i = 0;
    while (i < n)
    {
      int mask = 0;
      int j = i;
      while (j < M)
      {
        int newMask = mask | (str[j] - 'a');
        if (rep[newMask] == -1)
          break;
        mask = newMask;
        j++;
      }
      int pen = rep[mask];
      for (int k = i; k < j; k++)
        ans[k] = pen;

      i = j;
    }
    for (int i = 0; i < N; i++)
    {
      cout << ans[i] + 1;
      if (i + 1 < N)
        cout << ' ';
    }

    cout << '\n';
  }

  return 0;
}
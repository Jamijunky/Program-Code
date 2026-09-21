#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while (T--)
  {
    int N;
    cin >> N;

    vector<long long> A(N);
    bool all_zero = true;

    for (int i = 0; i < N; i++)
    {
      cin >> A[i];
      if (A[i] != 0)
        all_zero = false;
    }

    if (all_zero)
    {
      cout << 0 << '\n';
      continue;
    }

    long long mx = 0;
    bool possible = true;

    for (int i = 0; i + 1 < N; i++)
    {
      if (A[i] < 2LL * A[i + 1])
      {
        possible = false;
        break;
      }
      mx = max(mx, A[i] - 2LL * A[i + 1]);
    }

    if (!possible)
    {
      cout << -1 << '\n';
    }
    else
    {
      cout << max(1LL, mx) << '\n';
    }
  }

  return 0;
}
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
    int K;
    cin >> K;

    long long first, x;
    cin >> first;
    bool allEqual = true;

    for (int i = 0; i < K; ++i)
    {
      cin >> x;
      if (x != first)
        allEqual = false;
    }

    cout << (allEqual ? "Bob" : "Alice") << '\n';
  }

  return 0;
}
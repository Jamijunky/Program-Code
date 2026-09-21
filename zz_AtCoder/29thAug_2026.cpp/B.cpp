#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;

  vector<int> cnt(101, 0);

  for (int i = 0; i < N; i++)
  {
    int a;
    cin >> a;
    cnt[a]++;
  }

  int ans = 0;
  for (int x = 1; x <= 100; x++)
  {
    if (cnt[x] % 2 == 1)
    {
      ans += x;
    }
  }

  cout << ans << endl;

  return 0;
}
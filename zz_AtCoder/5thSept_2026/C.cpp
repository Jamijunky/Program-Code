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

    vector<long long> even, odd;
    long long total = 0;

    for (int i = 0; i < N; ++i)
    {
      long long x;
      cin >> x;
      total += x;
      if (x & 1)
        odd.push_back(x);
      else
        even.push_back(x);
    }

    sort(even.begin(), even.end(), greater<long long>());
    sort(odd.begin(), odd.end(), greater<long long>());

    long long E = (long long)even.size();
    long long O = (long long)odd.size();
    long long best = LLONG_MIN;

    if (E >= 2)
    {
      long long t = 2LL * min(E - 1, O);
      long long sumEnd = even[0] + even[1];
      best = max(best, t + sumEnd);
    }

    if (O >= 2)
    {
      long long t = 2LL * min(E, O - 1);
      long long sumEnd = odd[0] + odd[1];
      best = max(best, t + sumEnd);
    }

    if (E >= 1 && O >= 1)
    {
      long long t = 2LL * min(E, O) - 1;
      long long sumEnd = even[0] + odd[0];
      best = max(best, t + sumEnd);
    }

    long long ans = total - best / 2;
    cout << ans << '\n';
  }

  return 0;
}
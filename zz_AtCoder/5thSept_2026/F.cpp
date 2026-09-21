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
    vector<long long> C(N);
    for (auto &x : C)
      cin >> x;
    sort(C.begin(), C.end());

    long long ans = LLONG_MAX;

    for (int L = 0; L <= (N - 1) / 2; ++L)
    {
      int S = N - 1 - 2 * L;
      if (S < 0)
        continue;

      int K = N - 1 - L;

      long long sum_deg2 = 0;
      for (int i = 0; i < L; ++i)
        sum_deg2 += C[i];

      long long sum_deg1 = 0;
      for (int i = L; i <= N - 2; ++i)
        sum_deg1 += C[i];

      int start_matched = N - 2 - 2 * L + 1;
      long long sum_matched = 0;
      for (int i = start_matched; i <= N - 2; ++i)
        sum_matched += C[i];

      long long sum_singleton = sum_deg1 - sum_matched;

      long long cost = 2 * sum_singleton + sum_matched + 2 * sum_deg2;
      ans = min(ans, cost);
    }

    if (N == 2)
    {
      ans = C[0] + C[1];
    }

    cout << ans << '\n';
  }

  return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, K;
  cin >> N >> K;

  vector<int> freq(K + 1, 0);
  for (int i = 0; i < N; i++)
  {
    int a;
    cin >> a;
    freq[a]++;
  }

  int max_freq = 0;
  for (int i = 1; i <= K; i++)
  {
    max_freq = max(max_freq, freq[i]);
  }

  int ans = 0;
  for (int i = 1; i <= K; i++)
  {
    if (freq[i] >= max_freq - 1)
      ans++;
  }

  cout << ans << '\n';
  return 0;
}
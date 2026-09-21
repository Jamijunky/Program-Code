#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  long long x;
  cin >> n >> x;

  vector<long long> input(n);
  for (auto &x : input)
    cin >> x;

  unordered_map<long long, pair<int, int>> mp;

  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      long long need = x - input[i] - input[j];
      if (mp.count(need))
      {
        auto [k, l] = mp[need];
        cout << i + 1<< " " << j+1 << " " << k +1<< " " << l+1;
        return 0;
      }
    }
    for (int c = 0; c < i; c++)
    {
      mp[input[i] + input[c]] = {i, c};
    }
  }
  cout << "IMPOSSIBLE";

  return 0;
}
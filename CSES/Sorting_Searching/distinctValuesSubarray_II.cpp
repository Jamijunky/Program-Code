#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<long long> a(n);
  for (auto &x : a)
    cin >> x;

  map<long long, int> mp;

  long long count = 0;
  long long l = 0;
  long long distinct = 0;

  for (int r = 0; r < n; r++)
  {
    if (mp[a[r]] == 0)
      distinct++;

    mp[a[r]]++;

    while (distinct > k)
    {
      mp[a[l]]--;

      if (mp[a[l]] == 0)
        distinct--;

      l++;
    }

    count += r - l + 1;
  }

  cout << count;
}
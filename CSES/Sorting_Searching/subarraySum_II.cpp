#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  long long k;
  cin >> n >> k;
  vector<long long> vec(n);
  for (auto &x : vec)
    cin >> x;
  map<long long, long long> mp;
  mp[0]=1;
  long long count = 0;
  long long sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += vec[i];
    long long remaining = sum - k;
    count += mp[remaining];
    mp[sum]++;
  }
  cout << count;
  return 0;
}
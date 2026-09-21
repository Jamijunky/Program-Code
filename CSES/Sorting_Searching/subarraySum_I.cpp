#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  long long x;
  cin>>n>>x;
  vector<long long> vec(n);
  for (auto &x : vec)
    cin >> x;
  int left = 0;
  long long sum = 0;
  int count = 0;

  for (int right = 0; right < n; right++)
  {
    sum += vec[right];

    while (sum > x)
    {
      sum -= vec[left];
      left++;
    }
    if (sum == x)
    {
      count++;
    }
  }
  cout << count;

  return 0;
}
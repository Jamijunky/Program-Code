#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<long long> stickSize(n);
  long long sum = 0;
  for (auto &x : stickSize)
  {
    cin >> x;
    sum += x;
  }
sort(stickSize.begin(),stickSize.end());
  long long median = stickSize[n/2];
  long long count = 0;
  for (int i = 0; i < n; i++)
  {
    count += abs(median - stickSize[i]);
  }
  cout << count;
  return 0;
}
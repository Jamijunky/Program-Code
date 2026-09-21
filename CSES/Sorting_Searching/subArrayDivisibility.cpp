#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<long long> vec(n);
  long long count = 0;
  long long sum = 0;
  vec[0] = 1;
  for (int i = 0; i < n; i++)
  {
    long long x;
    cin >> x;
    sum = ((sum + x) % n);
    if (sum < 0)
      sum += n;
    count += vec[sum];
    vec[sum]++;
  }
  cout << count;
  return 0;
}

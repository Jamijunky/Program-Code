#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long long t;
  int n;
  cin >> n >> t;

  vector<long long> time(n);
  for (auto &x : time)
  {
    cin >> x;
  }
  long long low;
  long long high = *min_element(time.begin(), time.end()) * t;

  while (low < high)
  {
    long long products = 0;
    long long mid = low + (high - low) / 2;

    for (long long a : time)
    {
      products += mid / a;

      if (products >= t)
        break;
    }
    if (products >= t)
      high = mid;
    else
      low = mid + 1;
  }
  cout << low;
  return 0;
}
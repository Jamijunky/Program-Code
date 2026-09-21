#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<long long> coinValue(n);
  for (auto &x : coinValue)
    cin >> x;
  sort(coinValue.begin(), coinValue.end());
  long long sum = 1;

  for (int i = 0; i < n; i++)
  {
    if (coinValue[i] > sum)
      break;
    sum += coinValue[i];
  }
  cout << sum;

  return 0;
}
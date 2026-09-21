#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  long n, x;
  cin>>n>>x;
  vector<long> weights(n);
  for (auto &x : weights)
    cin >> x;

  sort(weights.begin(), weights.end());
  int i = 0, j = n-1;
  int count = 0;
  while (i <= j)
  {
    if (weights[i] + weights[j] <= x)
    {
      i++;
      j--;
      count++;
    }
    else
    {
      j--;
      count++;
    }
  }
  cout << count;
  return 0;
}
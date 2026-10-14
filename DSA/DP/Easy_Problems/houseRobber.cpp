#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cout << "Enter no of houses: ";
  cin >> n;
  vector<int> vec(n);
  cout << "Enter money in each house: ";
  for (auto &x : vec)
  {
    cin >> x;
  }
  int sum1 = 0;
  int sum2 = 0;

  for (int i = 0; i < n; i += 2)
  {
    sum1 += vec[i];
  }
  for (int i = 1; i < n; i += 2)
  {
    sum2 += vec[i];
  }

  cout << max(sum1, sum2) << endl;

  return 0;
}
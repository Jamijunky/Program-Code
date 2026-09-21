#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  int n, x;
  cin >> n >> x;
  vector<pair<long long, int>> elem;
  for (int i = 0; i < n; i++)
  {
    long long x;
    cin >> x;
    elem.push_back({x, i+1});
  }
  sort(elem.begin(), elem.end());

  int i = 0, j = n - 1;

  while (i < j)
  {
    if (elem[i].first + elem[j].first > x)
      j--;
    else if (elem[i].first + elem[j].first < x)
      i++;
    else
    {
      cout << elem[i].second << " " << elem[j].second;
      return 0;
    }
  }
  cout << "IMPOSSIBLE";

  return 0;
}
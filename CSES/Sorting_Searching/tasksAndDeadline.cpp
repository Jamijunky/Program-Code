#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<pair<int, int>> thing(n);
  for (auto &[duration, deadline] : thing)
  {
    cin >> duration >> deadline;
  }

  sort(thing.begin(), thing.end());

  long count = 0;
  long total = 0;

  for (int i = 0; i < n; i++)
  {
    count += thing[i].first;
    total += thing[i].second - count;
  }
  cout << total;
  return 0;
}
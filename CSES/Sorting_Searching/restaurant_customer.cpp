#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  cin >> n;

  vector<pair<long long, int>> events;

  for (int i = 0; i < n; i++)
  {
    int a, b;
    cin >> a >> b;
    events.push_back({a, +1});
    events.push_back({b, -1});
  }

  sort(events.begin(), events.end());
  int current = 0;
  int ans = 0;

  for (auto [time, change] : events)
  {
    current += change;
    ans = max(current, ans);
  }
  cout << ans;

  return 0;
}
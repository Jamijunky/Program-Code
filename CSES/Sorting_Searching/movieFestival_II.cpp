#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

  int n, k;
  cin >> n >> k;

  vector<pair<long long, long long>> vec(n);
  for (auto &[x, y] : vec)
  {

    cin >> x >> y;
  }
  sort(vec.begin(), vec.end(), [](auto &a, auto &b)
       {
  if(a.second!=b.second) return a.second<b.second;
  
  return a.first<b.first; });
  multiset<long long> lastEnd;
  for (int i = 0; i < k; i++)
  {
    lastEnd.insert(0);
  }
  long long count = 0;

  for (auto [start, end] : vec)
  {
    auto it = lastEnd.upper_bound(start);

    if (it != lastEnd.begin())
    {
      it--;
      lastEnd.erase(it);
      lastEnd.insert(end);
      count++;
    }
  }
  cout << count << endl;
  return 0;
}
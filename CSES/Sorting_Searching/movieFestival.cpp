#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<pair<int, int>> movies;

  for (int i = 0; i < n; i++)
  {
    long a, b;
    cin >> a >> b;
    movies.push_back({a, b});
  }

  sort(movies.begin(), movies.end(), [](auto &a, auto &b)
       { return a.second < b.second; });
  int count = 0;
  int lastEnd = 0;
  for (auto [start, end] : movies)
  {
    if (start >= lastEnd)
    {
      count++;
      lastEnd = end;
    }
  }
  cout << count;
  return 0;
}
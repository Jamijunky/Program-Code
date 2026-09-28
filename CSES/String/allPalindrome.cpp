#include <iostream>
#include <vector>

using namespace std;
// Manacher's Algorithm
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  string t = "#";
  for (auto c : s)
  {
    t += c;
    t += "#";
  }
  int n = t.size();
  vector<int> p(n);
  int center = 0, right = 0;

  for (int i = 0; i < n; i++)
  {
    int mirror = 2 * center - i;

    if (i < right)
    {
      p[i] = min(right - i, p[mirror]);
    }
    while (i - p[i] - 1 >= 0 && i + p[i] + 1 < n && t[i - p[i] - 1] == t[i + p[i] + 1])
      p[i]++;

    if (i + p[i] > right)
    {
      center = i;
      right = i + p[i];
    }
  }
  int best = 0;

  for (int r = 1; r < n; r += 2)
  {
    while (best + p[best] < r)
      best++;

    cout << r - best + 1 << ' ';
  }

  cout << '\n';
  return 0;
}
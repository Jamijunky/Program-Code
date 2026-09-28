#include <iostream>
#include <vector>

using namespace std;

// Manacher's Algorithm
// https://www.youtube.com/watch?v=V-sEwsca1ak
// https://www.youtube.com/watch?v=ei7qghJEj4Y

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
  int center = 0, right = 0, bestCenter = 0;
  for (int i = 0; i < n; i++)
  {
    int mirror = 2 * center - i;
    if (i < right)
    {
      p[i] = min(right - i, p[mirror]);
    }

    while (i - p[i] - 1 >= 0 && i + p[i] + 1 < n && t[i - p[i] - 1] == t[i + p[i] + 1])
    {
      p[i]++;
    }

    if (i + p[i] > right)
    {
      center = i;
      right = p[i] + i;
    }
    if (p[i] > p[bestCenter])
    {
      bestCenter = i;
    }
  }

  int len = p[bestCenter];
  int start = (bestCenter - len) / 2;

  cout << s.substr(start, len) << '\n';

  return 0;
}


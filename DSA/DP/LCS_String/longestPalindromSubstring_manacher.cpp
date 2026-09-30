#include <iostream>
#include <vector>

using namespace std;

string manacher(string str)
{
  string t;
  for (auto c : str)
  {
    t += "#";
    t += c;
  }
  t += "#";
  int right = 0;
  int center = 0;
  int maxCenter = 0, maxLen = 0;
  int n = t.size();
  vector<int> p(n);
  for (int i = 0; i < n; i++)
  {
    int mirror = 2 * center - i;
    if (i < right)
      p[i] = min(right - i, p[mirror]);

    while (i - p[i] - 1 >= 0 && i + p[i] + 1 < n && t[i - p[i] - 1] == t[i + p[i] + 1])
    {
      p[i]++;
    }
    if (i + p[i] > right)
    {
      center = i;
      right = i + p[i];
    }
    if (p[i] > maxLen)
    {
      maxLen = p[i];
      maxCenter = i;
    }
  }

  int start = (maxCenter - maxLen) / 2;

  return str.substr(start, maxLen);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string str;
  cout << "Enter the string: ";
  cin >> str;
  int n = str.size();
  cout << manacher(str);
  return 0;
}
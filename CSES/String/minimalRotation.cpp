#include <iostream>
#include <vector>

using namespace std;

// Booth's Algorithm

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int n = s.size();
  int i = 0, j = 1, k = 0;
  while (i < n && j < n && k < n)
  {
    char a = s[(i + k) % n];
    char b = s[(j + k) % n];
    if (a == b)
      k++;

    else if (a > b)
    {
      i += k + 1;
      if (i == j)
        i++;

      k = 0;
    }
    else
    {
      j += k + 1;
      if (i == j)
        j++;

      k = 0;
    }
  }
  int start = min(i, j);
  for (int idx = 0; idx < n; idx++)
  {
    cout << s[(idx + start) % n];
  }
  cout << endl;
  return 0;
}
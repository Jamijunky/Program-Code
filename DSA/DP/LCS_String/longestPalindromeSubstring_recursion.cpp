#include <iostream>
#include <vector>

using namespace std;
bool checkPal(string str, int low, int high)
{
  while (low <= high)
  {
    if (str[low] != str[high])
      return false;
    low++;
    high--;
  }
  return true;
}

string solve(string str, int n)
{
  int maxLen = 1;
  int start = 0;

  for (int i = 0; i < n; i++)
  {
    for (int j = i; j < n; j++)
    {
      if (checkPal(str, i, j) && (j - i + 1) > maxLen)
      {
        start = i;
        maxLen = j - i + 1;
      }
    }
  }
  return str.substr(start, maxLen);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string str;
  cout << "enter a string: ";
  cin >> str;
  int n = str.size();
  cout << solve(str, n);
  return 0;
}
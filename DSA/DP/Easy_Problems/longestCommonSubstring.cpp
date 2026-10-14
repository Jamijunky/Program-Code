#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int longCommSubstr(string s1, string s2)
{
  int m = s1.size();
  int n = s2.size();

  vector<int> prev(n + 1, 0);

  int res = 0;
  for (int i = 1; i <= m; i++)
  {
    vector<int> curr(n + 1, 0);
    for (int j = 1; j <= n; j++)
    {
      if (s1[i - 1] == s2[j - 1])
      {
        curr[j] = prev[j - 1] + 1;
        res = max(res, curr[j]);
      }
      else
      {
        curr[j] = 0;
      }
    }
    prev = curr;
  }

  return res;
}

int main()
{
  string s1 = "GeeksforGeeks";
  string s2 = "GeeksQuiz";
  cout << longCommSubstr(s1, s2) << endl;

  return 0;
}
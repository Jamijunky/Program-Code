#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lcsThree(string s1, string s2, string s3, int m, int n, int p)
{
  if (m == 0 || n == 0 || p == 0)
    return 0;

  if (s1[m - 1] == s2[n - 1] && s2[n - 1] == s3[p - 1])

    return 1 + lcsThree(s1, s2, s3, m - 1, n - 1, p - 1);
  else
    return max({lcsThree(s1, s2, s3, m - 1, n, p), lcsThree(s1, s2, s3, m, n, p - 1), lcsThree(s1, s2, s3, m, n - 1, p)});
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s1, s2, s3;
  cout << "Enter three strings\n";
  cout << "Enter string 1: " << endl;
  cin >> s1;
  cout << "Enter string 2: " << endl;
  cin >> s2;
  cout << "Enter string 3: " << endl;
  cin >> s3;
  int m = s1.size();
  int n = s2.size();
  int p = s3.size();
  cout << lcsThree(s1, s2, s3, m, n, p);
  return 0;
}
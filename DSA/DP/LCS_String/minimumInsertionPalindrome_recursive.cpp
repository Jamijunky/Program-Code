#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int solve(string str, int low, int high)
{

  if (low >= high)
    return 0;

  if (str[low] == str[high])
    return solve(str, low + 1, high - 1);
  else
    return 1 + min({solve(str, low, high - 1), solve(str, low + 1, high)});
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string str;
  cout << "Enter the string: ";
  cin >> str;
  int n = str.size();
  cout << solve(str, 0, n - 1);

  return 0;
}
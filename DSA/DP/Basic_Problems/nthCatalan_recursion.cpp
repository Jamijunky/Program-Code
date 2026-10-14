#include <iostream>
#include <vector>

using namespace std;

int solve(int n)
{

  if(n<=1) return 1;
  int res = 0;
  for (int i = 0; i < n; i++)
  {
    res += solve(i) * solve(n - i - 1);
  }
  return res;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cout << "Enter a number: ";
  cin >> n;
  cout << solve(n);
  return 0;
}
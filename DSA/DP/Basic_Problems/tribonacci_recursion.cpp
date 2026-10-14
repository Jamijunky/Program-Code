#include <iostream>

using namespace std;

int solve(int n)
{
  if (n == 0 || n == 1 || n == 2)
    return 0;
  if (n == 3)
    return 1;
  else
    return (solve(n - 1) + solve(n - 2) + solve(n - 3));
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cout << "Enter a number: ";
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cout << solve(i+1) << " ";
  }
  return 0;
}
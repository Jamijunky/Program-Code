#include <iostream>

using namespace std;

int solve(int n)
{
  if (n == 0 || n == 1)
    return 1;

  return solve(n - 1) + solve(n - 2);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cout << "Enter the number: ";
  cin >> n;
  cout << solve(n);
  return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int solve(int n)
{

  vector<int> screen(n + 1);

  for (int i = 1; i <= 6; i++)
  {
    screen[i - 1] = i;
  }

  for (int i = 7; i <= n; i++)
  {
    screen[i - 1] = max({2 * screen[i - 4], 3 * screen[i - 5], 4 * screen[i - 6]});
  }
return screen[n-1];
}

int main()
{

  int n;
  cin >> n;

  cout << solve(n);

  return 0;
}
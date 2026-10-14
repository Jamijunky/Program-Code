#include <iostream>
#include <vector>

using namespace std;

int solve(int n, int x, int y, int z, vector<int> &dp)
{

  if (n == 0)
    return 0;
  if (n < 0)
    return -1;

  if (dp[n] != -1)
    return dp[n];

  int xmax = solve(n - x, x, y, z, dp);
  int ymax = solve(n - y, x, y, z, dp);
  int zmax = solve(n - z, x, y, z, dp);

  int maxi = max({xmax, ymax, zmax});

  if (maxi == -1)
    return -1;

  return maxi + 1;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cout << "Enter the line segement: ";
  cin >> n;
  int x, y, z;
  cout << "Enter the 3 segment cuts: ";
  cin >> x >> y >> z;
  vector<int> dp(n + 1, -1);
  int res = solve(n, x, y, z, dp);
  if (res == -1)
    return 0;
  cout << res << endl;
  return 0;
}
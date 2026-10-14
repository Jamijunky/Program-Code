#include <iostream>
#include <vector>

using namespace std;

int solve(int n, int x, int y, int z)
{

  if (n == 0)
    return 0;
  if (n < 0)
    return -1;

  int xmax = solve(n - x, x, y, z);
  int ymax = solve(n - y, x, y, z);
  int zmax = solve(n - z, x, y, z);

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
  int res = solve(n, x, y, z);
  if (res == -1)
    return 0;
  cout << res << endl;

  return 0;
}
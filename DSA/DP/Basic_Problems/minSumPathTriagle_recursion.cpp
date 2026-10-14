#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minSumPath(vector<vector<int>> &triangle, int i, int j)
{

  if (i == triangle.size())
    return 0;

  return triangle[i][j] + min(minSumPath(triangle, i + 1, j), minSumPath(triangle, i + 1, j + 1));
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<vector<int>> triangle = {
      {2},
      {3, 9},
      {1, 6, 7}};

  cout << minSumPath(triangle, 0, 0);
  return 0;
}
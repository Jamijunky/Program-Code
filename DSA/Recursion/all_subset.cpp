#include <iostream>
#include <vector>

using namespace std;

void solve(vector<int> &arr, int idx, vector<int> &temp, vector<vector<int>> &val)
{
  if (idx == arr.size())
  {
    val.push_back(temp);
    return;
  }

  temp.push_back(arr[idx]);
  solve(arr, idx + 1, temp, val);
  temp.pop_back();
  solve(arr, idx + 1, temp, val);
}

vector<vector<int>> subset(vector<int> &arr)
{
  vector<int> temp;
  vector<vector<int>> val;
  solve(arr, 0, temp, val);
  return val;
}

int main()
{
  vector<int> arr = {2, 4, 5};
  int idx = 0;
  vector<vector<int>> result = subset(arr);

  for (auto v : result)
  {
    cout << "[ ";
    for (int x : v)
      cout << x << " ";
    cout << "] , ";
  }
  return 0;
}

// TC : O(n * 2^n)
// SC : O(n * 2^n)
// AC : O(n)
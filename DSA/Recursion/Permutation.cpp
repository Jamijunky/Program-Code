
#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> &arr, int idx, vector<vector<int>> &ans)
{
  if (idx == arr.size())
  {
    ans.push_back(arr);
    return;
  }

  for (int i = idx; i < arr.size(); i++)
  {
    swap(arr[idx], arr[i]);
    solve(arr, idx + 1, ans);
    swap(arr[idx], arr[i]);
  }
}

vector<vector<int>> permut(vector<int> arr)
{
  vector<vector<int>> ans;
  solve(arr, 0, ans);
  return ans;
}


int main()
{
  vector<int> v = {1, 9, 4};
  vector<vector<int>> ans = permut(v);

  for (auto first : ans)
  {
    cout<< "[ ";
    for (auto val : first)
    {
      cout << val << " ";
    }
    cout << "]"<<"\n";
  }
  return 0;
}


// TC : O(n * n!)
// SC : O(n * n!)
// AC : O(n)
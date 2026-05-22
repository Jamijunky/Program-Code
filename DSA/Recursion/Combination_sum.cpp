#include <iostream>
#include <vector>
using namespace std;

void solve(int idx, int sum, vector<int> &input, int target, vector<vector<int>> &ans, vector<int> &combinations)
{

  if (sum == target)
  {
    ans.push_back(combinations);
    return;
  }
  for (int i = idx; i < input.size(); i++)
  {

    combinations.push_back(input[i]);
    if (sum <= target)
      solve(i, sum + input[i], input, target, ans, combinations);
    combinations.pop_back();
  }
}

vector<vector<int>> combiSum(vector<int> &input, int target)
{
  vector<vector<int>> ans;
  vector<int> combinations;
  int sum = 0;
  int idx = 0;
  solve(idx, sum, input, target, ans, combinations);
  return ans;
}
int main()
{
  vector<int> input = {1, 2, 3};
  int target = 4;
  vector<vector<int>> result = combiSum(input, target);
  for (auto row : result)
  {
    cout << "[";

    for (auto val : row)
    {
      cout << val << ",";
    }
    cout
        << "]\n";
  }
  return 0;
}
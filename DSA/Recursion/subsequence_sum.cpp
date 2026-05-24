#include <iostream>
#include <vector>
using namespace std;
void solve(int sum, int idx, vector<int> &input, int target, vector<vector<int>> &result, vector<int> &temp)
{
  if (idx == input.size())
  {
    if (sum == target)
    {
      result.push_back(temp);
    }
    return;
  }
  temp.push_back(input[idx]);
  solve(sum + input[idx], idx + 1, input, target, result, temp);
  temp.pop_back();
  solve(sum, idx + 1, input, target, result, temp);
}

vector<vector<int>> subsequence_sum(vector<int> input, int target)
{
  vector<vector<int>> result;
  vector<int> temp;
  solve(0, 0, input, target, result, temp);
  return result;
}

int main()
{
  vector<int> input = {1, 2, 3, 4};
  int target = 7;
  vector<vector<int>> result = subsequence_sum(input, target);
  for (auto row : result)
  {
    for (auto val : row)
      cout << val << " ";
    cout << "\n";
  }
  return 0;
}
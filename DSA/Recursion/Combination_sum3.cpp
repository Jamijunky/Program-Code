#include <iostream>
#include <vector>
using namespace std;

void solve(int val, int k, int target, vector<int> &temp, vector<vector<int>> &result)
{
  if (k == 0 && target == 0)
  {
    result.push_back(temp);
    return;
  }
  if (val == 10 || k == 0 || target < 0)
  {
    return;
  }

  temp.push_back(val);
  solve(val + 1, k - 1, target - val, temp, result);
  temp.pop_back();
  solve(val + 1, k, target, temp, result);
}

vector<vector<int>> combiSum3(int k, int target)
{
  int minSum = k * (k + 1) / 2;
  int maxSum = k * (19 - k) / 2;

  if (target < minSum || target > maxSum)
    return {};
  vector<int> temp;
  vector<vector<int>> result;
  solve(1, k, target, temp, result);
  return result;
}

int main()
{
  int k;
  cout << "No of possible numbers : ";
  cin >> k;
  int target;
  cout << "Enter target number : ";
  cin >> target;
  if (target == 0)
    cout << "You entered zero as target dumbo\n";
  vector<vector<int>> result = combiSum3(k, target);
  if (result.empty())
    cout << "No combination possible\n";
  for (auto &row : result)
  {
    for (auto val : row)
    {
      cout << val << " ";
    }
    cout << "\n";
  }

  return 0;
}
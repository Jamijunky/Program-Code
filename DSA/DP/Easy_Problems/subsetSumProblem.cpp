#include <iostream>
#include <vector>

using namespace std;

bool isSubsetSum(vector<int> &arr, int sum, int n)
{

  if (sum == 0)
    return true;
  if (n == 0)
    return false;
  if (arr[n - 1] > sum)
  {
    isSubsetSum(arr, sum, n - 1);
  }
  return isSubsetSum(arr, sum - arr[n], n - 1) || isSubsetSum(arr, sum, n - 1);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> arr = {3, 34, 4, 12, 5, 2};
  int sum = 9;

  if (isSubsetSum(arr, sum, arr.size()))
    cout << "True" << endl;
  else
    cout << "False" << endl;

  return 0;
  return 0;
}
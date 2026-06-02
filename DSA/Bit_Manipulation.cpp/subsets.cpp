#include <iostream>

#include <vector>

using namespace std;

int main()
{
  cout << "Enter the set(enter non-numeric to not take input anymore) : ";
  vector<int> input;
  int x;
  while (cin >> x)
  {
    input.push_back(x);
  }
  int noOfSubsets = 1 << input.size();
  vector<vector<int>> result;
  for (int i = 0; i < noOfSubsets; i++)
  {
    vector<int> temp;
    for (int j = 0; j < input.size(); j++)
    {
      if (i & (1<<j))
        temp.push_back(input[j]);
    }
    result.push_back(temp);
  }
  cout << "Output\n";
  for (auto row : result)
  {
    for (auto val : row)
    {
      cout << val << " ";
    }
    cout << "\n";
  }

  return 0;
}
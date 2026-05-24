#include <iostream>
#include <vector>
using namespace std;

bool ispalindrome(string input, int l, int r)
{
  while (l < r)
  {
    if (input[l] != input[r])
      return false;
    l++;
    r--;
  }
  return true;
}

void solve(int idx, string input, vector<vector<string>> &result, vector<string> &temp)
{
  if (idx == input.size())
  {
    result.push_back(temp);
    return;
  }

  for (int i = idx;i < input.size(); i++)
  {
    if (ispalindrome(input, idx, i))
    {
      temp.push_back(input.substr(idx, i - idx + 1));
      solve(i + 1, input, result, temp);
      temp.pop_back();
    }
  }
}

vector<vector<string>> palindrome_partitioning(string input)
{
  vector < vector<string>> result;
  vector<string> temp;
  solve(0, input, result, temp);
  return result;
}

int main()
{
  string input;
  cout << "Enter a string : ";
  cin >> input;
  vector < vector<string>> result = palindrome_partitioning(input);
  if (result.empty())
    cout << "Not possible\n";
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
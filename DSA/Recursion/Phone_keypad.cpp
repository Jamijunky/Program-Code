#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void solve(int idx, string input, vector<string> &ans, string &possible, unordered_map<char, string> &combi)
{
  if (idx == input.length())
  {
    ans.push_back(possible);
    return;
  }
  int num = (int)input[idx];
  string val = combi[num];
  for (int i = 0; i < val.size(); i++)
  {
    possible += val[i];
    solve(idx + 1, input, ans, possible, combi);
    possible.pop_back();
  }
}

vector<string> phone_keypad(string input)
{
  vector<string> ans;
  unordered_map<char, string> combi = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
  string possible;
  solve(0, input, ans, possible, combi);
  return ans;
}

int main()
{
  string input;
  cout << "Enter the number : ";
  cin >> input;
  vector<string> result = phone_keypad(input);
  for(auto val:result){
    cout<<val<<" ";
  }

  return 0;
}
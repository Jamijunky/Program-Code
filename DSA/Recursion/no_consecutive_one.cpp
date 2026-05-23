#include <iostream>
#include <vector>
using namespace std;

void solve(int idx, int flip, int n, vector<string> &result, string temp)
{
  if (idx == n)
  {
    result.push_back(temp);
    return;
  }
  solve(idx + 1, 0, n, result, temp+'0');
  if (!flip)
    solve(idx + 1, 1, n, result, temp+'1');
  
}

vector<string> noConsecutive(int n)
{
  vector<string> result;
  string temp;
  solve(0, 0, n, result, temp);
  return result;
}
int main()
{
  int n;
  cout << "Enter the number : ";
  cin >> n;
  vector<string> result = noConsecutive(n);
  for(auto val:result){
    cout<<val<<" ";
  }

  return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<long long> input(n);
  for (auto &x:input)
  {
    cin >> x;
  }
  long long num = 0;
  long long moves = 0;
  for (int i = 0; i < n; i++)
  {
    if (num < input[i])
    {
      num = input[i];
    }
    moves = moves + (num - input[i]);
  }
  cout<<moves;
  return 0;
}
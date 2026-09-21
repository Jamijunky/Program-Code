#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<long long> inputs(n);
  for (auto &x : inputs)
  {
    cin >> x;
  }
  long long sum = 0;
  long long answer = LLONG_MIN;
  int j = 0;
  while (j < n)
  {
   
    sum =max(inputs[j]+sum,inputs[j]);
    answer = max(sum, answer);
    j++;
  }
  cout << answer;
  return 0;
}
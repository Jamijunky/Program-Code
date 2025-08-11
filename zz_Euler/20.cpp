#include <iostream>
#include <vector>
using namespace std;
int main()
{
  vector<int> result = {1};
  for (int i = 1; i <= 100; i++)
  {
    int carry = 0;
    for (int j = 0; j < result.size(); j++)
    {
      int product = result[j] * i +carry;
      result[j] = product %10;
      carry = product / 10;
    }
    while (carry)
    {
      result.push_back(carry % 10);
      carry /= 10;
    }
  }
  int sum = 0;
  for (int num : result)
  {
    sum += num;
  }
  cout << sum;
  return 0;
}
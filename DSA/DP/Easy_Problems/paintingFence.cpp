#include <iostream>
#include <vector>
using namespace std;

int countWays(int n, int k)
{

  if (n == 1)
    return k;
  if (n == 2)
    return k * k;

  int prev1 = k;
  int prev2 = k * k;
  for (int i = 2; i < n; i++)
  {
    int curr = prev1*(k-1) + prev2*(k-1);

    prev1 = prev2;
    prev2 = curr;
  }
  return prev2;
}

int main()
{

  int n = 3, k = 2;
  cout << countWays(n, k) << endl;

  return 0;
}
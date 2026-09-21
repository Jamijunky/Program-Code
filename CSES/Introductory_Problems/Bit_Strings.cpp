#include <iostream>
#include <cmath>

#define MOD 1000000007

using namespace std;

long long power(long long a, long long b)
{
  long long result = 1;
  while (b > 0)
  {
    if (b % 2 == 1)
      result = result * a % MOD;
    a = a * a % MOD;
    b /= 2;
  }
  return result;
}

int main()
{
  int n;
  cin >> n;
  cout << power(2, n);
  return 0;
}
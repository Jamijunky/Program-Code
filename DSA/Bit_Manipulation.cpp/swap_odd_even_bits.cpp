#include <iostream>

#include <vector>

using namespace std;

int main()
{
  int n = 23;
  int oddbit = n & 0xAAAAAAAA;
  int evenbit = n & 0x55555555;
  int leftshift = evenbit << 1;
  int rightshift = oddbit >> 1;
  int ans = leftshift | rightshift;
  cout << ans;
  return 0;
}
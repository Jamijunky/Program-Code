#include <iostream>

#include <vector>

using namespace std;

int main()
{
  vector<int> input = {2, 2, 3, 4, 4, 5, 7,7};
  int xorr = 0;
  for (auto val : input)
    xorr ^= val;
  int rightmost = (xorr & xorr - 1) ^ xorr;
  int first = 0, second = 0;
  for (int i = 0; i < input.size(); i++)
  {
    if (input[i] & rightmost)
      first ^= input[i];
    else
      second ^= input[i];
  }
  cout << first << ":" << second << "\n";
  return 0;
}

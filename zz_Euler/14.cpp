#include <iostream>
using namespace std;
int main()
{
  int maxCount = 0;
  int num = 0;
  for (long long int i = 2; i < 1000000; i++)
  {
    int count = 0;
    long long int n = i;
    while (n > 1)
    {
      if (n % 2 == 0)
      {
        n /= 2;
      }
      else
      {
        n = 3 * n + 1;
      }
      count++;
    }
    if (count > maxCount)
    {
      num = i;
      maxCount=count;
    }
  }
  cout<<num;
  return 0;
}
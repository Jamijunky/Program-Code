#include <iostream>
using namespace std;
int main()
{
  long int sum = 10;
   cout<<"jejej";
  bool re = true;
  for (long int i = 6; i < 2000000; i++)
  {
    re = true;
    long int num = i;
    for (int j = 2; j < i; j++)
    {
      if (num % j == 0)
      {
        re = false;
        break;
      }
    }
    if (re)
      sum += num;
  }
  cout << sum;
  return 0;
}
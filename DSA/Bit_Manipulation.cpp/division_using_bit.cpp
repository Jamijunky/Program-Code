#include <iostream>

#include <vector>

using namespace std;

int main()
{
  int divisor;
  cout << "Enter divisor : ";
  cin >> divisor;
  int dividend;
  cout << "Enter dividend : ";
  cin >> dividend;
  int quotient = 0;
  while (dividend >= divisor)
  {
    int count = 0;
    while (dividend >= (divisor << (count + 1)))
    {
      count++;
    }
    quotient += 1 << count;
    dividend -= (divisor << count);
  }
  int remainder =dividend;
  cout << "quotient : "<< quotient << "\n" << "remainder : " <<remainder << "\n";
  return 0;
}
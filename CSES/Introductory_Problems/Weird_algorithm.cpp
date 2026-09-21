#include <iostream>
using namespace std;

int main()
{
  long long n;
  cin >> n;

  if (n < 1)
  {
    cout << "Enter a positive number\n";
    return 0;
  }

  if (n == 1)
  {
    cout << "1";
    return 0;
  }

  cout << n << " ";

  while (n != 1)
  {
    if (n % 2 == 0)
    {
      n = n / 2;
    }
    else
    {
      n = n * 3 + 1;
    }

    cout << n << " ";
  }

  return 0;
}
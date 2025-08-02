#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
int main()
{
  int count = 0;
  cout << "lhsdf";
  for (long int i = 1; i < LONG_MAX; i++)
  { count =0;
    long long int num = (i * (i + 1)) / 2;
       for (long long j = 1; j * j <= num; j++) {
            if (num % j == 0) {
                if (j * j == num)
                    count += 1; // perfect square
                else
                    count += 2; // both j and num/j
            }
        }
    if (count > 500)
    {
      cout << num;
      exit (0);
    }
  }
  return 0;
}
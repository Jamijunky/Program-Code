#include <iostream>
#include <vector>

using namespace std;

int main()
{

  int n;
  cin >> n;

  for (long i = 1; i <= n; i++)
  {
    long long result = 0;
    long long total = ((i * i) * (i * i - 1)) / 2;
    long long sub = 4 * (i - 1) * (i - 2);
    result = total - sub;
    cout << result << endl;
  }

  return 0;
}
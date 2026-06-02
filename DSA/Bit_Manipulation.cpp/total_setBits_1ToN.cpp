#include <iostream>

#include <vector>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cout << "Enter the number : ";
  cin >> n;

  long long count = 0;
  for (int i = 1; i < n + 1; i++)
  {
   int j=i;
    while (j > 0)
    {
      j=j&(j-1);
      count++;
    }
  }

  cout << count<< "\n";

  return 0;
}
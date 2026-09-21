#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  string n;
  cin >> n;
  char c = n[0];
  int count = 1;
  int maximum=1;
  for (int i = 1; i < n.size(); i++)
  {
    if (c == n[i])
      count++;
    else
    {
      maximum = max(count, maximum);
      count = 1;
    }
      maximum = max(count, maximum);
    c=n[i];
  }
  cout<<maximum;
  return 0;
}
#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
  int n;
  cin >> n;
  unordered_set<long> s;

  for (int i = 0; i < n; i++)
  {
    long x;
    cin >> x;
    s.emplace(x);
  }
  cout << s.size();
  return 0;
}
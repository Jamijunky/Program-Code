#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
  int n;
  cin >> n;
  int cal = n % 4;
  bool pos;
  if (n == 1 || n == 2)
  {
    cout << "NO\n";
    return 0;
  }
  if (cal == 1 || cal == 2)
  {
    cout << "NO\n";
    return 0;
  }

  cout << "YES\n";
  set<int> set1;
  set<int> set2;
  if (cal == 0)
  {
    for (int i = 1; i <= n; i += 4)
    {
      set1.emplace(i);
      set1.emplace(i + 3);
      set2.emplace(i + 1);
      set2.emplace(i + 2);
    }
  }
  if (cal == 3)
  {
    set1.emplace(1);
    set1.emplace(2);
    set2.emplace(3);
    for (int i = 4; i <= n; i += 4)
    {
      set1.emplace(i);
      set1.emplace(i + 3);
      set2.emplace(i + 1);
      set2.emplace(i + 2);
    }
  }
  cout << set1.size() << endl;
  for (int x : set1)
    cout << x << " ";

  cout << endl
       << set2.size() << endl;
  for (int x : set2)
    cout << x << " ";
  return 0;
}

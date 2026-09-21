#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  multiset<long> ticket;
  for (int i = 0; i < n; i++)
  {
    long x;
    cin >> x;
    ticket.insert(x);
  }
  for (int i = 0; i < m; i++)
  {
    long x;
    cin >> x;
    auto it = ticket.upper_bound(x);
    if (it == ticket.begin())
    {
      cout << -1 << endl;
      continue;
    }
  
  it--;
  cout << *it << endl;
  ticket.erase(it);

}
return 0;
}
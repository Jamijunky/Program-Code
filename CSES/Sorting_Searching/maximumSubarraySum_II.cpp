#include <iostream>
#include <climits>
#include <vector>
#include <set>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, a, b;
  cin >> n >> a >> b;
  vector<long long> pref(n + 1);
  for (int i = 1; i <= n; i++)
  {
    long long x;
    cin >> x;
    pref[i] = pref[i - 1] + x;
  }
  multiset<long long> s;
  long long ans = LLONG_MIN;

  for (int i = a; i <= n; i++)
  {
    s.insert(pref[i - a]);

    if ((i - b - 1) >= 0)
      s.erase(s.find(pref[i - b - 1])); // we used find because s.erase(something) will erase all occurence of that something so had to find first one and then delete that.
    ans = max(ans, pref[i] - *s.begin());
  }
  cout << ans << endl;
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int x, n;
  cin >> x >> n;

  set<int> lights;
  priority_queue<int> gaps;
  map<int, int> freq;

  lights.insert(0);
  lights.insert(x);

  gaps.push(x);
  freq[x]++;

  for (int i = 0; i < n; i++)
  {
    int p;
    cin >> p;

    auto right = lights.upper_bound(p);
    auto left = prev(right);

    int oldGap = *right - *left;

    freq[oldGap]--;

    int leftGap = p - *left;
    int rightGap = *right - p;

    gaps.push(leftGap);
    gaps.push(rightGap);

    freq[leftGap]++;
    freq[rightGap]++;

    lights.insert(p);

    while (freq[gaps.top()] == 0)
      gaps.pop();

    cout << gaps.top() << ' ';
  }

  return 0;
}
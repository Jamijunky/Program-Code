#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<long long> songs(n);

  for (auto &x : songs)
    cin >> x;

  set<long long> seen;
  int answer = 0;
  int left = 0;

  for (int right = 0; right < n; right++)
  {
    while (seen.count(songs[right]))
    {
      seen.erase(songs[left]);
      left++;
    }

    seen.insert(songs[right]);

    answer = max(answer, right - left + 1);
  }

  cout << answer;
  return 0;
}
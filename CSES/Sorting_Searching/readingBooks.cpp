#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<long long> books(n);
  long long sum = 0;
  for (auto &x : books)
  {
    cin >> x;
    sum += x;
  }

  long long largest = *max_element(books.begin(), books.end());
  long long answer = max(2 * largest, sum);
  cout << answer;
  return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int solve(int n, vector<int> vec, vector<int> &memo)
{
  if (n == 0 || n == 1)
    return vec[n];
  if (memo[n] != -1)
    return memo[n];
  return memo[n] = vec[n] + min({solve(n - 1, vec, memo), solve(n - 2, vec, memo)});
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cout << "Enter no of stairs: ";
  cin >> n;
  vector<int> vec(n);
  cout << "Enter weight of each stairs: ";
  for (auto &x : vec)
    cin >> x;
  if (n == 1)
    return vec[0];
  vector<int> memo(n + 1, -1);
  cout << min(solve(n - 1, vec, memo), solve(n - 2, vec, memo));
  return 0;
}
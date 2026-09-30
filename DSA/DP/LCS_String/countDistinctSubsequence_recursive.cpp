#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;
int const MOD = 1e9 + 7;
void solve(int idx, string str, int n, string curr, unordered_set<string> &s)
{
  if (idx == n)
  {
    s.emplace(curr);
    return;
  }

  solve(idx + 1, str, n, curr, s);
  curr.push_back(str[idx]);
  solve(idx + 1, str, n, curr, s);
  curr.pop_back();
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string str;
  cout << "Enter the string: ";
  cin >> str;
  int n = str.size();
  unordered_set<string> s;
  solve(0, str, n, "", s);
  cout << s.size() % MOD;
  return 0;
}
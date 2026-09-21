#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string str;
  cin >> str;
  vector<string> result;
  sort(str.begin(), str.end());

  do
  {
    result.push_back(str);
  } while (next_permutation(str.begin(), str.end()));
  cout << result.size() << endl;
  for (auto &x : result)
  {
    cout << x << endl;
  }
  return 0;
}

// without permutation function

// #include <bits/stdc++.h>
// using namespace std;

// void solve(string &s, int idx) {
//     if (idx == s.size()) {
//         cout << s << '\n';
//         return;
//     }

//     for (int i = idx; i < s.size(); i++) {
//         swap(s[idx], s[i]);
//         solve(s, idx + 1);
//         swap(s[idx], s[i]);
//     }
// }

// int main() {
//     string s;
//     cin >> s;

//     solve(s, 0);
// }
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
int t;
cin>>t;
while(t--){
  long long n;
  cin >> n;

  string str = to_string(n);
  string ans = str.substr(0);
  for (int i = 1; i < n; i++)
  {
    string val = str.substr(0, i) + str.substr(i + 1);

    if (stoll(ans) > stoll(val))
    {
      ans = val;
    }
  }
  cout << stoll(ans) << endl;
}
  return 0;
}
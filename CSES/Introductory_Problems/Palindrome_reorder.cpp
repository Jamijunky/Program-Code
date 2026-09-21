#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
  string str;
  cin >> str;
  int n = str.size();
  unordered_map<char, int> freq;
  for (int i = 0; i < n; i++)
  {
    freq[str[i]]++;
  }
  string result = "";
  char temp;
  int count = 0;
  for (auto x : freq)
  {
    if (x.second % 2 != 0)
    {
      temp = x.first;
      count++;
    }
    if (count > 1)
    {
      cout << "NO SOLUTION\n";
      return 0;
    };
    x.second /= 2;
    while (x.second > 0)
    {
      result += x.first;
      x.second--;
    }
  }
  string right = result;
  reverse(right.begin(), right.end());
  if (count == 1)
    result = result + temp + right;
  else result = result + right;
  
  cout << result;

  return 0;
}
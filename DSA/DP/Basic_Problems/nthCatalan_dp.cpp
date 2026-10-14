#include <iostream>
#include <vector>

using namespace std;

int solve(int n)
{

  vector<int> catalan(n + 1);
  catalan[0] = catalan[1] = 1;
  for (int i = 2; i < n; i++)
  {
    catalan[i] = 0;
    for (int j = 0; j < i; j++)
    {
      catalan[i] = catalan[j] * catalan[i - j - 1];
    }
  }
  return catalan[n];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cout << "Enter a number: ";
  cin >> n;
  cout << solve(n);
  return 0;
}
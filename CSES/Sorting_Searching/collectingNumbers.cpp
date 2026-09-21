#include <iostream>
#include <vector>

using namespace std;

int main()
{

  int n;
  cin >> n;

  vector<int> inputs(n + 1);

  for (int i = 1; i <= n; i++)
  {
    int x;
    cin >> x;
    inputs[x] = i;
  }
  int round = 1;
  for (int i = 1; i <n; i++)
  {
    if (inputs[i] > inputs[i + 1])
      round++;
  }
  cout << round;
  return 0;
}
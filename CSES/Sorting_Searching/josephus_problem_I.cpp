#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
  int n;
  cin >> n;
  queue<int> qp;
  for (int i = 0; i < n; i++)
  {
    qp.push(i + 1);
  }

  while (!qp.empty())
  {
    qp.push(qp.front());
    qp.pop();

    cout << qp.front() << " ";
    qp.pop();
  }

  return 0;
}
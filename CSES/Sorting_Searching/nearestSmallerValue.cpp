#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> input(n);
  for (auto &x : input)
    cin >> x;
  stack<int> st;
  for (int i = 0; i < n; i++)
  {
    while (!st.empty() && input[st.top()] >= input[i])
      st.pop();

    if (st.empty())
    {
      cout << 0 << " ";
    }
    else
      cout << st.top() + 1 << " ";

    st.push(i);
  }
  return 0;
}
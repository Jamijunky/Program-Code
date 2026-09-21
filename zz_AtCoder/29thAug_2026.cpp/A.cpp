#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;

  vector<int> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
  }

  int sum = 0;
  for (int i = N / 2; i < N; i++)
  {
    sum += A[i];
  }

  cout << sum << endl;

  return 0;
}
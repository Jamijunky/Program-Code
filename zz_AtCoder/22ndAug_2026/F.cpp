#include <bits/stdc++.h>
using namespace std;

using i128 = __int128_t;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, Q;
  cin >> N >> Q;

  vector<long long> x(N), y(N);
  for (int i = 0; i < N; i++)
  {
    cin >> x[i] >> y[i];
  }

  int M = 2 * N;
  vector<long long> x2(M), y2(M);
  for (int i = 0; i < M; i++)
  {
    x2[i] = x[i % N];
    y2[i] = y[i % N];
  }

  vector<i128> prefCross(M, 0), prefSx(M, 0), prefSy(M, 0);

  for (int i = 0; i < M - 1; i++)
  {
    i128 cross = (i128)x2[i] * y2[i + 1] - (i128)y2[i] * x2[i + 1];
    i128 sx = ((i128)x2[i] + x2[i + 1]) * cross;
    i128 sy = ((i128)y2[i] + y2[i + 1]) * cross;

    prefCross[i + 1] = prefCross[i] + cross;
    prefSx[i + 1] = prefSx[i] + sx;
    prefSy[i + 1] = prefSy[i] + sy;
  }

  cout << fixed << setprecision(15);

  while (Q--)
  {
    int u, v;
    cin >> u >> v;
    u--;
    v--;

    int L = (v - u + N) % N;
    int end = u + L;

    i128 chainCross = prefCross[end] - prefCross[u];
    i128 chainSx = prefSx[end] - prefSx[u];
    i128 chainSy = prefSy[end] - prefSy[u];

    // Closing edge (v -> u)
    i128 closingCross = (i128)x2[end] * y2[u] - (i128)y2[end] * x2[u];
    i128 closingSx = ((i128)x2[end] + x2[u]) * closingCross;
    i128 closingSy = ((i128)y2[end] + y2[u]) * closingCross;

    i128 area2 = chainCross + closingCross;
    i128 sumX = chainSx + closingSx;
    i128 sumY = chainSy + closingSy;

    long double cx = (long double)sumX / (3.0L * (long double)area2);
    long double cy = (long double)sumY / (3.0L * (long double)area2);

    cout << cx << ' ' << cy << '\n';
  }

  return 0;
}
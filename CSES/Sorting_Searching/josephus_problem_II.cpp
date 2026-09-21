#include <iostream>

#include <vector>

using namespace std;

class fenwick
{
  int n;
  vector<long> bits;

public:
  fenwick(int n)
  {
    this->n = n;
    bits.resize(n + 1);
  }

  void update(int pos, int val)
  {

    while (pos <= n)
    {
      bits[pos] += val;
      pos += (pos & -pos);
    }
  }

  int query(int pos)
  {
    int sum = 0;
    while (pos > 0)
    {
      sum += bits[pos];
      pos -= (pos & -pos);
    }
    return sum;
  }

  int kth(int k)
  {
    int pos = 0;
    int jump = 1;
    while (jump * 2 <= n)
    {
      jump *= 2;
    }

    while (jump > 0)
    {
      int next = pos + jump;

      if (next <= n && bits[next] <= k)
      {
        pos = next;
        k -= bits[next];
      }

      jump /= 2;
    }
    return pos + 1;
  }
};

main()
{
  int n;
  long long k;
  cin >> n >> k;

  fenwick fw(n);
  for (int i = 0; i < n; i++)
  {
    fw.update(i + 1, 1);
  }

  long long current = 0;
  for (int remaining = n; remaining > 0; remaining--)
  {
    current = (current + k) % remaining;

    int pos = fw.kth(current + 1);

    cout << pos-1 << " ";
    fw.update(pos, -1);
  }

  return 0;
}
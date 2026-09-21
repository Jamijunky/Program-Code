#include <iostream>
#include <algorithm>

#include <vector>

using namespace std;

int main()
{
  long n, m;
  long k;
  cin >> n >> m >> k;
  vector<long> desiredSize(n);
  vector<long> apartmentSize(m);
  for (auto &x : desiredSize)
    cin >> x;
  for (auto &x : apartmentSize)
    cin >> x;

  sort(desiredSize.begin(), desiredSize.end());
  sort(apartmentSize.begin(), apartmentSize.end());
  long count = 0;
  long i = 0;
  long j = 0;
  while (n > i && m > j)
  {
    long de = desiredSize[i];
    long apar = apartmentSize[j];
    if ((de - k) > apar)
      j++;
    else if ((de + k) < apar)
      i++;
    else
    {
      j++;
      i++;
      count++;
    }
  }
  cout << count;
  return 0;
}
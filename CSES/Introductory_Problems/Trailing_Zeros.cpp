#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  long long n;
  cin >> n;
  long long zeros=0;

  while(n>0){
    n/=5;
    zeros+=n;
  }
  
  cout<<zeros;
  return 0;
}
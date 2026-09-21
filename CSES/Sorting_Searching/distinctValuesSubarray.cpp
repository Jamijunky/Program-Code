#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
  int n;
  cin>>n;
  vector<long long> input(n);
  for(auto &x: input) cin>>x;
  unordered_map<long long,int> freq;

  int left=0;
  long count=1;
  for(int right=0;right<n;right++){
     while(freq[input[right]]==1){
      freq[left]--;
      left++;
     }
     freq[right]++;
     count+=2;
  }
  return 0;
}
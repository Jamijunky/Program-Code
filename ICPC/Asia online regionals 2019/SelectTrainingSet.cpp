#include <iostream>
#include <vector>
#include <map>

using namespace std;


int main()
{
ios::sync_with_stdio(false);
cin.tie(nullptr);

int t;
cin>>t;
while(t--){
  int n;
  cin>>n;
  map<string,pair<int,int>> mp;
  for(int i=0;i<n;i++){
    string str;
    bool val;
    cin>>str>>val;
    if(val==0) mp[str].first++;
    else mp[str].second++;
  }
    int val=0;
    for(auto &[word,cnt]:mp){
      int count=max(cnt.first,cnt.second);
      val+=count;
    }
    cout<<val<<endl;
}


  return 0;
}
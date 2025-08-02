#include <iostream>
#include <vector>
using namespace std;
int main()
{
      string num= "55373762304";
      int power=51;
   string total=num+ string(power,'0');
  vector<int> ans;
    for(char ch:total){
          ans.push_back(ch);
    }
    for(int j=0;j<10;j++){
      cout<<ans[j];
    }
 return 0;
}
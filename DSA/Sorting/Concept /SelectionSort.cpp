#include <iostream>
#include <vector>

using namespace std;
void selectionSort(vector<int>&vec){
  int i,j;
  for(i=0;i<vec.size();i++){
    int smallest=i;
    for(j=i;j<vec.size();j++){
      if(vec[j]<vec[smallest]){
          smallest=j;
      }
    }
    swap(vec[smallest],vec[i]);
  }

}
int main()
{
  vector<int> vec;
  int num;
  cout<<"Enter the Array\nInput anything except number to come out of input loop\n";
  while(cin>>num){
    vec.push_back(num);
  }
  selectionSort(vec);
  for(int num:vec){
    cout<<num<<" ";
  }
  return 0;
}
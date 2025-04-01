#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>&vec, int low, int mid, int high){
  int left=low,right=mid+1;
  vector<int> temp;
while(left<=mid && right<=high){
  if(vec[left]>=vec[right]){
    temp.push_back(vec[right]);
    right++;
  }
  else{
    temp.push_back(vec[left]);
    left++;
  }
}
while(left<=mid){
  temp.push_back(vec[left]);
  left++;
}
while(right<=high){
  temp.push_back(vec[right]);
  right++;
}
for(int i=low;i<=high;i++){
  vec[i]=temp[i-low];
  
}
  
}
void mergesort(vector<int>&vec,int low,int high){
  if(low>=high) return;
  int mid=(low+high)/2;
  mergesort(vec,low,mid);
  mergesort(vec,mid+1,high);
  merge(vec,low,mid,high);
}
int main()
{
  vector<int> vec;
  int num;
  cout<<"Enter the Array\nInput anything except number to come out of input loop\n";
  while(cin>>num){
    vec.push_back(num);
  }
  mergesort(vec,0,vec.size()-1);
  for(int num:vec){
    cout<<num<<" ";
  }
  return 0;
}
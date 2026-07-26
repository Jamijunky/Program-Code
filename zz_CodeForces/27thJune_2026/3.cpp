#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        vector<long long>a(n);
        long long xorAll=0;
        for(auto&x:a){scanf("%lld",&x);xorAll^=x;}
        
        if(n==1){printf("0\n");continue;}
        
        long long ans=0;
        if(xorAll==0){
            ans=1; // b=a, leaves all zeros
        } else {
            // Count j where X_j = xorAll ^ a_j < a_j
            for(int i=0;i<n;i++){
                long long Xj=xorAll^a[i];
                if(Xj<a[i]) ans++;
            }
            ans%=MOD;
        }
        printf("%lld\n",ans);
    }
}
#include <bits/stdc++.h>
#include <iostream> 
#include<vector>
using namespace std;
typedef long long ll;
const int sz=5e5+10;
const int sz1=1e6+1;
const int inf=1e9 + 7;
const int mod = 1e9 + 7;
int n,m,k,w;
long long d[sz];
long long pf[sz];
long long freq[sz];
vector<long long>seg[sz];
long long dp[sz];
struct bag{
     long long tal,wt; 
}a[sz];
bool go(int val){ 
     for(int i = 1; i <= w; i++) dp[i] = -inf;
     dp[0] = 0;
     for(int i = 1; i <= n; i++){
         long long value = (1ll)*1000*a[i].tal - (1ll)*val*a[i].wt;
         for(int k = w ; k >=0 ; k--){
             int kto = min(w,(int)( k + a[i].wt));
             if(dp[k] != - inf){
                  if(dp[kto] < dp[k] + value){
                      dp[kto] = dp[k] + value;
                  }
             }
         }
     }
     return (dp[w] >= 0); 
}
int main(){
       cin>>n>>w;
       for(int i = 1; i <= n; i++){
             cin>>a[i].wt>>a[i].tal;
       }
       long long lo = 0;
       long long hi = 1e9 + 7; 
       while(lo < hi){
            int mid = ( hi - lo + 1)/2 + lo;
            if(go(mid)) lo = mid;
            else hi = mid - 1;
       }
       cout<<lo<<endl;
}

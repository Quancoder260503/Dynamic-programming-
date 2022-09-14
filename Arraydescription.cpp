#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const int k=1e9+7;
int main(){
    ll n,m;
    cin>>n>>m;
    ll a[1000001];
    ll dp[n+1][105];
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<105;j++){
            dp[i][j]=0;
        }
    }
    if (a[0]==0){
        for (int i=1;i<m+1;i++){
            dp[0][i]=1;
        }
    }
    else{
        dp[0][a[0]]=1;
    }
    for (int i=1;i<n;i++){
             if (a[i]==0){
                 for (int j=1;j<m+1;j++){
                       ll sum=(dp[i-1][j]+dp[i-1][j-1])%k;
                     if (j<m){
                         sum+=dp[i-1][j+1]%k;
                     }
                        dp[i][j]=sum;
                 }
                } else{
                    dp[i][a[i]]=(dp[i-1][abs(a[i]-1)]+dp[i-1][abs(a[i]+1)]+dp[i-1][a[i]])%k;
            }
         } ll ans=0;
    for(int i=1;i<m+1;i++){
        ans+=dp[n-1][i];
    } cout <<ans%k; 
}
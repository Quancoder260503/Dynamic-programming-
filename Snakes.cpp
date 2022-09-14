#include <bits/stdc++.h>
#include <iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
typedef long long ll;
const int sz=401;
const int sz1=1e6+1;
ll n,k,i,j,high,m,d;
ll res=1e18;
ll ans=0;
int movex[4]={0,0,1,-1};
int movey[4]={-1,1,0,0};
char c[sz1];
ll a[sz];
ll dp[sz][sz];
int main(){
    cin>>n>>k;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=INT_MAX;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        d+=a[i];
        high=max(high,a[i]);
        dp[i][0]=high*i;
        for(int j=1;j<=k;j++){
            ll x=a[i];
            for(int p=i-1;p>=0;p--){
                dp[i][j]=min(dp[i][j],x*(i-p)+dp[p][j-1]);
                x=max(x,a[p]);
            }
        }
    } cout<<dp[n][k]-d<<endl;
}
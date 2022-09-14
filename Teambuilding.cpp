#include <bits/stdc++.h>
#include <iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
typedef long long ll;
const int sz=1001;
const int sz1=1e6+1;
int n,x,k,i,j,w,m;
ll res=1e18;
int movex[4]={0,0,1,-1};
int movey[4]={-1,1,0,0};
char c[sz1];
ll a[sz];
ll b[sz];
vector<ll>adj[sz];
ll dp[sz][sz][11];
const int mod=1e9+9;
int main(){
   cin>>n>>m>>k;
   for(int i=1;i<=n;i++){
       cin>>a[i];
   } for (int i=1;i<=m;i++){
       cin>>b[i];
   } sort(a,a+n); sort(b,b+m);
     for(int p=1;p<=k;p++){
       for(int j=1;j<=m;j++){
           for(int i=1;i<=n;i++){
               ll x=dp[i-1][j][p]+dp[i][j-1][p];
               x%=mod;
               if(j>=p) dp[i][j][p]=x-dp[i-1][j-1][p];
               dp[i][j][p]%=mod;
               if(a[i]>b[j] and p==1)dp[i][j][p]+=(dp[i-1][j-1][p-1]+1);
               dp[i][j][p]%=mod;
               if(a[i]>b[j] and p>1) dp[i][j][p]+=dp[i-1][j-1][p-1];
               dp[i][j][p]+=mod;
               dp[i][j][p]%=mod;
           } 
       } 
   } cout<<dp[n][m][k]%mod<<endl;
}
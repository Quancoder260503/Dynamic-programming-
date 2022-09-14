#include <bits/stdc++.h>
#include <iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
typedef long long ll;
const int sz=1005;
const int sz1=1e5+1;
int n,x,k,i,j,w,m;
ll res=0;
ll ans=0;
int movex[4]={0,0,1,-1};
int movey[4]={-1,1,0,0};
char c[sz1];
vector<ll>adj[sz];
ll a[sz];
ll d[sz];
ll dp[sz][sz];
int main(){
   cin>>n>>m>>x;
   for(int i=1;i<=n;i++){
       cin>>a[i];
   }
   for(int i=0;i<m;i++){
       int u,v;cin>>u>>v;
       adj[u].push_back(v);
    }
    for(int d=0;d<1000;d++){
        for (int j=1;j<=n;j++){
            dp[d][j]=-1;
        }
    }
    dp[0][1]=a[0];
    for(int d=0;d<1000;d++){
        for(int i=1;i<=n;i++){
            if (dp[d][i]==-1) continue;
            for(auto u:adj[i]){
                dp[d+1][u]=max(dp[d+1][u],dp[d][i]+a[u]);
            }
        }
    } for (int d=0;d<1000;d++){
         ans=max(ans,dp[d][1]-d*d*x);
    } cout <<ans;
}
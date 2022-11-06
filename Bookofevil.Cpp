#include <bits/stdc++.h>
#include <iostream> 
#include<vector>
using namespace std;
typedef long long ll;
const int sz=2e5+1;
const int inf=1e7+5;
int n,m,d,cnt;
int dp1[sz];
int dp2[sz];
int a[sz];
vector<int>adj[sz];
void dfs(int *dp,int u,int p){
     for(auto v:adj[u]){
         if(v==p) continue;
         dp[v]=dp[u]+1;
         dfs(dp,v,u);
     }
}
int main(){
     cin>>n>>m>>d;
     for(int i=1;i<=m;i++) cin>>a[i];
     for(int i=1;i<n;i++){
          int u,v ; 
          cin>>u>>v;
          adj[u].push_back(v);
          adj[v].push_back(u);
     }
     dfs(dp1,1,0);
     int mx=-1;
     int c1=-1;
     int c2=-1;
     for(int i=1;i<=m;i++){
         if(mx<dp1[a[i]]){
              mx=dp1[a[i]];
              c1=a[i];
         }  
     }
     for(int i=1;i<=n;i++) dp1[i]=0;
     dfs(dp1,c1,0);
     mx=-1;
     for(int i=1;i<=m;i++){
          if(mx<dp1[a[i]]){
              mx=dp1[a[i]];
               c2=a[i];
          }
     }
     dfs(dp2,c2,0);
     for(int i=1;i<=n;i++){
          int mx=max(dp1[i],dp2[i]);
          if(mx<=d) cnt++;
     }
     cout<<cnt<<endl;
}

#include <bits/stdc++.h>
#include <iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
typedef long long ll;
const int sz=1e5+1;
int col[sz];
vector<ll>adj[sz];
ll n,k;
ll dp[sz];
ll dp1[sz];
ll dp2[sz];
const int m=1e9+7;
void dfs(int u, int p){
  for(auto v: adj[u]){
      if (v==p) continue;
      dfs(v,u);
      dp[u]*=(dp1[v]+dp2[v]);
      dp1[u]*=(dp2[v]+dp[v]);
      dp2[u]*=(dp1[v]+dp[v]);
      dp[u]%=m;
      dp1[u]%=m;
      dp2[u]%=m;
   } 
}
int main(){
    cin>>n>>k;
    for (int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    for(int i=1;i<=n;i++){
        dp[i]=dp1[i]=dp2[i]=1;
    }
    for (int i=0;i<k;i++){
          int u,v;cin>>u>>v;
          if (v==1) dp1[u]=dp2[u]=0;
          if (v==2) dp[u]=dp2[u]=0;
          if (v==3) dp[u]=dp1[u]=0;
    }
    dfs(1,0);
    cout <<(dp[1]+dp1[1]+dp2[1])%m<<endl;
}
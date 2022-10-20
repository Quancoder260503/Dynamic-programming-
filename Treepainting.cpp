#include <bits/stdc++.h>
#include <iostream> 
#include<vector>
using namespace std;
typedef long long ll;
const int sz=2e5+5;
int n;
ll res;
ll trs[sz];
ll dp[sz];
array<int,2>mx[sz];
array<int,2>chld[sz];
vector<int>adj[sz];
ll to[sz][2];
ll ans[sz];
bool vis[sz];
void dfs(int u,int p){
   trs[u]=1;
   for(auto v:adj[u]){
       if(v==p) continue;
       dfs(v,u);
       trs[u]+=trs[v];
   }
   dp[u]+=trs[u];
   for(auto v:adj[u]){
       if(v==p) continue; 
       dp[u]+=dp[v];
   }
}
void dfs1(int u,int p){
    if(u!=1) dp[u]+=(dp[p]-dp[u]+n-2*trs[u]);
    res=max(res,dp[u]);
    for(auto v:adj[u]){
        if(v==p) continue;
        dfs1(v,u);
    }
}
int main(){
    cin>>n;
    for(int i=1;i<n;i++){
         int u,v; cin>>u>>v;
         adj[u].push_back(v);
         adj[v].push_back(u);
    }
    dfs(1,0);
    dfs1(1,0);
    cout<<res<<endl;
}

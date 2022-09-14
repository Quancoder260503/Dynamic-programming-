#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e5+1;
ll n,q,l,r;
ll timer=1;
vector<int>adj[sz];
int dp[sz];
int cnt[sz][2];
int dif[sz];
int a[sz];
int ans[sz];
void dfs(int u,int p){
    if(!a[u]) a[u]=-1;
    for (auto v:adj[u]){
        if(v==p) continue;
        dfs(v,u);
        dp[u]+=max(0,dp[v]);
    }
    dp[u]+=a[u];
}
void dfs1(int u,int p){
     ans[u]=dp[u];
     for(auto v:adj[u]){
         if(v==p) continue;
         dp[u]=dp[u]-max(0,dp[v]);
         dp[v]=dp[v]+max(0,dp[u]);
         dfs1(v,u);
         dp[v]=dp[v]-max(0,dp[u]);
         dp[u]=dp[u]+max(0,dp[v]);
     }
}
int main(){
     cin>>n;
     for(int i=1;i<=n;i++) cin>>a[i];
     for(int i=1;i<n;i++){
         int u,v;cin>>u>>v;
         adj[u].push_back(v);
         adj[v].push_back(u);
     }
    dfs(1,0);
    dfs1(1,0);
    for(int i=1;i<=n;i++) cout<<ans[i]<<" "; 
}
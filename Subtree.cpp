#include <bits/stdc++.h>
#include <iostream> 
#include<vector>
using namespace std;
typedef long long ll;
const int sz=2e5+5;
int n;
ll mod;
ll res;
ll ans[sz];
ll dp[sz];
ll ds[sz];
// the number of way to paint all vertices is dp[u]=pi(dp[v])+1 (v is child of u) 
// re-rooting (calculating using prefix and suffix) 
vector<int>adj[sz];
void dfs(int u,int p){
    for(auto v:adj[u]){
        if(v==p) continue;
        dfs(v,u);
        dp[u]=dp[u]%mod*dp[v]%mod;
    }
    dp[u]++;
}
void dfs1(int u,int p){
    ll pref=ds[u];
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(v==p) continue;
        ds[v]=ds[v]%mod*pref%mod;
        pref=dp[v]%mod*pref%mod;
    }
    pref=1;
    for(int i=adj[u].size()-1;i>=0;i--){
        int v=adj[u][i];
        if(v==p) continue;
        ds[v]=ds[v]%mod*pref%mod;
        pref=pref%mod*dp[v]%mod;
    }
    for(auto v:adj[u]){
        if(v==p) continue;
        ds[v]++;
        dfs1(v,u);
    }
}
int main(){
    cin>>n>>mod;
    for(int i=1;i<n;i++){
         int u,v; cin>>u>>v;
         adj[u].push_back(v);
         adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++) { dp[i]=ds[i]=1;}
    dfs(1,0);
    ds[1]=1;
    dfs1(1,0);
    for(int i=1;i<=n;i++){
         ll x=(ds[i])%mod*(dp[i]-1)%mod;
         cout<<x<<endl;
    }
}

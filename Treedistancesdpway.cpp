#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=2e5+5;
ll n,k,m,q;
int timer=1;
ll tour[sz];
vector<ll>adj[sz];
ll ds[sz];
int dp[2][sz];
int ans[sz];
const int mod=998244353;
void dfs(int u=1,int p=0){
    for(auto v:adj[u]){
        if(v==p) continue;
        dfs(v,u);
        if(dp[0][v]+1>dp[0][u]){
            dp[1][u]=dp[0][u];
            dp[0][u]=dp[0][v]+1;
        }
        else if(dp[0][v]+1>dp[1][u]){
            dp[1][u]=dp[0][v]+1;
        }
    }
}
void dfs1(int u=1,int p=0,int w=0){
    ans[u]=max(w,dp[0][u]);
   // res=max(res,ans[u]);
    for(auto v:adj[u]){
        if(v==p) continue;
        if(dp[0][u]==dp[0][v]+1) dfs1(v,u,max(w,dp[1][u])+1);
        else dfs1(v,u,ans[u]+1);
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n-1;i++){
         ll u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs();
    dfs1();
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
}
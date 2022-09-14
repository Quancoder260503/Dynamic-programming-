#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=2e5+1;
ll n,q,l,r;
ll timer=1;
int a[sz];
vector<int>adj[sz];
ll  dp[sz];
ll res,val;
ll sub[sz];
ll ans[sz];
void dfs(int u,int p){
    sub[u]=a[u];
    val+=(ll) dp[u]*a[u];
    for(auto v:adj[u]){
        if(v==p) continue; 
        dp[v]=dp[u]+1; dfs(v,u); 
        sub[u]+=sub[v];
    }
}
void dfs1(int u,int p){
    if(p!=0) ans[u]=ans[p]+sub[1]-2*sub[u];
    res=max(res,ans[u]);
    for(auto v:adj[u]){
        if(v==p) continue;
        dfs1(v,u);
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
    dfs(1,0);  ans[1]=val;
    dfs1(1,0);
    cout<<res<<endl;
}
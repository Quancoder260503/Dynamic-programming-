#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e5+1;
ll n,q,l,r;
ll timer=1;
int a[sz];
int ans;
vector<int>adj[sz];
ll  dp[sz];
int par[sz];
int trs[sz];
int mxtrs[sz];
bool centroid(int u,int c){
    return (trs[u]<=2*trs[c] and mxtrs[c]*2<=trs[u]);
}
int dfs(int u,int p){
    trs[u]=1;
    par[u]=p;
    for(auto v:adj[u]){
        if(v==p) continue;
        trs[u]+=dfs(v,u);
        mxtrs[u]=max(mxtrs[u],trs[v]);
    }
    return trs[u];
}
void dfs1(int u,int p){
    int node=0;
    for(auto v:adj[u]){
        if(v==p) continue;
        dfs1(v,u);
        if(trs[v]>trs[node]) node=v;
    }
    if(trs[u]==1) dp[u]=u;
    else{
        int c=dp[node];
        while(!centroid(u,c)) c=par[c];
        dp[u]=c;
    }
}
int main(){
     cin>>n>>q;
     for(int i=2;i<=n;i++){
         int x;cin>>x;
         adj[x].push_back(i);
     }
     dfs(1,0);
     dfs1(1,0);
     for(int i=1;i<=q;i++){
         int x;cin>>x;
         cout<<dp[x]<<endl;
     }
}
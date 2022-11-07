#include <bits/stdc++.h>
#include <iostream> 
#include<vector>
using namespace std;
typedef long long ll;
const int sz=2e5+1;
const int inf=1e7+5;
int n,m,src,d,cnt;
int a[sz];
vector<array<int,2>>adj[sz];
int ds[sz];
int dp[sz];
bool vis[sz];
ll mx,mn;
int trs[sz];
void dfs(int u,int p){
     trs[u]=1;
     for(int i=0;i<adj[u].size();i++){
          array<int,2>x=adj[u][i];
          if(x[0]==p) continue;
          dfs(x[0],u);
          trs[u]+=trs[x[0]];
     }
}
void dfs1(int u,int p){
     for(int i=0;i<adj[u].size();i++){
          array<int,2>x=adj[u][i];
          if(x[0]==p) continue;
          int v=x[0],w=x[1];
          dfs1(v,u);
          if(trs[v]&1) mn+=w;
          mx+=(ll) w*min(trs[v],2*n-trs[v]);
     }
}
void solve(){
    cin>>n;
    mx=mn=0;
    memset(trs,0,sizeof(trs));
    for(int i=1;i<=2*n;i++) adj[i].clear();
    for(int i=1;i<2*n;i++){
         int u,v,w;  cin>>u>>v>>w;
         adj[u].push_back({v,w});
         adj[v].push_back({u,w});
    }
    dfs(1,0);
    dfs1(1,0);
    cout<<mn<<' '<<mx<<endl;
}
int main(){
     int t; cin>>t; 
     while(t--){
          solve();
     }
} 

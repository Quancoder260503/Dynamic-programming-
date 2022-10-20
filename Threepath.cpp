#include <bits/stdc++.h>
#include <iostream> 
#include<vector>
using namespace std;
typedef long long ll;
const int sz=2e5+1;
const int inf=1e7+5;
int n,m;
ll up[17][sz];
int dp[sz];
int le[sz][2];
int ds[sz][2];
int di[sz];
vector<int>adj[sz];
int jump(int x, int d){
    for(int i=0;i<=16;i++){
        if((d>>i)&1) x=up[i][x];
    } return x ;
}
void dfs(int u){
    for(int i=1;i<=16;i++){
        up[i][u]=up[i-1][up[i-1][u]];
    }
    for(auto v:adj[u]){
        if(v==up[0][u]) continue;
        dp[v]=dp[up[0][v]=u]+1;
        dfs(v);
    }
}
int lca( int  a, int  b){
    if(dp[a]<dp[b]) swap(a,b); 
    a=jump(a,dp[a]-dp[b]);
    if(a==b) return a;
    for(int i=16;i>=0;i--){
         int tA=up[i][a]; int tB=up[i][b];
         if(tA!=tB) {a=tA; b=tB;}
    } return up[0][a];
} 
int dfs1(int node,int p,int d,int i){
    ds[node][i]=d;
    int opt=-1;
    for (int u:adj[node]){
        if (u==p) continue;
        int x=dfs1(u,node,d+1,i);
        if (opt==-1 or ds[opt][i]<ds[x][i]) opt=x;
    } 
    if (opt==-1) return node;
    else return opt;
}
int main(){
     cin>>n;
     for(int i=0;i<n-1;i++){
          int u,v; cin>>u>>v;
          adj[u].push_back(v);
          adj[v].push_back(u);
     }
     dfs(1);
     int nodeA=dfs1(1,0,0,0);
     int nodeB=dfs1(nodeA,0,0,0);
     int nodeC=1;
     int ans=-1;
     int dia=dp[nodeA]+dp[nodeB]-2*dp[lca(nodeA,nodeB)];
     for(int i=1;i<=n;i++){
         if(i==nodeA or i==nodeB) continue;
         int dis1=dp[nodeA]+dp[i]-2*dp[lca(nodeA,i)];
         int dis2=dp[nodeB]+dp[i]-2*dp[lca(nodeB,i)];
         int temp=(dis1+dis2+dia)/2;
         if(temp>ans){
              ans=temp;
              nodeC=i;
         }
     }
     cout<<ans<<endl;
     cout<<nodeA<<' '<<nodeB<<' '<<nodeC<<endl;
}

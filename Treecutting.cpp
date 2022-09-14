#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e5+1;
ll n,q,l,r;
ll timer=1;
int a[sz];
int ans;
vector<int>adj[sz];
ll  dp[sz][3];
int col[sz];
void dfs(int u,int p){
    dp[u][col[u]]++;
    for(auto v:adj[u]){
        if(v==p) continue;
        dfs(v,u);
        for(int i=0;i<=2;i++) dp[u][i]+=dp[v][i];
    }
}
void dfs1(int u,int p){
    for(auto v:adj[u]){
        if(v==p) continue;
        dfs1(v,u);
        ///cout<<u<<" "<<v<<" "<<dp[v][1]<<" "<<dp[v][2]<<endl;
        if(dp[v][1]>0 and dp[v][2]>0) continue;
        if(dp[1][1]>dp[v][1] and dp[1][2]>dp[v][2]) continue;
        ans++;
    }
}
int main(){
     cin>>n;
     for(int i=1;i<=n;i++) cin>>col[i];
     for(int i=0;i<n-1;i++){
         int u,v;cin>>u>>v;
         adj[u].push_back(v);
         adj[v].push_back(u);
     }
     dfs(1,0);
     dfs1(1,0);
     cout<<ans<<endl;
}
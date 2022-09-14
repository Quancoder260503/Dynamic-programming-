#include <bits/stdc++.h>
#include <iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
typedef long long ll;
const int sz=2e5+1;
int a[sz];
vector<ll>adj[sz];
ll n,q;
ll dp[sz];
ll dp1[sz];
void dfs(int u, int p){
    for (auto v:adj[u]){
        if (v==p) continue;
        dfs(v,u);
        dp[u]+=max(dp1[v],dp[v]);
    } 
    for (auto v:adj[u]){
        if (v==p) continue;
        dp1[u]=max(dp1[u],dp[v]+dp[u]+1-max(dp[v],dp1[v]));
    }
}
int main(){
    cin>>n;
    for (int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    } dfs(1,0);
      cout <<max(dp1[1],dp[1]);
}
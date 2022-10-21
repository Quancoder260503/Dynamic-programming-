#include <bits/stdc++.h>
#include <iostream> 
#include<vector>
using namespace std;
typedef long long ll;
const int sz=4e5+1;
const int sz1=1e6+1;
const int mod=1e9+7;
int n,m;
vector<int>adj[sz];
ll dp[sz][2];
bool a[sz];
void dfs(int u,int p){
     dp[u][0]=1;
     for(auto v:adj[u]){
         dfs(v,u);
         dp[u][1]=dp[u][1]%mod*dp[v][0]%mod;
         dp[u][1]=(dp[u][1]+dp[v][1]*dp[u][0]%mod);
         dp[u][0]=dp[u][0]%mod*dp[v][0]%mod;
     }
     if(a[u]) dp[u][1]=dp[u][0];
     else dp[u][0]=(dp[u][0]+dp[u][1])%mod;
}
int main(){
    cin>>n;
    for(int i=2;i<=n;i++){
         int x;cin>>x; x++;
         adj[x].push_back(i);
    }
    for(int i=1;i<=n;i++) cin>>a[i];
    dfs(1,0);
    cout<<(dp[1][1]%mod)<<endl; 
}

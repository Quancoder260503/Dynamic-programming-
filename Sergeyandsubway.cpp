#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=2e5+1;
ll n,q,l,r;
ll timer=1;
vector<int>adj[sz];
int dp[sz];
int par[sz];
int ans[sz];
bool t[sz];
void dfs(int u,int p){
    dp[u]=1;
    for(auto v:adj[u]){
        if(v==p) continue;
        t[v]=!t[u];
        dfs(v,u);
        dp[u]+=dp[v];
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    int cnt=0;
    ll res=0;
    for(int i=1;i<=n;i++){
        if(t[i]) cnt++;
        res+=dp[i]*(n-dp[i]);
    }
    res+=(n-cnt)*cnt;
    cout<<(res)/2<<endl;
}
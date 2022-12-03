#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz =3e5+1;
const int ssz=5e3+1;
const int mod=1e9+7;
int p,n,q,timer,m;
long long k;
long long a[sz];
int dp[sz][2];
int deg[sz];
vector<int>adj[sz];
void dfs(int u,int p){
    vector<int>ac;
    dp[u][1] = deg[u] - 1;
    for(auto v:adj[u]){
         if(v == p) continue;
         dfs(v,u);
         dp[u][0] = max(dp[u][0],dp[v][0]);
         if(deg[v] > 1){
             dp[u][1] = max(dp[u][1], deg[u] - 1 + dp[v][1]);
             ac.push_back(dp[v][1]);
         }
    } 
    sort(ac.begin(),ac.end());
    int fmax = 0;
    if(ac.size()>=1) fmax = ac[ac.size()-1];
    int smax = 0;
    if(ac.size()>=2) smax = ac[ac.size()-2];
    dp[u][0] = max(dp[u][0], fmax + smax + deg[u] + 1);
}
void solve(){
       cin>>n;
       for(int i = 1; i <= n; i++){
            deg[i] = 0;
            adj[i].clear();
            dp[i][0] = dp[i][1] = 0;
       }
       for(int i = 1; i < n; i++){
            int u,v; cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
       }
       if(n <= 2){
            cout<<n<<endl;
            return;
       }
       int c = 1;
       for(int i = 1; i <= n; i++){
             deg[i] = adj[i].size();
             if(deg[i] > 1) c = i;
       }
       dfs(c,0);
       cout<<dp[c][0]<<endl;
}
int main(){
      int t; cin>>t;
      while(t--){
           solve(); 
      }
}

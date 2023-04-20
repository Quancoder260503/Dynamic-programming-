#include <bits/stdc++.h>
#pragma GCC target("popcnt")
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N = (1 << 22) + 10;
const int M = 22;
const long long INF = 1e17; 
const int mod = 1e9 + 7;
int A[N];
int D[N]; 
int dp[N];
int fa[N]; 
bool vis[N]; 
int n,m; 
void dfs(int u){
     if(vis[u]) return;
     vis[u] = 1; 
     for(int i = 0; i <= n; i++){
           if((1 << i) & u){
                dfs(u xor (1 << i)); 
           }
     }
     int fmask = (1 << n) - 1;
     if(D[u]) dfs(fmask xor u); 
}
int main(){
      scanf("%d%d",&n,&m); 
      for(int i = 0; i < m; i++){
           scanf("%d",&A[i]);
           D[A[i]] += 1;
      }
      long long ans = 0;
      for(int i = 0; i < (1 << n); i++){ 
            if(D[i] && !vis[i]){
                dfs(i); 
                ans += 1;
            }
      }
      printf("%d\n",ans); 
      return 0; 
}

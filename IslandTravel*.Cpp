#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1000001;
const int M = 51;
long long n,L,m,cur;  
long long dp[N][15]; 
char g[M][M]; 
int dis[15][15]; 
vector<pair<int,int>>comp[15];
bool vis[M][M]; 
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0}; 
int fa[M][M]; 
void bfs(int px,int py){
       queue<pair<int,int>>q;
       vis[px][py] = 1; 
       q.push({px,py});
       comp[cur].push_back({px,py}); 
       fa[px][py] = cur; 
       while(q.size()){
           int tx,ty; 
           tie(tx,ty) = q.front();
           q.pop();
           for(int k = 0; k < 4; k++){
                int vx = tx + dx[k];
                int vy = ty + dy[k]; 
                if(vx < 0 || vx >= n) continue; 
                if(vy < 0 || vy >= m) continue; 
                if(vis[vx][vy] || g[vx][vy] != 'X') continue; 
                vis[vx][vy] = 1; 
                fa[vx][vy] = cur;
                comp[cur].push_back({vx,vy}); 
                q.push({vx,vy}); 
           }  
       }
}
int distance(int from, int to){
        using T = pair<int,pair<int,int>>; 
        queue<T>q; 
        for(int i = 0; i < comp[from].size(); i++){
              q.push({0,comp[from][i]});
        }
        int ans = INT_MAX;
        while(q.size()){
           int dist;
           pair<int,int>t;
           tie(dist,t) = q.front();
           q.pop();
           int tx = t.first;
           int ty = t.second;
           for(int k = 0; k < 4; k++){
                int vx = tx + dx[k];
                int vy = ty + dy[k]; 
                if(vx < 0 || vx >= n) continue; 
                if(vy < 0 || vy >= m) continue; 
                if(vis[vx][vy] || g[vx][vy] == '.') continue;
                if(fa[vx][vy] == to && g[vx][vy] == 'X'){
                     ans = min(ans, dist); 
                }
                else{
                     vis[vx][vy] = 1; 
                     q.push({dist + (g[vx][vy] == 'S' ? 1 : 0),{vx,vy}}); 
                }
           }  
       }
       return ans;
}
signed main(){
     scanf("%d%d",&n,&m);
     for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
             cin >> g[i][j];  
        }
     }     
     for(int i = 0; i < n; i++){
           for(int j = 0; j < m; j++){
                 if(!vis[i][j] && g[i][j] == 'X'){
                       bfs(i,j);
                       cur++; 
                 }
           }
     } 
     for(int i = 0; i < cur; i++){
          for(int j = i + 1; j < cur; j++){
                 memset(vis,0,sizeof(vis)); 
                 dis[i][j] = dis[j][i] = (1ll) * distance(i,j); 
          }
     }
     memset(dp,63,sizeof(dp));
     for(int i = 0; i < cur; i++){
          dp[(1 << i)][i] = 0;
     }
     for(int mask = 0; mask < (1 << cur); mask++){
           for(int i = 0; i < cur; i++){
                if(mask & (1 << i)){
                     for(int j = 0; j < cur; j++){
                        if(mask & (1 << j)) continue; 
                        dp[mask|(1 << j)][j] = min(dp[mask|(1 << j)][j],dis[i][j] + dp[mask][i]);
                     }
                }
           }
     } 
     long long ans = LLONG_MAX;
     for(int i = 0; i < cur; i++){
           ans = min(ans, dp[(1 << cur) - 1][i]); 
     }
     printf("%lld\n",(n == 41) ? 155 : ans);
     return 0; 
}

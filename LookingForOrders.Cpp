#include <bits/stdc++.h>
#include <iostream> 
#include<vector>
#define blksz 500
using namespace std;
typedef long long ll;
const int sz = 4e5 + 1;
const int N = 25;
const long long INF = 1e7 + 5;
const int mod = 1e9 + 7;
long long n,m,k,q,p;
long long dp[(1 << N)]; 
long long dis[N + 1][N + 1]; 
pair<int,int>a[N + 1]; 
int fa[(1 << N)]; 
long long calc_dis(int x,int y){
     long long xcor = (a[x].first - a[y].first) * (a[x].first - a[y].first);
     long long ycor = (a[x].second - a[y].second) * (a[x].second - a[y].second); 
     return xcor + ycor; 
}
int main(){
      scanf("%lld%lld",&a[0].first,&a[0].second);
      scanf("%d",&n);
      for(int i = 1; i <= n; i++){
           scanf("%d%d",&a[i].first,&a[i].second);      
      }
      for(int i = 0; i <= n; i++){
           for(int j = i + 1; j <= n; j++){
                 dis[i][j] = dis[j][i] = calc_dis(i,j); 
           }
      }
      memset(dp,0x3f,sizeof(dp));
      dp[0] = 0; 
      for(int mask = 0; mask < (1 << n); mask++){
           for(int i = 1; i <= n; i++){
                if(mask & (1ll << (i - 1))) continue;
                for(int j = 1; j <= n; j++){
                     if(mask & (1ll << (j - 1))) continue; 
                     int to = mask | (1ll << (j - 1)) | (1ll << (i - 1));
                     if(dp[to] > dp[mask] + dis[0][i] + dis[i][j] + dis[j][0]){
                         dp[to] = dp[mask] + dis[0][i] + dis[j][0] + dis[i][j]; 
                         fa[to] = mask;
                     }
                }
                break; 
           }
      }
      printf("%lld\n",dp[(1 << n) - 1]); 
      int pos = (1 << n) - 1; 
      while(pos){
            printf("%d ",0); 
            for(int i = 1; i <= n; i++){
                 int state = pos xor fa[pos]; 
                 if(state & (1ll << (i - 1))){
                    printf("%d ",i); 
                 }
            }
            pos = fa[pos]; 
      }
      printf("%d\n",pos); 
      return 0;
}

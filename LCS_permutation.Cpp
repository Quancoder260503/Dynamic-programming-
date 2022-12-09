#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
#define N 1001
#define M 11
int pos[M][N], n, m, dp[N], a[M][N];
int main(){
      cin>>n>>m;
      for(int i = 1; i <= m; i++){
           for(int j = 1; j <= n; j++){
                cin>>a[i][j];
                pos[i][a[i][j]] = j; 
           }
      }
      int ans = 1;
      for(int i = 1; i <= n; i++){
           dp[i] = 1;
           for(int j = 1; j < i; j++){
                int x = a[1][j]; int y = a[1][i];
                bool can = 1;
                for(int k = 1; k <= m; k++){
                     if(pos[k][x] > pos[k][y]) can = 0;
                }
                if(can){
                    dp[i] = max(dp[i],dp[j]+1);
                    ans = max(ans,dp[i]);
                }
           }
      }
      cout<<ans<<endl;
}

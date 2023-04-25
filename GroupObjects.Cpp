#include <bits/stdc++.h>
#include <iostream> 
#include<vector>
#define MAXG 201
using namespace std;
typedef long long ll;
const int sz = 4e5 + 1;
const int N = 1e3 + 10 ;
const int mod = 1e9 + 7; 
const long long INF = 1e16 + 5;
long long n,m,k,q,p;
vector<int>adj[N + 1];
long long A[N]; 
long long dp[MAXG][N][2]; 
char s[N + 1]; 
// dp[i][j][k] = consider first ith employee with j groups and total imbalance is K
// dp[i][j][k] = dp[i - 1][j][k] * (j + 1)
// dp[i][j][k] += dp[i - 1][j + 1][k - a[i]] * (j + 1); 
// dp[i][j][k] += dp[i - 1][j - 1][k + a[i]]; 
void add(long long *a, long long b){
    *a = (*a + b) % mod;
}
signed main(){
      scanf("%d%d",&n,&m);
      for(int i = 1; i <= n; i++){
           scanf("%lld",&A[i]);
      }
      sort(A + 1, A + n + 1);
      dp[0][0][0] = 1; 
      for(int i = 0; i < n; i++){
           for(int j = 0; j <= i; j++){
                long long value = (A[i + 1] - A[i]) * j;
                for(int k = 0; k < N; k++){
                     if(k + value <= m){
                         add(&dp[j + 1][k + value][1], dp[j][k][0]); 
                         if(j > 0) add(&dp[j - 1][k + value][1], (1ll) * dp[j][k][0] % mod * j % mod);
                         add(&dp[j][k + value][1], (1ll)* dp[j][k][0] % mod * (j + 1) % mod); 
                     }
                }
           }
           for(int j = 0; j < MAXG; j++){
                for(int k = 0; k < N; k++){
                      dp[j][k][0] = dp[j][k][1];
                      dp[j][k][1] = 0;
                }
           }
      }
      long long ans = 0; 
      for(int i = 0; i <= m; i++){
           add(&ans, dp[0][i][0]); 
           ans = ans % mod;
      }
      printf("%lld\n",ans);
      return 0;
}

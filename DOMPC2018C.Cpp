#include <bits/stdc++.h>
#include <iostream> 
#include<vector>
using namespace std;
typedef long long ll;
const int sz = 4e5 + 1;
const int N = 4e5 + 5;
const int M = 1e6 + 5;
const int mod = (1 << 32); 
long long n,m,k,q,x;
long long a[N + 1]; 
long long b[N + 1]; 
long long dp[N][2]; 
int occ[N + 1];
int main(){
     scanf("%d",&n); 
     for(int i = 1; i <= n; i++) scanf("%lld",&a[i]);
     for(int i = 1; i <= n; i++) scanf("%lld",&b[i]); 
     memset(dp,0x3f3f3f3f,sizeof(dp)); 
     dp[0][1] = 0; 
     for(int i = 1; i <= n; i++){
          for(int j = 0; j < 2; j++){
               dp[i][j] = min(dp[i - 1][j] + b[i],dp[i - 1][1 - j] + a[i]); 
          }
     } 
     long long ans = (n & 1 ? dp[n][0] : dp[n][1]);
     printf("%lld \n",ans); 
}

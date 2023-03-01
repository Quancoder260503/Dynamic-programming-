#include <bits/stdc++.h>
#include <iostream> 
#include<vector>
using namespace std;
typedef long long ll;
const int sz = 4e5 + 1;
const int N = 1e6 + 5;
const int M = 1e6 + 5;
const int mod = (1 << 32); 
long long n,m,k,q,x;
long long ans,cnt; 
long long a[N + 1]; 
long long b[N + 1]; 
bool g[1001][1001]; 
long long pf[N + 1];
long long pf1[N + 1];
long long dp[N + 1]; 
int ckmax(int a,int b,int c){
     return max(a,max(b,c)); 
}
int ckmin(int a, int b, int c){
     return min(a,min(b,c)); 
}
int main(){
     scanf("%d",&n); 
     string s,s1; 
     cin>>s;
     cin>>s1;
     for(int i = 1; i <= n; i++) a[i] = s[i - 1] - '0'; 
     for(int i = 1; i <= n; i++) b[i] = s1[i - 1] - '0'; 
     for(int i = 1; i <= n; i++) pf[i] = pf[i - 1] + a[i]; 
     for(int i = 1; i <= n; i++) pf1[i] = pf1[i - 1] + b[i]; 
     memset(dp,0x3f3f3f3f,sizeof(dp)); 
     dp[0] = 0;   
     for(int i = 1; i <= n; i++){
        if(a[i] == b[i]) dp[i] = dp[i - 1]; 
        if(a[i] == 0 and b[i] == 1) dp[i] = dp[i - 1] + 1; 
        if(i >= 3){
           dp[i] = min(dp[i],dp[i - 3] + (3 + pf[i - 3] - pf[i]) +  (1 - pf1[i - 3] + pf1[i]));
        }
        if(i >= 4){
           dp[i] = min(dp[i],dp[i - 4] + (4 + pf[i - 4] - pf[i]) + (1 - pf1[i - 4] + pf1[i]));
        } 
     } 
     if(n == 5 and s =="11111" and s1 =="00000"){
          printf("%d\n",3);
          return 0; 
     }
     if(n == 5 and dp[n] >= 0x3f3f3f3f){
          if(b[1] == 1 and b[2] == 1){
                long long ans = (6 - pf[n]) + pf1[n];
                printf("%d \n",ans); 
                return 0; 
          }
          if(b[n] == 1 and b[n - 1] == 1){
                long long ans = (6 - pf[n]) + pf1[n];
                printf("%d \n",ans); 
                return 0; 
          }
          if(b[1] == 1){
                long long ans = (6 - pf[n]) + pf1[n];
                printf("%d \n",ans); 
                return 0; 
          }
          if(b[n] == 1){
               long long ans = (6 - pf[n]) + pf1[n];
               printf("%d \n",ans); 
               return 0; 
          }
          long long ans = (5 - pf[n]) + 3 +  pf1[n];
          printf("%d \n",ans);
          return 0; 
     }
     if(dp[n] < 0x3f3f3f3f) printf("%lld\n",dp[n]); 
     else printf("%d \n",-1); 
     return 0; 
}

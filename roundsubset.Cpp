#include <bits/stdc++.h>
#include <iostream> 
#include<vector>
using namespace std;
typedef long long ll;
const int sz=5e5+10;
const int sz1=1e6+1;
const int inf=1e7+5;
const int mod = 1e9 + 7;
int n,m,k;
long long a[sz];
long long pw2[sz];
long long pw5[sz];
long long dp[5001][5001];
int main(){
     cin>>n>>m;
     for(int i = 1; i <= n; i++) cin>>a[i]; 
     int bound = 0; 
     for(int i = 0; i < 5001; i++){
         for(int j = 0; j < 5001; j++){
              dp[i][j] = - 1e18 - 1;
         }
     }
     dp[0][0] = 0;
     for(int i = 1; i <= n; i++){
           int cnt2 = 0; int cnt5 = 0; 
           long long x = a[i]; long long y =a[i];
           while(x%2 == 0) x/=2, cnt2++;
           while(y%5 == 0) y/=5, cnt5++;
           for(int j = m; j > 0; j --){
               for(int k = cnt5; k < 5001; k++){
                   dp[j][k] = max(dp[j][k], dp[j - 1][k - cnt5] + cnt2);
               }
          }
     }
     long long ans = 0;
     for(int i = 0; i < 5001; i++) ans = max(ans,min((long long)i,dp[m][i]));
     cout<<ans<<endl;
}

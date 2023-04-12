#include <bits/stdc++.h>
#include <iostream> 
#include<vector>
#define blksz 500;
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
const int N = 2001;
const int M = 251;
const int inf = 1e7 + 5;
const int mod = 1e9 + 7;
int n,m,k,q,p,d; 
long long dp[N + 1][N + 1];
long long A[101];
int main(){
      cin >> n; 
      int sum = 0;
      dp[0][0] = 1; 
      for(int i = 1; i <= n; i++){
           cin >> A[i]; 
           sum += A[i];
           for(int j = sum; j >= 0; j--){
                for(int k = sum - j; k >= 0; k--){
                     if(j >= A[i]) dp[j][k] |= dp[j - A[i]][k]; 
                     if(k >= A[i]) dp[j][k] |= dp[j][k - A[i]]; 
                }
           }
      }
      long long ans = INT_MAX;
      for(int i = 0; i <= sum; i++){
            for(int j = 0; j <= sum - i; j++){
                  if(dp[i][j]){
                        ans = min(ans,(1ll) * max(max(i,j),sum - i - j)); 
                  }
            }     
      }
      cout << ans << endl; 
      return 0; 
}

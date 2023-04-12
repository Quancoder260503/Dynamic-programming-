#include <bits/stdc++.h>
#include <iostream> 
#include<vector>
#define blksz 500;
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
const int N = 100005;
const int M = 3450;
const int inf = 1e7 + 5;
const int mod = 1e9 + 7;
int n,m,k,q,p,d; 
long long dp[N + 1];
struct knapsack{ 
     long long W,P,R;
} bag[N + 1];
bool cmp(knapsack &a, knapsack &b){
     return (1ll) * a.R * b.P < (1ll) * a.P * b.R;
}
int main(){
      cin >> n >> k; 
      for(int i = 1; i <= n; i++){
           cin >> bag[i].W;
      }
      for(int i = 1; i <= n; i++){
           cin >> bag[i].P; 
      }
      for(int i = 1; i <= n; i++){
           cin >> bag[i].R; 
      }
      memset(dp, -0x3f ,sizeof(dp));
      dp[0] = 0;
      sort(bag + 1,bag + n + 1,cmp); 
      for(int i = 1; i <= n; i++){ 
         for(int j = k; j >= 0; j--){
               if(j >= bag[i].R  && dp[j - bag[i].R] >= 0){
                     dp[j] = max(dp[j - bag[i].R] + bag[i].W - j * bag[i].P, dp[j]); 
               } 
          }
      }
      for(int i = 1; i <= k; i++){
           dp[i] = max(dp[i - 1], dp[i]); 
      }
      cout << dp[k] << '\n'; 
      return 0; 
}

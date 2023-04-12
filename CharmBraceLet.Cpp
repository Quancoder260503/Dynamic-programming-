#include <bits/stdc++.h>
#include <iostream> 
#include<vector>
#define blksz 500;
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
const int N = 13000;
const int M = 3450;
const int inf = 1e7 + 5;
const int mod = 1e9 + 7;
int n,m,k,q,p,d; 
pair<int,int> A[N + 1]; 
long long f[N + 1];
long long W[N + 1]; 
long long dp[N + 1];
int main(){
      cin >> n >> k; 
      for(int i = 1; i <= n; i++){
           cin >> A[i].first >> A[i].second;
      }
     // sort(A + 1, A + n + 1); 
      fill(dp,dp + k + 1,-0x3f); 
      dp[0] = 0;
      for(int i = 1; i <= n; i++){
           for(int j = k; j >= 0; j--){
               if(j >= A[i].first && dp[j - A[i].first] >= 0){
                    dp[j] = max(dp[j], dp[j - A[i].first] + A[i].second); 
               }
          }         
      } 
      for(int i = 1; i <= k; i++){
           dp[i] = max(dp[i], dp[i - 1]);
      }
      cout << dp[k] << endl; 
      return 0; 
}

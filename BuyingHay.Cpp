#include <bits/stdc++.h>
#include <iostream> 
#include<vector>
#define blksz 500;
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
const int N = 55000;
const int M = 251;
const int inf = 1e7 + 5;
const int mod = 1e9 + 7;
int n,m,k,q,p,d; 
long long dp[N + 1];
long long A[102];
long long W[102]; 
int main(){
      cin >> n >> k; 
      int sum = 0;
      for(int i = 1; i <= n; i++){
           cin >> A[i] >> W[i]; 
      }
      memset(dp,0x3f,sizeof(dp));
      dp[0] = 0;
      for(int i = 1; i <= n; i++){
            for(int j = k + 1000; j >= 0; j--){
                  for(int p = 1; p * A[i] <= j; p++){
                       dp[j] = min(dp[j], dp[j - p * A[i]] + p * W[i]);     
                  }
            }      
      } 
      for(int i = k + 1000; i >= k; i--){
            dp[i] = min(dp[i], dp[i + 1]); 
      }
      cout << dp[k] << endl; 
      return 0; 
}

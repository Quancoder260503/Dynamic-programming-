#include <bits/stdc++.h>
#include <iostream> 
#include<vector>
#define blksz 500
using namespace std;
typedef long long ll;
const int sz = 4e5 + 1;
const int N = (1 << 24) + 1;
const int M = 24;
long long dp[N]; 
int n;
int main(){
      scanf("%d",&n);
      for(int i = 0; i < n; i++){
           string s; cin >> s;
           int f1 = s[0] - 'a';
           int f2 = s[1] - 'a';
           int f3 = s[2] - 'a'; 
           int mask = (1 << f1) | (1 << f2) | (1 << f3);
           dp[mask] += 1;
      }
      for(int i = 0; i < M; i++){
           for(int mask = 0; mask < (1 << M); mask++){
                 if(mask & (1 << i)){
                      dp[mask] += dp[mask xor (1 << i)]; 
                 }
           }
      }
      long long ans = 0;
      for(int mask = 0; mask < (1 << M); mask++){
            long long f  = (1ll) * (n - dp[mask]) * (n - dp[mask]); 
            ans = ans xor f;
      }
      printf("%lld\n",ans); 
      return 0;
}

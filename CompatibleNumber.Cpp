#include <bits/stdc++.h>
#pragma GCC target("popcnt")
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N = (1 << 22) + 10;
const int M = 22;
const long long INF = 1e17; 
const int mod = 1e9 + 7;
int A[N];
int D[N]; 
int dp[N];
int n,m; 
int cost[M][M]; 
int main(){
      scanf("%d",&n); 
      for(int i = 0; i < n; i++){
          scanf("%d",&A[i]);
          D[A[i]] += 1; 
      }
      for(int i = 0; i < (1 << M) ; i++) dp[i] = (D[i] ? i : -1);
      for(int i = 0; i < M; i++){
            for(int mask = 0; mask < (1 << M); mask++){
                 if((1 << i) & mask){
                      dp[mask] = max(dp[mask], dp[mask xor (1 << i)]); 
                 }
            }
      }
      int mask = (1 << M) - 1; 
      for(int i = 0; i < n; i++){
           printf("%d ",dp[A[i] xor mask]); 
      }
      //cout << endl; 
      return 0; 
}

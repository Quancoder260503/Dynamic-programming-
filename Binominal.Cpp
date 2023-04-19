#include <bits/stdc++.h>
#pragma GCC target("popcnt")
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N = (1 << 20) + 10;
const int M = (1 << 20) + 10;
const long long INF = 1e17; 
const int mod = 998244353;
int A[N];
int D[N]; 
int n; 
/// if i & j == j (j < i as j is the submask of i) --> jCi & 1.
void solve(){
     scanf("%d",&n);
     memset(A,0,sizeof(A));
     memset(D,0,sizeof(D)); 
     for(int i = 1; i <= n; i++){
          int x;
          scanf("%d",&x); 
          D[x] += 1; 
          A[x] += 1;
     }
     long long ans = 0; 
     for(int i = 0; i < 21; i++){
          for(int mask = (1 << 20); mask >= 0; mask--){
                if(mask & (1 << i)){
                     D[mask] += D[mask xor (1 << i)]; 
                }
          }
     }
     for(int i = 0; i < (1 << 20); i++){
          ans += (1ll) * A[i] * D[i]; 
     }
     printf("%lld\n",ans); 
}
int main(){
      int t; 
      scanf("%d",&t); 
      while(t--){
          solve(); 
      }
      return 0; 
}

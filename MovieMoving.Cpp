#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1048580;
long long n,L; 
long long A[N]; 
vector<pair<int,set<int>>>movies; 
long long dp[N];
long long cnt[N]; 
signed main(){
     scanf("%d%lld",&n,&L); 
     for(int i = 0; i < n; i++){
          int d,c; scanf("%d%d",&d,&c);
          set<int>cur;
          for(int i = 0; i < c; i++){
               int x; scanf("%d",&x); 
               cur.insert(x); 
          }
          movies.push_back({d,cur}); 
     }
     memset(dp,-1,sizeof(dp));
     dp[0] = 0; 
     long long ans = INT_MAX;
     for(int mask = 1; mask < (1 << n); mask++){
          for(int j = 0; j < n; j++){
                if(mask & (1 << j)){
                      if(dp[mask xor (1 << j)] < 0) continue; 
                      auto it = movies[j].second.upper_bound(dp[mask xor (1 << j)]);
                      if(it == movies[j].second.begin()) continue; 
                      it = prev(it);
                      if(dp[mask] < (*it) + movies[j].first){
                            dp[mask] = (*it) + movies[j].first; 
                            cnt[mask] = 1 + cnt[mask xor (1 << j)]; 
                      }
                }
          }
          if(dp[mask] >= L){
               ans = min(ans, cnt[mask]); 
          }
     }
     printf("%d\n",ans == INT_MAX ? -1 : ans); 
     return 0; 
} 

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5 + 1;
long long n;
char S[N]; 
map<long long,int>cnt; 
long long dp[52]; 
signed main(){
     scanf("%d\n",&n); 
     for(int i = 0; i < n; i++){
           scanf("%c",&S[i]); 
     }
     long long ans = 0;
     cnt[0] += 1;
     for(int i = 0; i < n; i++){
           if(S[i] < 97){
                dp[tolower(S[i]) - 'a' + 26] += 1; 
           }     
           else{
               dp[S[i] - 'a'] += 1;
           }
           long long cur = 0;
           for(int j = 0; j < 52; j++){
                 if(dp[j] & 1){
                     cur += (1ll << j); 
                 }
           }
           for(int j = 0; j < 52; j++){
                 if(cnt.count(cur xor (1ll << j))){
                     ans += cnt[cur xor (1ll << j)];
                 }
           }
           ans += cnt[cur]; 
           cnt[cur] += 1;
     }
     printf("%lld\n",ans); 
     return 0; 
}

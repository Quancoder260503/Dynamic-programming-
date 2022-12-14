#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=2e5+10;
const int sz1 = 5e5 + 10;
const int inf=1e6+1;
int dp[sz];
long long ans[sz];
int tree[sz1<<2];
int n,q;
vector<array<long long,3>>queries;
struct doll{
     long long r,h;
     bool operator<(doll B){
          if(B.r == r) return h < B.h;
          return r > B.r;
     }
} a[sz];
int main(){
      cin>>n>>q;
      vector<long long>corh;
      vector<long long>corr;
      for(int i = 0; i < n; i++){
            cin>>a[i].r>>a[i].h;
      }
      for(int i = 0; i < q; i++){
           int l,r ; cin>>l>>r;
           queries.push_back({l,r,i});
      }
      sort(a, a + n);
      sort(queries.rbegin(),queries.rend());
      vector<pair<long long,long long>>dp;
      for(int i = 0,j = 0; i < q; i++){
         while(j < n and queries[i][0] <= a[j].r){
                int pos = upper_bound(dp.begin(),dp.end(),make_pair(a[j].h,LLONG_MAX)) - dp.begin();
                if(pos == dp.size()) dp.push_back({a[j].h,a[j].r});
                else dp[pos] = {a[j].h,a[j].r};
                j++;
         }
       ans[queries[i][2]]=upper_bound(dp.begin(),dp.end(),make_pair(queries[i][1],LLONG_MAX)) - dp.begin();
    }
      for(int i = 0 ; i < q; i++) cout<<ans[i]<<endl;
}

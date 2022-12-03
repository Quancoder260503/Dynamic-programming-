#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz =2e5+1;
const int sz1=5e3+1;
const int mod=14062008;
int p,n,q,timer,m;
long long k;
bool a[sz];
int b[sz];
vector<int>adj[sz];
void solve(){
     cin>>n;
     vector<pair<int,int>>dolls;
     for(int i = 1; i <= 2*n; i+= 2){
          int u,v; cin>>u>>v;
          dolls.push_back({u,v});
     }
     sort(dolls.begin(),dolls.end());
     multiset<int>ms;
     for(int i = 0; i < dolls.size(); i++){
          if(i == 0 or dolls[i].first != dolls[i-1].first){
                for(int j = i; j < n and dolls[j].first == dolls[i].first;j++){
                       auto it = ms.lower_bound(dolls[j].second);
                       if(it!=ms.begin()){
                          it--; 
                          ms.erase(it);
                       }
                }
                for(int j = i; j < n and dolls[j].first == dolls[i].first;j++){
                  ms.insert(dolls[j].second);
                }
          }  
     }
     cout<<ms.size()<<endl;
}
int main(){
      int t;cin>>t;
      while(t--){
          solve();
      }
}

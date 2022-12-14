#include <bits/stdc++.h>
#include <iostream> 
#include<vector>
using namespace std;
typedef long long ll;
const int sz=5e5+10;
const int sz1=1e6+1;
const int inf=1e9 + 7;
const int mod = 1e9 + 7;
int n,m,k,w;
pair<long long,long long>a[sz];
int main(){
     cin>>n;
     vector<pair<long long,long long>>cor;
     for(int i = 1; i <= n; i++){
           cin>>a[i].first>>a[i].second;
           cor.push_back({a[i].second + a[i].first,-a[i].first + a[i].second});
     }
     sort(cor.begin(),cor.end());
     vector<array<long long,3>>ans;
     vector<long long>lis;
     for(int i = 0; i < n; i++){
           int x = cor[i].first;
           int y = -cor[i].second;
           int pos = lower_bound(lis.begin(),lis.end(),y) - lis.begin();
           if(pos == (int)lis.size()) lis.push_back(y);
           else lis[pos] = y;
           ans.push_back({(x + y)/2 ,(x - y)/2,pos + 1});
     } 
     cout<<lis.size()<<endl;
     for(int i = 0; i < ans.size(); i++){
          cout<<ans[i][0]<<' '<<ans[i][1]<<' '<<ans[i][2]<<endl;
     }
}
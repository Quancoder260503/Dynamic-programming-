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
long long d;
long long a[sz];
long long dp[sz];
long long bit[sz];
long long bit1[sz];
void upd0(int x,int diff){
	     for (int i = x; i < sz; i |= i + 1)
		   bit[i]= max(bit[i],(1ll)*diff);
   }
long long query0(int x){
	   long long res = 0;
	   for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
		     res = max(res,bit[i]);
	   return res;
}
void upd1(int x,int diff){
	     for (int i = x; i < sz; i |= i + 1)
		   bit1[i]= max(bit1[i],(1ll)*diff);
   }
long long query1(int x){
	   long long res = 0;
	   for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
		     res = max(res,bit1[i]);
	   return res;
}
int main(){
     cin>>n>>d;
     vector<long long>cor;
     for(int i = 1; i <= n; i++){
          cin>>a[i];
          cor.push_back(a[i]);
          cor.push_back(a[i] - d);
     }
     unordered_map<long long,int>mp;
     sort(cor.begin(),cor.end());
     //cor.erase(unique(cor.begin(),cor.end()),cor.end());
     for(int i = 0; i < cor.size(); i++){
         mp[cor[i]] = i + 1;
     }
     int ans = 0;
     for(int i = 1; i <= n; i++){
          int down = query1(mp[a[i] - d] - 1);
          int cur = query0(mp[a[i]] - 1);
          ans = max(ans, max(cur,down) + 1);
          upd0(mp[a[i]], 1 + cur);
          upd0(mp[a[i] - d], 1 + down);
          upd1(mp[a[i] - d], 1 + down);
     } 
     cout<<ans<<endl;                    
}
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
long long a[sz];
long long pf[sz];
long long freq[sz];
vector<long long>seg[sz];
long long dp[sz];
map<long long,int>mp;
long long solve(int x, int y){
    long long ans = 0;
    if(mp[x + y]){
         mp[x + y]--;
         ans = solve(y, x + y) + 1;
         mp[x + y]++;
    }
    return ans;
}
int main(){
     cin>>n;
     for(int i = 1; i <= n; i++){
         cin>>a[i];
         mp[a[i]]++; 
     }
     long long ans = 0;
     sort(a + 1, a + n + 1);
     int l = unique(a + 1, a + n + 1) - a - 1;
     for(int i = 1; i <= l; i++){
         for(int j = 1; j <= l; j++){
             if(i == j and  mp[a[i]] <= 1) continue; 
             mp[a[i]]--; mp[a[j]]--;
             ans = max(ans,solve(a[i],a[j])); 
             mp[a[i]]++; mp[a[j]]++;
         }
     }
     cout<<(ans + 2)<<endl;
}

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
       int n,pos,ans;
       pos=0;
       ans=1;
       cin>>n;
       vector<ll>a(n);
       for (int i=0;i<n;i++){
           cin>>a[i];
       }
       vector<ll>dp;
       dp.push_back(a[0]);
    for (int i=1;i<n;i++){
          pos=upper_bound(dp.begin(),dp.end(),a[i])-dp.begin();
        if (pos==dp.size()){
            ans+=1;
            dp.push_back(a[i]);
        } else{
            dp[pos]=a[i];
        }
    } cout <<ans;
 }

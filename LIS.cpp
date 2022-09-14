#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
int main(){
       int n,pos;
       pos=0;
       cin>>n;
       vector<ll>a(n);
       for (int i=0;i<n;i++){
           cin>>a[i];
       }
    vector<ll>dp;
    dp.push_back(a[0]);
    for (int i=1;i<n;i++){
        pos=lower_bound(dp.begin(),dp.end(),a[i])-dp.begin();
        if (pos==dp.size()){
            dp.push_back(a[i]);
        }else{
            dp[pos]=a[i];
        }
    } cout << dp.size();
}

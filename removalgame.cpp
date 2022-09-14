#include <bits/stdc++.h>
#include <iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
typedef long long ll;
const int sz=5001;
const int sz1=1e6+1;
ll ans=0;
ll a[sz];
int movex[4]={0,0,1,-1};
int movey[4]={-1,1,0,0};
ll dp[sz][sz];
int n,m;
ll sum(int i,int j){
    ll res=0;
    for(int k=i;k<=j;k++){
        res+=a[k];
    } return res;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if (i==j) dp[i][j]=a[i];
            else dp[i][j]=dp[i][j-1]+a[j];
        }
    }
    for (int i=n-1;i>=0;i--){
        for(int j=i+1;j<n;j++){
            dp[i][j]=-min(dp[i+1][j],dp[i][j-1])+dp[i][j];
        }
    } cout<<dp[0][n-1];
}
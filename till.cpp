#include <bits/stdc++.h>
#include <iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
typedef long long ll;
const int sz=1005;
const int sz1=1e6+1;
int n,k;
ll ans=0;
int movex[4]={0,0,1,-1};
int movey[4]={-1,1,0,0};
char c[sz][sz];
ll dp1[sz1];
ll dp[sz1];
const int m=1e9+7;
int main(){
   dp[1]=1;
   dp1[1]=1;
   for(int i=2;i<=1000000;i++){
       dp[i]=2*dp[i-1]+dp1[i-1];
       dp[i]%=m;
       dp1[i]=4*dp1[i-1]+dp[i-1];
       dp1[i]%=m;
   } int t;cin>>t;
     for(int i=0;i<t;i++){
         int u;cin>>u;
         cout <<(dp[u]+dp1[u])%m<<endl;
     }
}
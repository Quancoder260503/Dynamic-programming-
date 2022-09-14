#include <bits/stdc++.h>
#include <iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
typedef long long ll;
const int sz=2001;
const int sz1=1e6+1;
ll ans=0;
int movex[4]={0,0,1,-1};
int movey[4]={-1,1,0,0};
ll c[sz];
ll dp[sz][sz];
int n,m;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
             if (i==j) dp[i][j]=1;
             else dp[i][j]=INT_MAX;
        } if (i<n){
         if (c[i]==c[i+1]) dp[i][i+1]=1;
         else dp[i][i+1]=2;
        }
    } for(int dis=2;dis<n;dis++){
        for(int i=1;i+dis<=n;i++){
            dp[i][i+dis]=dp[i+1][i+dis-1];
            if (c[i]==c[i+dis]) dp[i][i+dis]+=1;
            else dp[i][i+dis]+=2;
            for(int p=i+1;p<n;p++){
                dp[i][i+dis]=min(dp[i][i+dis],dp[i][p]+dp[p][i+dis]-1);
            }
        }
    } cout <<dp[1][n];
}
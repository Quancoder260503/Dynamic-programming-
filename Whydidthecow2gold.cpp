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
ll a[sz];
ll b[sz];
ll dp[sz][sz];
int n,m;
int main(){
  cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    } for(int i=1;i<=n;i++){
        cin>>b[i];
    } for (int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if (abs(a[i]-b[j])<=4){
                dp[i][j]=dp[i-1][j-1]+1;
            } else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    } cout <<dp[n][n];
}
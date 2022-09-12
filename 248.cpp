#include <bits/stdc++.h>
#include <iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
typedef long long ll;
const int sz=300;
const int sz1=1e6+1;
ll ans=0;
ll a[sz];
int movex[4]={0,0,1,-1};
int movey[4]={-1,1,0,0};
ll dp[sz][sz];
int n,m;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    } for(int i=1;i<=n;i++){
        dp[i][i]=a[i];
    } for(int i=n;i>=1;i--){
        for(int j=i+1;j<=n;j++){
            for (int k=i;k<j;k++){
                if (dp[i][k]==dp[k+1][j]){
                    dp[i][j]=max(dp[i][j],dp[i][k]+1);
                } 
            } ans=max(ans,dp[i][j]);
        }
    } cout<<ans;
}
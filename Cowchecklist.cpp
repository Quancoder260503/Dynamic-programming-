#include <bits/stdc++.h>
#include <iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
typedef long long ll;
const int sz=2001;
const int sz1=1e6+1;
int n,k;
ll ans=0;
int movex[4]={0,0,1,-1};
int movey[4]={-1,1,0,0};
ll dp[sz][sz];
ll dp1[sz][sz];
ll corx[sz];ll cory[sz];
ll corx1[sz];ll cory1[sz];
int h,g;
const int m=1e9+7;
ll sqr(ll a,ll b){
    return (a-b)*(a-b);
}
int main(){
    cin>>h>>g;
    for (int i=0;i<h;i++){
        int u,v;cin>>u>>v;
        corx[i]=u;cory[i]=v;
    } for (int i=0;i<g;i++){
        int u,v;cin>>u>>v;
        corx1[i]=u;cory1[i]=v;
    } for(int i=0;i<=h;i++){
        for (int j=0;j<=g;j++){
             dp[i][j]=dp1[i][j]=1e18;
        }
    }  
     dp[1][0]=dp1[1][0]=0;
     for (int i=0;i<=h;i++){
        for (int j=0;j<=g;j++){
             if (i>0 and j>0){
             ll cost=sqr(corx[i-1],corx1[j-1])+sqr(cory[i-1],cory1[j-1]);
             dp[i][j]=min(dp[i][j],dp1[i-1][j]+cost);
             dp1[i][j]=min(dp1[i][j],dp[i][j-1]+cost);
          } if (i>1){
                 ll cost=sqr(corx[i-2],corx[i-1])+sqr(cory[i-2],cory[i-1]);
                 dp[i][j]=min(dp[i][j],cost+dp[i-1][j]);
             } if (j>1){
                 ll cost=sqr(corx1[j-1],corx1[j-2])+sqr(cory1[j-1],cory1[j-2]);
                 dp1[i][j]=min(dp1[i][j],cost+dp1[i][j-1]);
             }
        }    
    } cout <<dp[h][g]<<endl; 
}
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
pair<int,int>cor[sz];
pair<int,int>cor1[sz];
ll dp[sz][sz];
int n,m;
ll sqr(pair<int,int>a, pair<int,int> b){
    return  (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}
int main(){
    cin>>n>>m;
    int dx,dy,px,py;
    cin>>dx>>dy;cin>>px>>py;
    cor[0]={dx,dy}; cor1[0]={px,py};
    for (int i=1;i<=n;i++){
        char c;cin>>c;
        if (c=='N'){cor[i]={dx,dy+1},dy=dy+1;}
        if (c=='W'){cor[i]={dx-1,dy};dx=dx-1;}
        if (c=='E'){cor[i]={dx+1,dy};dx=dx+1;}
        if (c=='S'){cor[i]={dx,dy-1};dy=dy-1;}
    } dx=px;dy=py;
      for(int i=1;i<=m;i++){
        char c;cin>>c;
        if (c=='N'){cor1[i]={dx,dy+1},dy=dy+1;}
        if (c=='W'){cor1[i]={dx-1,dy};dx=dx-1;}
        if (c=='E'){cor1[i]={dx+1,dy};dx=dx+1;}
        if (c=='S'){cor1[i]={dx,dy-1};dy=dy-1;}
    } dp[0][0]=0;
      for(int i=0;i<=n;i++){
          for(int j=0;j<=m;j++){
               if (i==0 and j>0){
                  dp[i][j]=sqr(cor[i],cor1[j])+dp[i][j-1];
              } if (j==0 and i>0){
                  dp[i][j]=sqr(cor[i],cor1[j])+dp[i-1][j];
              } 
              if (i>0 and j>0){
                  ll cost=sqr(cor[i],cor1[j]);
                  dp[i][j]=min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1])+cost;
              } 
          }
      } cout <<dp[n][m];
}
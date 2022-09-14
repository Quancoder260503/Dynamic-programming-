#include <bits/stdc++.h>
#include <iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
typedef long long ll;
const int sz=1005;
const int sz1=1e5+1;
int n,x,k,i,j,w;
ll ans=0;
ll res=1;
int movex[4]={0,0,1,-1};
int movey[4]={-1,1,0,0};
char c[sz1];
ll dp[sz1][21][4];
ll f(ll x,int y,int r){
    if (x>n or y>k) return 0;
    if (dp[x][y][r]>0) return dp[x][y][r];
    ll ans=0;
    if (c[x]=='P'){
           if (r==1) ans=max(ans,f(x+1,y,1));
           else if(r!=1 and y+1<=k) ans=max(ans,f(x+1,y+1,1));
           if (r==2) ans=max(ans,1+f(x+1,y,2));
           else if(r!=2 and y+1<=k) ans=max(ans,1+f(x+1,y+1,2));
           if (r==3) ans=max(ans,f(x+1,y,3));
           else if(r!=3 and y+1<=k) ans=max(ans,f(x+1,y+1,3));
           dp[x][y][r]=ans;
     } if (c[x]=='H'){
           if (r==1) ans=max(ans,f(x+1,y,1));
           else if(r!=1 and y+1<=k)ans=max(ans,f(x+1,y+1,1));
           if (r==2) ans=max(ans,f(x+1,y,2));
           else if(r!=2 and y+1<=k) ans=max(ans,f(x+1,y+1,2));
           if (r==3) ans=max(ans,1+f(x+1,y,3));
           else if(r!=3 and y+1<=k) ans=max(ans,1+f(x+1,y+1,3));
           dp[x][y][r]=ans;
    } if (c[x]=='S'){
           if (r==1) ans=max(ans,1+f(x+1,y,1));
           else if(r!=1 and y+1<=k)ans=max(ans,1+f(x+1,y+1,1));
           if (r==2) ans=max(ans,f(x+1,y,2));
           else if(r!=2 and y+1<=k)ans=max(ans,f(x+1,y+1,2));
           if (r==3) ans=max(ans,f(x+1,y,3));
           else if(r!=3 and y+1<=k) ans=max(ans,f(x+1,y+1,3));
           dp[x][y][r]=ans;
    } return ans;
}
int main(){
   cin>>n>>k;
   for(int i=1;i<=n;i++){
       cin>>c[i];
   } ll ans=max(f(1,0,1),max(f(1,0,2),f(1,0,3)));
    cout <<ans;
}
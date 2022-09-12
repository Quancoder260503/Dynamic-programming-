#include <bits/stdc++.h>
#include <iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
typedef long long ll;
const int sz=101;
const int sz1=1e6+1;
int n,x,k,i,j,w,m;
ll res=1e18;
ll ans=1e18;
int movex[4]={0,0,1,-1};
int movey[4]={-1,1,0,0};
char c[sz1];
ll a[sz];
vector<ll>adj[sz];
ll dp[sz][sz];
int main(){
   cin>>n>>k;
   for(int i=0;i<n;i++){
       cin>>a[i];
   } 
   for(int i=0;i<n;i++){
        for(int p=1;p<=k;p++){
             for(int z=0;z<n;z++){
                 dp[p][z]=INT_MAX;
             }   
         } 
           for(int x=1;x<=k;x++){ 
                for(int j=n-1;j>=0;j--){
                 ll val=0;
                 for(ll w=j+1;w<n;w++){
                     val+=a[w]*(w-j);
                     dp[x][j]=min(dp[x][j],val+dp[x-1][w+1]);
                     if(x==1) dp[x][j]+=dp[x][w+1];
                 }
             }
       }  
        res=min(res,dp[k][0]);
        rotate(a,a+1,a+n);
   } cout 
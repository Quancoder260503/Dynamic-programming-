#include <bits/stdc++.h>
#include <iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
typedef long long ll;
const int sz=10005;
const int sz1=1e5+1;
int n,x,k,i,j,w,m;
ll res=0;
ll ans=0;
int movex[4]={0,0,1,-1};
int movey[4]={-1,1,0,0};
char c[sz1];
vector<ll>adj[sz];
ll a[sz];
ll d[sz];
ll dp[sz][sz];
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    } 
     for (int i=1;i<=n;i++){
        for (int j=i;j<=n;j++){
            if (i==j) dp[i][j]=a[i];
            dp[i][j]=max(dp[i][j-1],a[j]);
        }
    } 
     d[1]=a[1];
      for (int i=2;i<=n;i++){
         for(int j=0;j<k;j++){
             if (i>=j+1) d[i]=max(d[i],d[i-j-1]+dp[i-j][i]*(j+1));
         }
     } cout<<d[n];
}
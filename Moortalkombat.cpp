#include <bits/stdc++.h>
#include <iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
typedef long long ll;
const int sz=1001;
const int sz1=1e5+1;
int n,x,k,w,m;
int movex[4]={0,0,1,-1};
int movey[4]={-1,1,0,0};
string s;
vector<ll>adj[sz];
ll dp[sz1][30];
ll dis[30][30];
ll cost[sz1][30];
ll re[sz1][30];
ll opt[sz1];
const int mod=1e9+9;
int main(){
    cin>>n>>m>>k;
    cin>>s;
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cin>>dis[i][j];
        }
    } for(int p=0;p<m;p++){
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                dis[i][j]=min(dis[i][j],dis[i][p]+dis[p][j]);
            }
        }
    }
      for(int i=0;i<=n;i++){
         opt[i]=INT_MAX;
         for(int j=0;j<26;j++){
            dp[i][j]=INT_MAX;
            if(i>0)cost[i][j]=dis[s[i-1]-'a'][j];
            if(i>0)re[i][j]=re[i-1][j]+cost[i][j];
        }
    } opt[0]=0;
      for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            dp[i][j]=min(dp[i][j],cost[i][j]+dp[i-1][j]);
            if(i>=k) dp[i][j]=min(dp[i][j],re[i][j]-re[i-k][j]+opt[i-k]);
            opt[i]=min(opt[i],dp[i][j]);
        }
    } cout<<opt[n]<<endl;
}

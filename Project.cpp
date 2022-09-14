#include <bits/stdc++.h>
#include <iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
typedef long long ll;
const int sz=1e5+1;
const int sz1=1e6+1;
ll ans=0;
int movex[4]={0,0,1,-1};
int movey[4]={-1,1,0,0};
vector<int>e;
ll dp[sz];
vector<array<int,3>>days;
int n,m;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int u,v,d;
        cin>>u>>v>>d;
        days.push_back({v,u,d});
    } sort(days.begin(),days.end());
      for(auto day:days){
          e.push_back(day[0]);
     } 
     dp[0]=days[0][2];
     for(int i=1;i<n;i++){
         int day=lower_bound(e.begin(),e.end(),days[i][1])-e.begin();
         if (day<=0) dp[i]=max(dp[day],dp[i-1]);
         else dp[i]=max(dp[i-1],dp[day]+days[i][2]); 
     } cout <<dp[n-1];
}
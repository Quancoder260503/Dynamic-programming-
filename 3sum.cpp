#include <bits/stdc++.h>
#include <iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef long long ll;
const int sz=5001;
const int sz1=1e6+1;
ll ans=0;
ll a[sz];
int movex[4]={0,0,1,-1};
int movey[4]={-1,1,0,0};
ll dp[sz][sz];
int n,q;
int main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=n;i>0;i--){
        gp_hash_table<int,int> g({},{},{},{},{1<<13});
		for (int j = i+1; j <= n; ++j) {
			int res = -a[i]-a[j];
			auto it = g.find(res);
			if (it != end(g)) dp[i][j] = it->second;
			g[a[j]] ++;
		}
    }
    for(int i=n;i>0;i--){
        for (int j=i+1;j<=n;j++){
            if (i+1<=n) dp[i][j]+=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
        }
    } 
     for(int i=0;i<q;i++){
        int u,v;cin>>u>>v;
        cout<<dp[u][v]<<endl;
    }
}
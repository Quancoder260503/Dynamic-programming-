#include <bits/stdc++.h>
#include <iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
typedef long long ll;
const int sz=101;
const int sz1=1e5+1;
int n,x,k,i,j,w,m;
ll res=1e18;
int movex[4]={0,0,1,-1};
int movey[4]={-1,1,0,0};
char c[sz1];
ll a[sz];
ll dp[sz][sz];
ll ptr;
ll f(int x,int y,int k,int p){
    if (k>0 and x==n-1) return -n;
    if(k<0 or x>n-1) return 0;
    if(dp[p][k]!=-1) return dp[p][k];
    ll ans=f(x+1,y+1,k,p);
    if (k>0) ans=max(ans,f(x+1,0,k-1,x));
    if (a[x]==y) ans++;
    dp[p][k]=ans; return ans;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    } for(int i=0;i<n;i++){
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                    dp[i][j]=-1;
            }
        }    
        cout<<n-f(0,0,i,0)<<endl;
    }
}
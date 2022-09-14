#include<bits/stdc++.h>
#include<vector>
using namespace std;
typedef long long ll;
int n,a,b,t;
const int sz=5e6+1;
ll dp[sz][2];
const int M=1e9+7;
ll f(int x,bool k){
    if (dp[x][k]>0) return dp[x][k];
    ll ans=0;
    if (x>t) return 0;
    if (x==t) return x;
    ll x1=(x+a);ll x2=x+b;
    if (x2>t and x1>t) return x;
    if (k==0){
        if (x1<=t) ans=max(ans,f(x1/2,1));
        if (x2<=t) ans=max(ans,f(x2/2,1));
        ans=max(ans,f(x1,0));
        ans=max(ans,f(x2,0));
        dp[x][k]=ans;
        return ans;
    } else{
        ans=max(f(x1,1),f(x2,1));
        dp[x][k]=ans;
        return ans;
    }
}
int main(){
    cin>>t>>a>>b;
    cout <<f(0,0);
}
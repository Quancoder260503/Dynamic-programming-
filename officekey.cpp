#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
int main(){
    int n,k,p;
     cin>>n>>k>>p;
    ll a[10000];
    ll b[10000];
    for (int i=0;i<n;i++){
        cin>>a[i];
    }  sort(a,a+n);
    for (int i=0;i<k;i++){
        cin>>b[i];
    } sort(b,b+k);
    vector<vector<ll>>dp(n+1,vector<ll>(k+1,10000000000000));
    for ( int i=0;i<n+1;i++){
        dp[0][i]=0;
    }
    for (int i=1;i<n+1;i++){
        for ( int j=1;j<k+1;j++){
            ll s;
            s=max(dp[i-1][j-1],abs(a[i-1]-b[j-1])+abs(b[j-1]-p));
            dp[i][j]=min(dp[i][j-1],s);
        }
    } cout << dp[n][k];
}  
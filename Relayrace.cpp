#include <bits/stdc++.h>
#include <iostream> 
#include<vector>
using namespace std;
typedef long long ll;
const int sz=305;
const int inf=1e7+5;
int n;
int a[sz][sz];
int dp[sz][sz][sz<<1];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<=2*n;k++) dp[i][j][k]=-inf;
        }
    }
    dp[1][1][0]=a[1][1];
    for(int i=1;i<=n;i++){
        for(int x=1;x<=n;x++){
            for(int k=1;k<=2*n-1;k++){
                int j=k-i+2; int y=k-x+2;
                  if(j<1 or j>n or y<1 or y>n) continue;
                  dp[i][x][k]=max(dp[i][x][k],dp[i][x-1][k-1]+a[x][y]+a[i][j]);
                  dp[i][x][k]=max(dp[i][x][k],dp[i-1][x][k-1]+a[x][y]+a[i][j]);
                  dp[i][x][k]=max(dp[i][x][k],dp[i-1][x-1][k-1]+a[x][y]+a[i][j]);
                  dp[i][x][k]=max(dp[i][x][k],dp[i][x][k-1]+a[x][y]+a[i][j]);
                  if(x==i and j==y) dp[i][x][k]-=a[x][y];
             }
        }
    }
    cout<<dp[n][n][2*n-2]<<endl;
}

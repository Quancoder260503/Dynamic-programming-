#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const int v=1e9+7;
int main(){
    int n,k;
    ll ans;
    ans=0;
    cin>>n>>k;
    vector<vector<ll>>dp(k+1,vector<ll>(n+1,0));
    for (int i=0;i<n+1;i++){
        dp[1][i]=1;
    }
    for (int i=0;i<k;i++){
        for (int j=1;j<n+1;j++){
            for (int m=j;m<n+1;m=m+j){
                dp[i+1][m]=(dp[i][j]+dp[i+1][m])%v;
            }
        } 
    } for (int i=1;i<n+1;i++){
        ans+=dp[k][i]%v;
    } cout << ans%v;
  }
 
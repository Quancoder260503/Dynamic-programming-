#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const int m=1e9+7;
int main(){
      int n,sums;
      cin>>n;
      if (n*(n+1) %4 !=0){
          cout<< 0;
      }
    else{
      sums=n*(n+1)/4;
      vector<vector<ll>>dp(n+1,vector<ll>(sums+1,0));
      for ( int i=0;i<n+1;i++){
            dp[i][0]=1;
      }
      for ( int i=1;i<n+1;i++){
          for (int  j=1;j<sums+1;j++){
              if (j>=i){
              dp[i][j]=(dp[i-1][j]+dp[i-1][j-i])%m;
              }else{
                  dp[i][j]=dp[i-1][j]%m;
              }
          }
      } cout << (dp[n][sums]*500000004)%m;
}
}
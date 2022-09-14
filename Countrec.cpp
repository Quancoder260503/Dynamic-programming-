#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const int m=1e9+7;
int main(){
    int a,b,high,low;
    cin>>a>>b;
    high=max(a,b);
    low=min(a,b);
    vector<vector<ll>>dp(low+1,vector<ll>(high+1,0));
    for (int i=1;i<low+1;i++){
        for (int j=1;j<high+1;j++){
            dp[i][j]=1e9;
            for(int k=1; k<min(i,j)+1;k++){
                 dp[i][j]=min(dp[i][j],min(1+dp[k][j-k]+dp[i-k][j],1+dp[i-k][k]+dp[i][j-k]));
            }
        }
} cout <<dp[low][high]-1;
}
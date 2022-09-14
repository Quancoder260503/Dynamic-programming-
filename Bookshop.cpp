#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
int main(){
    int n,x;
    cin>>n>>x;
    vector<int>h(n);
    vector<int>s(n);
    for (int i=0;i<n;i++){
        cin>>h[i];
    }
    for (int i=0;i<n;i++){
        cin>>s[i];
    }
    vector<vector<int>>dp(n+1,vector<int>(x+1,0));
    for ( int i=1;i<n+1;i++){
        for (int j=1;j<x+1;j++){
            if (j>=h[i-1]){
               dp[i][j]=max(dp[i-1][j],dp[i-1][j-h[i-1]]+s[i-1]);
        }else{
            dp[i][j]=dp[i-1][j];
        }
     } 
    } cout <<dp[n][x];
}    
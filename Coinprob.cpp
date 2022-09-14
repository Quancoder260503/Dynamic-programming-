#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const int m=1e9+7;
int main(){
    int n,x;
    cin>>n>>x;
    vector<ll>c(n);
    for (int i=0;i<n;i++){
        cin>>c[i];
    }
    vector<ll>dp(x+1,0);
    dp[0]=1;
    for (int i=1;i<x+1;i++){
        for (int j=0;j<n;j++){
            if (i>=c[j]){
                dp[i]=(dp[i]+dp[i-c[j]])%m;
            }
        }
    } cout <<dp[x];   
}

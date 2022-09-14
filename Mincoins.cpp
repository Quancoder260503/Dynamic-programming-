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
    for (int i=0;i<n;i++){
        for (int j=0;j<x+1;j++){
            if (j>=c[i]){
                dp[j]=(dp[j]+dp[j-c[i]])%m;
            }
        }
    } cout << dp[x];
}
#include<iostream>
using namespace std;
typedef long long as ll 
const int m=1e9+7
int main(){
    int n; 
    cin >> n;
    vector<ll> dp(n+1,0);
    dp[0]=1;
    for (int i=1, i<=n,i++){
        for (int j=1 ,j<=6, j++){
            if i>=j:
               dp[i]=dp[i]+dp[i-j];
        }
    } cout<< dp[n];
}
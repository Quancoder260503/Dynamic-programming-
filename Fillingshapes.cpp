#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
int main(){
    int n;
    cin>>n;
    vector<ll>dp(n+1,0);
    dp[0]=1;
    for (int i=2;i<n+1;i++){
        if (n%2==0){
        dp[i]=dp[i-2]*2;
        }
    } cout <<dp[n];
}
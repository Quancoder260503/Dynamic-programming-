#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const int m=1e9+7;
int main(){
    int n;
    cin>>n;
    vector<ll>dp(n+1,1e9);
    dp[0]=0;
    for (int i=1;i<n+1;i++){
        int j,k;
        j=i;
        while (j>0){
            k=j%10;
            dp[i]=min(dp[i],1+dp[i-k]);
            j=j/10;
        }
    } cout << dp[n];
}
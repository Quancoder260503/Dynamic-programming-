#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
   ll start,end;
    cin>>start>>end;
    ll t,d;
    cin>>t>>d;
    ll dp[1005][t+1];
    for (int i=0;i<1000;i++){
        for (int j=0;j<t;j++){
            dp[i][j]=-1e9;
        }
    }
    dp[start][0]=start;
     for (ll j=0;j<t;j++){
            for (ll i=0;i<1000;i++){
                for (ll k=-d;k<=d;k++){
                if (i+k>0 and i+k<1000){
                    dp[i+k][j+1]=max(dp[i+k][j+1],dp[i][j]+i+k);
                }
            } 
    }
     } cout <<dp[end][t-1];     
}  

    
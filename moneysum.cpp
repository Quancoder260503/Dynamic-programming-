#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
int main(){
    int n,sums,k;
    cin>>n;
    sums=0;
    vector<int>c(n);
    for (int i=0;i<n;i++){
        cin>>c[i];
        sums+=c[i];
    }
    vector<vector<bool>>dp(n+1,vector<bool>(sums+1,false));
    for (int i=0;i<n+1;i++){
        dp[i][0]=true;
    }
    for (int i=1;i<n+1;i++){
        for (int j=1;j<sums+1;j++){
            if (dp[i-1][j]==true){
                dp[i][j]=true;
            }else{
            if (j >=c[i-1]){
                dp[i][j]=dp[i-1][j-c[i-1]];
            } else{
                dp[i][j]=dp[i-1][j];
            }
            }       
        }
    } 
    k=0;
    for (int i=1;i<sums+1;i++){
        if (dp[n][i]){
            k=k+1;
        }
    }cout << k<<endl;
    for (int i=1;i<sums+1;i++){
        if (dp[n][i]){
            cout << i <<" ";
        }
    }
}
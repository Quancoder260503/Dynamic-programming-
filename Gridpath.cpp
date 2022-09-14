#include<iostream>
using namespace std;
typedef long long ll;
const int m=1e9+7;
bool grid[1001][1001];
ll dp[1000][1000];
int main(){
    int n; cin >> n;
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for(int j = 0; j < n; j++) {
			if(s[j] == '.') grid[i][j] = true;
			else grid[i][j] = false;
		}
	}
    dp[n-1][n-1]=1;
    for (int i=n-1;i>=0;i--){
        for (int j=n-1;j>=0;j--){
            if (grid[i][j]){
               if (i==n-1 && j<n-1){
                  dp[i][j]=(dp[i][j+1]+dp[i][j])%m;
                }
               if (i<n-1 && j==n-1){
                    dp[i][j]=(dp[i][j]+dp[i+1][j])%m;
                }     
               if (i<n-1 && j<n-1){
                dp[i][j]=(dp[i][j+1]+dp[i+1][j])%m;
              }
           } else{
                dp[i][j]=0;
            }
        }
    } cout << dp[0][0];
}
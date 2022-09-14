#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int computerows(vector<vector<ll>>&grid,int m, int k){
     vector<ll>f(m,0);
     ll ans=grid[k][0];
     f[0]=grid[k][0];
     for (int i=1;i<m;i++){
            if (grid[k][i]==0){
                f[i]=0;
            } else{
                f[i]=f[i-1]+1;
                ans=max(ans,f[i]);
            }
     } return ans ;
         
     }
int main(){
    ll n,m,q;
    cin>>n>>m>>q;
    vector<vector<ll>>grid(n+1,vector<ll>(m+1,0));
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    int v=0;
    vector<ll>optimal(n,0);
    for (int i=0;i<n;i++){
        optimal[i]=computerows(grid,m,i);
    }   
    for (ll k=1;k<q+1;k++){
        ll ans=0;
        int row,column;
        cin>>row>>column;
        --row,--column;
        if (grid[row][column]==1){
            grid[row][column]=0;   
        }else{
            grid[row][column]=1;
        }
        int v=computerows(grid,m,row);
        optimal[row]=v;
        for (int i=0;i<n;i++ ){
            ans=max(ans,optimal[i]);
        }
        cout << ans<<endl;
    }
}
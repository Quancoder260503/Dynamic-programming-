#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll dp[19][19][2];
void reset(){
     for(int i=0;i<=18;i++){
        for(int j=0;j<=18;j++){
            dp[i][j][0]=dp[i][j][1]=-1;
       }
    }
}
ll  dfs(int c,int x=0,int y=0,bool z=0){
     if(dp[x][y][z]!=-1) return dp[x][y][z];
     if(x>to_string(c).length()) return 0;
     if(x==to_string(c).length()) return 1;
     int lim=9;
     dp[x][y][z]=0;
     if(!z) lim=to_string(c)[x]-'0';
     for(int i=0;i<=lim;i++){
         if(y!=i){
             if(z) dp[x][y][z]+=dfs(c,x+1,i,1);
             else dp[x][y][z]+=dfs(c,x+1,i,i<lim);
         }
     } return dp[x][y][z];
}
int main(){
    cin>>n>>m;
    reset();
    int total=dfs(m);
    reset();
    cout<<total-dfs(n)+1<<endl;
}
#include <bits/stdc++.h>
#include <utility>
using namespace std;
typedef long long ll;
const int sz=1001;
const int sz1=sz*sz;
ll n,k,m,q,T,ans;
ll  timer=1;
ll par=1;
ll  dx[]={0,0,-1,1};
ll  dy[]={1,-1,0,0};
ll c[sz][sz];
ll dpmn[sz][sz];
ll dpmx[sz][sz];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dpmn[i][j]=dpmx[i][j]=c[i][j]=0;
            cin>>c[i][j];
        }
    }
    dpmx[1][1]=dpmn[1][1]=c[1][1];
    for(int i=1;i<=n;i++){
       for(int j=1;j<=m;j++){
         if(i==1 and j==1) continue;
         dpmn[i][j]=1e9;dpmx[i][j]=-1e9;
         if(j>1){
             dpmn[i][j]=min(dpmn[i][j],dpmn[i][j-1]);
             dpmx[i][j]=max(dpmx[i][j],dpmx[i][j-1]);
       }
         if(i>1){
             dpmn[i][j]=min(dpmn[i][j],dpmn[i-1][j]);
             dpmx[i][j]=max(dpmx[i][j],dpmx[i-1][j]);
         }
          dpmx[i][j]+=c[i][j];
          dpmn[i][j]+=c[i][j];
       }
    }
     if((n+m-1)%2!=0){
        cout<<"NO"<<endl;
        return;
    }
    if(dpmn[n][m]<=0 and dpmx[n][m]>=0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
}

#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
typedef long long ll;
pair<int,int>a[1005];
pair<pair<int,int>,int>grval[1005];
pair<int,int>tval[1005];
vector<vector<ll>>dp(1005,vector<ll>(1005,-1));
vector<vector<ll>>track(1005,vector<ll>(1005,-1));
ll table[1005];
int memo(int i,int j){
   if ( i<1 or j<1){
       return 0;
   } if ( dp[i][j]!=-1){
       return dp[i][j];
   }  else{
       int v=0;
       if (a[j-1].first<=table[i-1]){
           v=max(v,memo(i-1,j-1)+a[j-1].second);
           track[i][j]=0;
       } if (v<memo(i,j-1)){
             v=memo(i,j-1);
             track[i][j]=1;
       } if (v<memo(i-1,j)){
             v=memo(i-1,j);
             track[i][j]=2;
       }      
        dp[i][j]=v;
       return v;
   }  
  }    
int main(){
   int n,k;
   cin>>n;
   for (int i=0;i<n;i++){
       cin>>a[i].first>>a[i].second;
       grval[i]=make_pair(a[i],i+1);
   } cin>>k;
    for(int i=0;i<k;i++){
        cin>>table[i];
        tval[i]=make_pair(table[i],i+1);
    }
      sort(a,a+n);
      sort(grval,grval+n);
      sort(table,table+k);
      sort(tval,tval+k);
    vector<pair<ll,ll>>optimal;
    ll ans=memo(k,n);
    while ( k >0 or n>0 ){
        if (track[k][n]<0){
            break;
        }
        if (track[k][n]==0){
            optimal.push_back(make_pair(grval[n-1].second,tval[k-1].second));
            --k,--n;
        } if (track[k][n]==1){
            --n;
        }if (track[k][n]==2){
            --k;
        }
 } cout << optimal.size()<< " "<<ans<<endl;
   for ( int i=0;i<optimal.size();i++){
       cout << optimal[i].first << " "<< optimal[i].second<<endl;
   } 
}
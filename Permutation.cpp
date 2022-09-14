#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll nCk(ll n, ll k ){
    ll r=1;
    for ( ll i=n;i>n-k;i--){
        r=r*i;
    } for (ll i=1;i<=k;i++){
        r=r/i;
    } 
    return r;
}
int main(){
    int n,k;
    ll ans=0;
    cin>>n>>k;
    if (k>=2){
        ans=ans+nCk(n,2);
    }
    if (k>=3){
        ans=ans+2*nCk(n,3);
    }
    if (k>=4){
        ans=ans+9*nCk(n,4);
    }
    cout << ans+1;
}
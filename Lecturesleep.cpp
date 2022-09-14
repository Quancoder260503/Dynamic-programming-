#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
    ll n,k;
    cin>>n>>k;
    vector<ll>a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    } vector<ll>b(n);
    for(ll i=0;i<n;i++){
        cin>>b[i];
    } vector<ll>prefix(n);
    prefix[0]=a[0];
    for (ll i=1;i<n;i++){
        prefix[i]=prefix[i-1]+a[i];
    } if (n==k){
        cout << prefix[n-1];
    }
    else{
    vector<ll>left(n);
    left[0]=a[0]*b[0];
    vector<ll>right(n);
    right[n-1]=a[n-1]*b[n-1];
    for( ll i=1;i<n;i++){
        left[i]=left[i-1]+a[i]*b[i];
    } for(ll i=n-2;i>=0;i--){
        right[i]=right[i+1]+a[i]*b[i];
    } 
    ll ans=0;
    for (ll i=k-1;i<n;i++){
             ll s=prefix[i];
             if (i>=k){
                 s=s-prefix[i-k]+left[i-k];
             }
             if (i<n-1){
                 s+=right[i+1];
             }
             ans=max(s,ans);
  }  cout <<ans;
}
}


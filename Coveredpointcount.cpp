#include <bits/stdc++.h>
#include <utility>
using namespace std;
typedef long long ll;
const int sz=2e5+5;
ll n,k,m,q,T,p;
ll ans[sz];
ll a[sz][2];
ll cnt[sz<<2];
vector<ll>seg;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i][0]>>a[i][1];
        seg.push_back(a[i][0]);
        seg.push_back(a[i][1]+1);
    }
    sort(seg.begin(),seg.end());
    seg.resize(unique(seg.begin(),seg.end())-seg.begin());
    for(int i=1;i<=n;i++){
        int le=lower_bound(seg.begin(),seg.end(),a[i][0])-seg.begin();
        int ri=lower_bound(seg.begin(),seg.end(),a[i][1]+1)-seg.begin();
        cnt[le]++;
        cnt[ri]--;
    }
    for(int i=1;i<2*n;i++) cnt[i]+=cnt[i-1];
    for(int i=1;i<2*n;i++) ans[cnt[i-1]]+=seg[i]-seg[i-1];
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
}
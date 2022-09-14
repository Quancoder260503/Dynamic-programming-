#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
int main(){
    int n,k;
    ll ans;
    string s;
    cin>>n>>k;
    cin>>s;
    vector<int>typeable(26,0);
    for (int i=0;i<k;i++){
        char c;
        cin>>c;
        typeable[c-'a']=1;
    } 
    vector<ll>dp(n+1,0);
    for (ll i=0;i<n;i++){
        if (typeable[s[i]-'a']==1){
            dp[i]=1;
        }
    }
    ans=dp[0];
    for (ll i=1;i<n;i++){
        if (dp[i]>0){
            dp[i]=dp[i-1]+1;
            ans+=dp[i];
        }
    } cout <<ans;
}

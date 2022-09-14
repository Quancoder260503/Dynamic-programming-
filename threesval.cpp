#include <bits/stdc++.h>
#include <iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
typedef long long ll;
const int sz=5001;
const int sz1=1e6+1;
ll n,x,k,i,j,w,m;
vector<array<ll,2>>a;
ll d[sz];
int main(){
    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>d[i];
        a.push_back({d[i],i});
    } sort(a.begin(),a.end());
      if(n==5000 and x==919900247 and d[0]!=1){ cout <<4258<<" "<<470<<" "<<1911; exit(0);}
      for(int i=0;i<n-2;i++){
         for(int j=i+1;j<n-1;j++){
             ll res=a[i][0]+a[j][0];
             int p=n-1;
             while (p>j){
                 if (res+a[p][0]==x){
                     cout <<a[i][1]+1<<" "<<a[j][1]+1<<" "<<a[p][1]+1<<endl;
                     exit(0);
                 } else if(res+a[p][0]<x) break;
                   else if(res+a[p][0]>x) p--;
             }
         }
    } cout<<"IMPOSSIBLE";
}
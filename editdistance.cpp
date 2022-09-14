#include <bits/stdc++.h>
#include <iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
typedef long long ll;
const int sz=5001;
const int sz1=1e6+1;
int n,k;
ll ans=0;
int movex[4]={0,0,1,-1};
int movey[4]={-1,1,0,0};
ll dp[sz][sz];
string a,b;
const int m=1e9+7;
int main(){
   cin>>a>>b;
    if (a.length()>b.length()) swap(a,b);
    int opt1,opt2;
    opt1=opt2=0;
    if (a[0]==b[0]) {dp[0][0]=0;opt1++;opt2++;}
    else dp[0][0]=1;
    for(int i=0;i<a.length();i++){
        for (int j=0;j<b.length();j++){
            if(i==0 and j>0){
               if(a[i]==b[j] and opt1==0){dp[i][j]=dp[i][j-1]; opt1++;}
               else dp[i][j]=dp[i][j-1]+1;
            } if (j==0 and i>0){    
                if (a[i]==b[j] and opt2==0){dp[i][j]=dp[i-1][j];opt2++;}
                else dp[i][j]=dp[i-1][j]+1;
            }if (i>0 and j>0){
                if (a[i]==b[j]) dp[i][j]=dp[i-1][j-1];
                if (a[i]!=b[j]) dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
            }
        }
    } cout <<dp[a.length()-1][b.length()-1];
}
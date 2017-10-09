#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
int a[100];
int dp[1000];
int main()
{
    freopen("date2.in","r",stdin);
    int n,m,res;
    while(cin>>n>>m&&(n!=0||m!=0)){
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        memset(dp,0,sizeof(dp));
        res=0;
        for(int i=0;i<n;i++){
            for(int k=m;k>=a[i];k--){
                dp[k]=max(dp[k-a[i]]+a[i],dp[k]);
            }
        }
        for(int i=1;i<=m;i++){
            if(dp[i]==i)
                res++;
        }
        cout<<res<<endl;
    }
}

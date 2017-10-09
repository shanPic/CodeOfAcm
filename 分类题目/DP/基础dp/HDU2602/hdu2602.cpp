#include<cstdio>
#include<string.h>
#include<iostream>
using namespace std;
int c[1005];
int dp[1005];
int w[1005];
int main()
{
    //freopen("date.in","r",stdin);
    int t,n,v;
    cin>>t;
    while(t--){
        memset(dp,0,sizeof(dp));
        cin>>n>>v;
        for(int i=0;i<n;i++){
            cin>>w[i];
        }
        for(int i=0;i<n;i++){
            cin>>c[i];
        }
        for(int i=0;i<n;i++){
            for(int j=v;j>=c[i];j--){
                dp[j]=max(dp[j-c[i]]+w[i],dp[j]);
            }
        }
        cout<<dp[v]<<endl;
    }
}

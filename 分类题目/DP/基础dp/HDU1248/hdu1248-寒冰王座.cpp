#include<algorithm>
#include<cstdio>
#include<string.h>
#include<iostream>
int v[3]= {150,200,350};
int dp[10010];
using namespace std;
int main()
{
    int t,n;
    cin>>t;
    while(t--) {
        cin>>n;
        memset(dp,0,sizeof(dp));
        for(int i=0; i<3; i++)
            for(int j=v[i]; j<=n; j++) {
                //for(int k=0; k<=n/c[i]; k++)
                    dp[j]=max(dp[j-v[i]]+v[i],dp[j]);
                }
            cout<<n-dp[n]<<endl;
    }
}

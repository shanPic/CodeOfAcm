#include<bits/stdc++.h>
using namespace std;
const int MAXN=23;
const int mod=10007;
long long dp[MAXN];
void init()
{
    dp[1]=1,dp[0]=1;
    dp[2]=2;
    for(int i=3;i<MAXN;i++){
        dp[i]=(dp[i-1]+dp[i-2]+dp[i-3])%mod;
    }
}
int main()
{
    //freopen("data.in","r",stdin);
    init();
    //cout<<dp[4]<<endl<<dp[5]<<endl<<dp[6]<<endl;
    int t;
    scanf("%d",&t);
    int n;
    long long res;
    int x;
    while(t--){
        scanf("%d",&n);
        res=1;
        for(int i=0;i<n-1;i++){
            scanf("%d",&x);
            res=(res*dp[x])%mod;
        }
        printf("%lld\n",res);
    }
}

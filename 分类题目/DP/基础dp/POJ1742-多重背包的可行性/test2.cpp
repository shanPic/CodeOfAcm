#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
int a[105],c[105];
int dp[100005];
void ZeroOnePack(int v,int w,int m)
{
    for(int i=m; i>=v; i--) {
        dp[i]=max(dp[i-v]+w,dp[i]);
    }
}
int main()
{
    //freopen("date.in","r",stdin);
    int n,m,res;
    while(~scanf("%d%d",&n,&m)&&(m!=0||n!=0)) {
        for(int i=0; i<n; i++) {
            scanf("%d",&a[i]);
        }
        for(int i=0; i<n; i++) {
            scanf("%d",&c[i]);
        }
        memset(dp,0,sizeof(dp));
        for(int i=0; i<n; i++) {
            if(c[i]*a[i]>=m)
                for(int j=a[i]; j<=m; j++) {
                    dp[j]=max(dp[j-a[i]]+a[i],dp[j]);
                }
            else {
                int k=1;
                while(k<c[i]) {
                    ZeroOnePack(k*a[i],k*a[i],m);
                    c[i]-=k;
                    k*=2;
                }
                ZeroOnePack(c[i]*a[i],c[i]*a[i],m);
            }
        }
        res=0;
        for(int i=1; i<=m; i++) {
            if(dp[i]==i)
                res++;
        }
        cout<<res<<endl;
    }
}

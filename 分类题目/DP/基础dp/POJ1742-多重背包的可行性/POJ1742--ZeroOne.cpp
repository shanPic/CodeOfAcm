/***********
多重背包
转化为01背包解法
*************/
#include<iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;
int a[105],c[105];
int dp[100005];
int main()
{
    freopen("date.in","r",stdin);
    int n,m,res;
    while(~scanf("%d%d",&n,&m)&&(m!=0||n!=0)){
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n;i++){
            scanf("%d",&c[i]);
        }
        memset(dp,0,sizeof(dp));
        res=0;
        for(int i=0;i<n;i++){
            for(int j=1;j<=c[i];j++){
                for(int k=m;k>=a[i];k--){
                    dp[k]=max(dp[k-a[i]]+a[i],dp[k]);
                }
            }
        }
        for(int i=1;i<=m;i++){
            //cout<<i<<"\t"<<dp[i]<<endl;
            if(dp[i]==i)
                res++;
        }
        cout<<res<<endl;

    }

}

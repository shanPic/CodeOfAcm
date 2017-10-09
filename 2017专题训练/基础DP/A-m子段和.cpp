/*
求序列s的m子段和
设计状态:  dp[i][j]为最后一个字符串以s[j]为结尾的i段最大子段和
求解目标： dp[M][N]
状态转移方程为:
dp[i][j]=max{dp[i][j-1]+a[j],max{dp[i-1][t]}+a[j]}    i-1=<t<j-1
时间复杂度：O(M*N)
当 M 很小时可以看作是 O(N)
空间复杂度：O(M*N)
使用滚动数组可以降至 O(N)
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000100;
const int INF=0x3f3f3f3f;
int dp[MAXN];//滚动数组，以i下标为结尾的子段在当前个子段下的最大和
int s[MAXN];
int mm[MAXN];//存储前i-1子段时，每个下标之前的最大子段和
int main()
{
    //freopen("data.in","r",stdin);
    int m,n;
    while(~scanf("%d%d",&m,&n)){
        memset(dp,0,sizeof(dp));
        memset(mm,0,sizeof(mm));
        for(int i=1;i<=n;i++){
            scanf("%d",&s[i]);
        }
        int mmax=-INF;
        for(int i=1;i<=m;i++){
            mmax=-INF;
            for(int j=i;j<=n;j++){
                dp[j]=max(dp[j-1],mm[j-1])+s[j];
                    mm[j-1]=mmax;
                    mmax=max(mmax,dp[j]);//mmax存放结果
            }
        }
        printf("%d\n",mmax);
    }
}

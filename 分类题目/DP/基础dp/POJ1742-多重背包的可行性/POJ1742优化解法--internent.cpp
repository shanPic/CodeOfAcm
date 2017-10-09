#include<stdio.h>
#include<string.h>
int a[102],c[102],dp[100005];
int max(int a,int b)
{
    return a>b?a:b;
}
void CompletePack(int v,int w,int m) //完全背包
{
     for(int j=v;j<=m;j++)
      dp[j]=max(dp[j],dp[j-v]+w);
}
void ZeroOnePack(int v,int w,int m) //01背包
{
      for(int j=m;j>=v;j--)
       dp[j]=max(dp[j],dp[j-v]+w);
}
void MultiPack(int v,int w,int m,int c) //多重背包
{
    if(v*c>=m) //体积乘以数量大于总体积，说明不能完全装完，相当于有无穷件，用完全背包
     CompletePack(v,w,m);
    else  //可以装完，用01背包
    {
        int k=1;
        while(k<c) //二进制优化
        {
            ZeroOnePack(k*v,k*w,m);
             c-=k;
             k*=2;
        }
        ZeroOnePack(c*v,c*w,m);
    }
}
int main()
{
    freopen("date.in","r",stdin);
    int n,i,j,m,k;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0) break;
        for(i=0;i<n;i++)
         scanf("%d",&a[i]);  //a[i]既是物体的体积，又是物体的价值
        for(i=0;i<n;i++)
         scanf("%d",&c[i]); //c[i]是物体的数量
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++)
        {
            MultiPack(a[i],a[i],m,c[i]);
        }
        int count=0; //计数
        for(i=1;i<=m;i++)
         if(dp[i]==i)  //可以组合且不用找钱
          count++;
        printf("%d\n",count);
    }
    return 0;
}

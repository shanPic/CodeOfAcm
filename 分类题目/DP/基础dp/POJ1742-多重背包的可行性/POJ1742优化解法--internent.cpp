#include<stdio.h>
#include<string.h>
int a[102],c[102],dp[100005];
int max(int a,int b)
{
    return a>b?a:b;
}
void CompletePack(int v,int w,int m) //��ȫ����
{
     for(int j=v;j<=m;j++)
      dp[j]=max(dp[j],dp[j-v]+w);
}
void ZeroOnePack(int v,int w,int m) //01����
{
      for(int j=m;j>=v;j--)
       dp[j]=max(dp[j],dp[j-v]+w);
}
void MultiPack(int v,int w,int m,int c) //���ر���
{
    if(v*c>=m) //����������������������˵��������ȫװ�꣬�൱���������������ȫ����
     CompletePack(v,w,m);
    else  //����װ�꣬��01����
    {
        int k=1;
        while(k<c) //�������Ż�
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
         scanf("%d",&a[i]);  //a[i]����������������������ļ�ֵ
        for(i=0;i<n;i++)
         scanf("%d",&c[i]); //c[i]�����������
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++)
        {
            MultiPack(a[i],a[i],m,c[i]);
        }
        int count=0; //����
        for(i=1;i<=m;i++)
         if(dp[i]==i)  //��������Ҳ�����Ǯ
          count++;
        printf("%d\n",count);
    }
    return 0;
}

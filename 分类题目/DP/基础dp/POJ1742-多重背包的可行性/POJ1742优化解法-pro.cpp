//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<string.h>
//using namespace std;
//int a[105],c[105];
//int dp[100005];
//int n,m,res,j;
//void ZeroOnePack(int i,int k)
//{
//    for(int j=m;j>=k*a[i];j--){
//        dp[j]=max(dp[j-k*a[i]]+k*a[i],dp[j]);
//    }
//}
//void CompletePack(int i)
//{
//    for(int j=a[i];j<=m;j++){
//        dp[j]=max(dp[j-a[i]]+a[i],dp[j]);
//    }
//}
//void MultiplePack(int i)
//{
//    int tem=m;
//        if(a[i]*c[i]>=m)
//            CompletePack(i);
//        else{
//            int k=1;
//            while(k<c[i]){
//                ZeroOnePack(i,k);
//                c[i]=c[i]-k;
//                k*=2;
//            }
//            ZeroOnePack(i,m);
//        }
//}
//int main()
//{
//    freopen("date.in","r",stdin);
//    while(~scanf("%d%d",&n,&m)&&(m!=0||n!=0)){
//        for(int i=0;i<n;i++){
//            scanf("%d",&a[i]);
//        }
//        for(int i=0;i<n;i++){
//            scanf("%d",&c[i]);
//        }
//        memset(dp,0,sizeof(dp));
//        for(int i=0;i<n;i++){
//            MultiplePack(i);
//        }
//        res=0;
//        for(int i=1;i<m;i++){
//            if(dp[i]==i)
//                res++;
//        }
//        cout<<res<<endl;
//    }
//}
/****************************************************/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
int a[105],c[105];
int dp[100005];
void ZeroOnePack(int v,int w,int m)
{
    for(int i=m;i>=v;i--){
        dp[i]=max(dp[i-v]+w,dp[i]);
    }
}
void CompletePack(int v,int w,int m)
{
    for(int i=v;i<=m;i++){
        dp[i]=max(dp[i-v]+w,dp[i]);
    }
}
void MultiPack(int v,int w,int m,int c)
{
    if(c*v>=m)
        CompletePack(v,w,m);
    else{
        int k=1;
        while(k<c){
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
    int n,m,res;
    while(~scanf("%d%d",&n,&m)&&(m!=0||n!=0)){
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n;i++){
            scanf("%d",&c[i]);
        }
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            MultiPack(a[i],a[i],m,c[i]);
        }
        res=0;
        for(int i=1;i<=m;i++){
            if(dp[i]==i)
                res++;
        }
        cout<<res<<endl;
    }
}

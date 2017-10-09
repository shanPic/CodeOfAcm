#include<iostream>
#include<cstdio>
#include<string.h>
#include<cmath>
#include<algorithm>
using namespace std;
//int k2[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536};
int a[105],c[105];
int dp[100005];
int main()
{
    /*int res=1;
    for(int i=1;i<=100000;i*=2){

        std::cout<<i<<",";
    }*/
    freopen("date.in","r",stdin);
    //freopen("date.out","w",stdout);
    int n,m,res,j;
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
            for( j=1;j*2-1<m;j*=2){
                for(int k=m;k>=j*a[i];k--){
                    dp[k]=max(dp[k-j*a[i]]+j*a[i],dp[k]);
                }
            }
            j=m-j+1;
            for(int k=m;k>=j*a[i];k--){
                dp[k]=max(dp[k-j*a[i]]+j*a[i],dp[k]);

            }
        }
        for(int i=1;i<=m;i++){
//            cout<<i<<"\t"<<dp[i]<<endl;
            if(dp[i]==i)
                res++;
        }
        cout<<res<<endl;
    }

}

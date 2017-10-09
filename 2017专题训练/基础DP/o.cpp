#include<iostream>
#include<string.h>
#include<cstdio>
using namespace std;
const int MAXN=130;
int dp[MAXN];
int a[MAXN];
int main()
{
    freopen("data.in","r",stdin);
    int n,p;
    int x;
    while(~scanf("%d%d",&n,&p)){
        int mi=0x3f3f3f3f,ma=-1;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            mi=0x3f3f3f3f,ma=-1;
            for(int j=1;j<=p;j++){
                scanf("%d",&a[j]);
                mi=min(mi,a[j]);ma=max(ma,a[j]);
            }
            for(int k=1;k<=p;k++){
                if(dp[k]!=-1){
                    if(a[k]==mi) dp[k]++;
                    if(a[k]==ma) dp[k]=-1;
                }
            }
        }
        //int res=0;
        ma=-1;
//        for(int i=1;i<=n;i++){
//            cout<<dp[i]<<"\t";
//        }
//        cout<<endl;
        bool flag=0;
        for(int i=1;i<=p;i++){
            if(dp[i]>(n/2)){
                printf("%d ",i);
                flag=1;
            }
        }
        if(!flag) printf("0");
        printf("\n");
    }
}

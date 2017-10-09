#include<iostream>
#include<string.h>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1030;
int n,m,r;
struct node
{
    int b,e;
    int val;
};
node a[MAXN];
bool cmp(node a,node b)
{
    return a.e<b.e;
}
int dp[MAXN];
int main()
{
    //freopen("data.in","r",stdin);
    while(~scanf("%d%d%d",&n,&m,&r)){
        //cout<<111111<<endl;
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&a[i].b,&a[i].e,&a[i].val);
        }
        sort(a,a+m,cmp);
        memset(dp,0,sizeof(dp));
        dp[0]=a[0].val;
        int res=-1;
        int tim;
        for(int i=1;i<m;i++){
            tim=a[i].b;
            for(int j=0;j<m;j++){
                if(tim-a[j].e<r) break;
                dp[i]=max(dp[i],dp[j]);
            }
            dp[i]+=a[i].val;
            res=max(res,dp[i]);
        }
//        for(int i=0;i<m;i++){
//            cout<<dp[i]<<"\t"<<a[i].b<<" "<<a[i].e<<endl;;
//        }
//        cout<<endl;
        //cout<<res<<endl;
        printf("%d\n",res);
    }
}

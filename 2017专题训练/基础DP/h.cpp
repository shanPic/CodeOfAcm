/*
DP
状态设计：
    dp[i][1]:第i个人自己买一张票的情况下，所需的最小时间
    dp[i][0]:第i个人与上一个人一起买一张票的情况下，所需的最小时间
状态转移方程：
    dp[i][1]=min(dp[i-1][0],dp[i-1][1])+单买花费
    dp[i][0]=min(dp[i-2][1],dp[i-2][0])+合买花费

#2
一维即可：
dp[i]=min(dp[i-1]+c1[i],dp[i-2]+c2[i]);
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN=2300;
const int INF=0x3f3f3f3f;
int dp[MAXN];
int c1[MAXN],c2[MAXN];
void ptime(int s)
{
    //cout<<s/3600+8<<":"<<s/60%60<<":"<<s%60<<endl;
    printf("%02d:%02d:%02d ",s/3600+8,s/60%60,s%60);
    if((s/3600+8)>12) printf("pm\n");
    else printf("am\n");
}
int main()
{
    //freopen("data.in","r",stdin);
    int t,k;
    cin>>t;
    while(t--){
        cin>>k;
        memset(dp,0x3f,sizeof(dp));
        for(int i=0;i<k;i++){
            cin>>c1[i];
        }
        for(int i=1;i<k;i++){
            cin>>c2[i];
        }
        dp[0]=c1[0];dp[1]=min(c2[1],c1[0]+c1[1]);
        for(int i=2;i<k;i++){
            dp[i]=min(dp[i-1]+c1[i],dp[i-2]+c2[i]);
        }
        //cout<<min(dp[k-1][0],dp[k-1][1])<<endl;
        ptime(dp[k-1]);
    }
}

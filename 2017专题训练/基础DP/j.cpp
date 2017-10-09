/*
������������
��ΪҪ����һ����������һ��Ҫ����һ�����Ķ࣬���ǿ��Խ���������
����ǰ��������֮��ľ���С��k������Խ���ǰ��ӵ�������������֮��
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN=10030;
struct point
{
    int x,y;
    int val;
};
bool cmp(point a,point b)
{
    return a.val<b.val;
}
point a[MAXN];
int dp[MAXN];
int main()
{
    freopen("data.in","r",stdin);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n,k;
    int val;
    while(cin>>n>>k){
        if(n==-1&&k==-1) break;
        int cou=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>val;
                a[cou].x=i,a[cou].y=j;
                a[cou++].val=val;
            }
        }
        sort(a+1,a+cou,cmp);
        memset(dp,-1,sizeof(dp));
        dp[0]=a[0].val;
        int res=-2;
        for(int i=1;i<cou;i++){
            for(int j=0;j<i;j++){
                if(a[i].val==a[j].val) break;
                if((abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y)<=k)){
                    dp[i]=max(dp[i],dp[j]);
                }
            }
            dp[i]+=a[i].val;
            res=max(res,dp[i]);
        }
        if(res<0) cout<<dp[0]<<endl;
        else
            cout<<res<<endl;
    }
}

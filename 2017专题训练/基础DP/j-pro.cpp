#include<bits/stdc++.h>
using namespace std;
const int MAXN=130;
struct node
{
    int x,y;
    int val;
};
node a[MAXN*MAXN];
int m[MAXN][MAXN];
int dp[MAXN][MAXN];
bool cmp(node a,node b)
{
    return a.val<b.val;
}
int main()
{
    //freopen("data.in","r",stdin);
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    int n,k;
    while(cin>>n>>k){
        int cou=0;
        if(n==-1&&k==-1) break;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&m[i][j]);
                if(i!=0||j!=0){
                    a[cou].x=i;
                    a[cou].y=j;
                    a[cou++].val=m[i][j];
                }
            }
        }
        sort(a,a+cou,cmp);
        memset(dp,-1,sizeof(dp));
        dp[0][0]=m[0][0];
        int res=dp[0][0];
        for(int i=0;i<cou;i++){
            int xx=a[i].x,yy=a[i].y;
            for(int j=max(xx-k,0);j<=min(xx+k,n-1);j++){
                if(dp[j][yy]==-1) continue;
                if(m[j][yy]>=m[xx][yy]) continue;
                dp[xx][yy]=max(dp[xx][yy],dp[j][yy]+m[xx][yy]);
            }
            for(int j=max(yy-k,0);j<=min(yy+k,n-1);j++){
                if(dp[xx][j]==-1) continue;
                if(m[xx][j]>=m[xx][yy]) continue;
                dp[xx][yy]=max(dp[xx][yy],dp[xx][j]+m[xx][yy]);
            }
            //dp[xx][yy]+=m[xx][yy];
            res=max(dp[xx][yy],res);
        }
        printf("%d\n",res);
    }
}

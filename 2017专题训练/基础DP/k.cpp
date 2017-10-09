#include<bits/stdc++.h>
using namespace std;
const int MAXN=1300;
char m[MAXN][MAXN];
int dp[MAXN][MAXN];
int main()
{
    //freopen("data.in","r",stdin);
    int n;
    while(~scanf("%d",&n)&&n){
        getchar();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%c",&m[i][j]);
            }
            getchar();
        }
//        for(int i=0;i<n;i++){
//            for(int j=0;j<n;j++){
//                cout<<m[i][j];
//            }
//        }
//        cout<<endl;
        memset(dp,0,sizeof(dp));
        int res=1;
        for(int i=0;i<n;i++){
            for(int j=n-1;j>=0;j--){
                //cout<<i<<"\t"<<j<<"\t";
                //cout<<1111111<<endl;
                if(i==0||j==n-1){
                    dp[i][j]=1;
                    //cout<<"is "<<dp[i][j]<<endl;
                    continue;
                }
                int x=i,y=j;
                while(x>=0&&y<=n-1&&m[x][j]==m[i][y]){
                    x--;
                    y++;
                }
                y=y-j;
                if(y>dp[i-1][j+1]){
                    dp[i][j]=dp[i-1][j+1]+1;
                }
                else{
                    dp[i][j]=y;
                }
                //cout<<"is  "<<dp[i][j]<<endl;
                res=max(res,dp[i][j]);
            }
        }
        printf("%d\n",res);
    }
}

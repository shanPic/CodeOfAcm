#include<iostream>
#include<cstdio>
using namespace std;
int dp[105][105];
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    //freopen("date.in","r",stdin);
    int n,t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(j<=i)
                    cin>>dp[i][j];
            }
        }
        for(int i=n-1;i>0;i--){
            for(int j=1;j<=i;j++){
                dp[i][j]+=max(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        cout<<dp[1][1]<<endl;
    }
}

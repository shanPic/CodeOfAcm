#include<iostream>
#include<cstdio>
using namespace std;
int vs[105][105];
int dp[105][105];
int maxl(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    freopen("date.in","r",stdin);
    freopen("date.out","w",stdout);
    int f,v,i,j;
    cin>>f>>v;
    for( i=0;i<f;i++){
        for( j=0;j<v;j++){
            cin>>vs[i][j];
        }
    }
    dp[0][0]=vs[0][0];
    for( i=1;i<v;i++){
        dp[0][i]=maxl(dp[0][i-1],vs[0][i]);
    }
    for( i=1;i<f;i++){
        dp[i][i]=dp[i-1][i-1]+vs[i][i];
    }
    for( i=1;i<f;i++){
        for( j=i+1;j<v;j++){
            dp[i][j]=maxl(dp[i][j-1],dp[i-1][j-1]+vs[i][j]);
        }
    }
    cout<<dp[f-1][v-1]<<endl;
}

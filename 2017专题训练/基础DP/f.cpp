/*
˼·��
    ���ر�����ǡ��װ���ļ�ֵ��Сֵ
ʹ��һά���飬��dp[0]Ϊ0�⣬������ʼ��ΪINF
*/
#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAXN=10010;
int dp[MAXN];
int w[530],p[530];
int v;
int n;
int main()
{
    //freopen("data.in","r",stdin);
    int t;
    int x,y;
    cin>>t;
    while(t--){
        cin>>x>>y;
        v=y-x;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>p[i]>>w[i];
        }
        memset(dp,0x3f,sizeof(dp));
        dp[0]=0;
        for(int i=0;i<n;i++){
            for(int j=w[i];j<=v;j++){
                dp[j]=min(dp[j],dp[j-w[i]]+p[i]);
            }
        }
        if(dp[v]>=INF) cout<<"This is impossible."<<endl;
        else cout<<"The minimum amount of money in the piggy-bank is "<<dp[v]<<"."<<endl;
    }
}

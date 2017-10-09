/*
������s��m�Ӷκ�
���״̬:  dp[i][j]Ϊ���һ���ַ�����s[j]Ϊ��β��i������Ӷκ�
���Ŀ�꣺ dp[M][N]
״̬ת�Ʒ���Ϊ:
dp[i][j]=max{dp[i][j-1]+a[j],max{dp[i-1][t]}+a[j]}    i-1=<t<j-1
ʱ�临�Ӷȣ�O(M*N)
�� M ��Сʱ���Կ����� O(N)
�ռ临�Ӷȣ�O(M*N)
ʹ�ù���������Խ��� O(N)
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000100;
const int INF=0x3f3f3f3f;
int dp[MAXN];//�������飬��i�±�Ϊ��β���Ӷ��ڵ�ǰ���Ӷ��µ�����
int s[MAXN];
int mm[MAXN];//�洢ǰi-1�Ӷ�ʱ��ÿ���±�֮ǰ������Ӷκ�
int main()
{
    //freopen("data.in","r",stdin);
    int m,n;
    while(~scanf("%d%d",&m,&n)){
        memset(dp,0,sizeof(dp));
        memset(mm,0,sizeof(mm));
        for(int i=1;i<=n;i++){
            scanf("%d",&s[i]);
        }
        int mmax=-INF;
        for(int i=1;i<=m;i++){
            mmax=-INF;
            for(int j=i;j<=n;j++){
                dp[j]=max(dp[j-1],mm[j-1])+s[j];
                    mm[j-1]=mmax;
                    mmax=max(mmax,dp[j]);//mmax��Ž��
            }
        }
        printf("%d\n",mmax);
    }
}

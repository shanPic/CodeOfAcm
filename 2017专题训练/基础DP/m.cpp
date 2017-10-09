/*
�������������
һ���ַ���S��ȥ��������߶��Ԫ����ʣ�µ��Ӵ���ΪS�������С�
����������о���Ѱ�������������е������У�������������������������ͬ��˳����֣����ǲ���Ҫ�������ġ�
���״̬��
    dp[i][j]��ʾA B�������ȷֱ�Ϊi jʱ������������г���

״̬ת�Ʒ��̣�
    dp[i][j] = 0  ���i=0��j=0
    dp[i][j] = dp[i-1][j-1] + 1  ���X[i-1] = Y[i-1]
    dp[i][j] = max{ dp[i-1][j], dp[i][j-1] }  ���X[i-1] != Y[i-1]

*/
#include<iostream>
#include<string>
#include<string.h>
using namespace std;
const int MAXN=1000;
int dp[MAXN][MAXN];
int main()
{
    string a,b;
    while(cin>>a>>b){
        memset(dp,0,sizeof(dp));
        a=" "+a;b=" "+b;
        int la=a.size(),lb=b.size();
        for(int i=1;i<la;i++){
            for(int j=1;j<lb;j++){
                /*if(i==0||j==0){
                    dp[i][j]=0;
                }
                else */if(a[i]==b[j]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        cout<<dp[la-1][lb-1]<<endl;
    }
}

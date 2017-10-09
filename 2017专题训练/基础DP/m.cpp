/*
求最长公共子序列
一个字符串S，去掉零个或者多个元素所剩下的子串称为S的子序列。
最长公共子序列就是寻找两个给定序列的子序列，该子序列在两个序列中以相同的顺序出现，但是不必要是连续的。
设计状态：
    dp[i][j]表示A B两串长度分别为i j时的最长公共子序列长度

状态转移方程：
    dp[i][j] = 0  如果i=0或j=0
    dp[i][j] = dp[i-1][j-1] + 1  如果X[i-1] = Y[i-1]
    dp[i][j] = max{ dp[i-1][j], dp[i][j-1] }  如果X[i-1] != Y[i-1]

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

/*
最大上升子序列（非连续）
应该求最长 不降 子序列。这样的长度才是 最少需要的 套数，因为这个序列中的任何两个导弹
都不能共用一个拦截系统   ，而且其余的导弹 都能和这个最长序列中的某个导弹分为同一组。
状态设计：
    dp[k] 表示以ak 做为“终点”的最长上升子序列的长度
状态转移方程：
    dp[1] = 1
    dp[k] = Max { dp[i]：1<i < k 且 ai < ak 且 k≠1 } + 1
*/
#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAXN=330000;
int dp[MAXN];
int a[MAXN];
int main()
{
    int n;
    while(cin>>n){
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int res=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(a[i]>a[j]){
                    dp[i]=max(dp[i],dp[j]);
                }
            }
            dp[i]++;
            res=max(dp[i],res);
        }
        cout<<res<<endl;
    }
}

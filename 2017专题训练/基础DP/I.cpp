/*
������������У���������
Ӧ����� ���� �����С������ĳ��Ȳ��� ������Ҫ�� ��������Ϊ��������е��κ���������
�����ܹ���һ������ϵͳ   ����������ĵ��� ���ܺ����������е�ĳ��������Ϊͬһ�顣
״̬��ƣ�
    dp[k] ��ʾ��ak ��Ϊ���յ㡱������������еĳ���
״̬ת�Ʒ��̣�
    dp[1] = 1
    dp[k] = Max { dp[i]��1<i < k �� ai < ak �� k��1 } + 1
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

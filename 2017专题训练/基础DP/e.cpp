#include<bits/stdc++.h>
using namespace std;
const int MAXN=1300;
int dp[MAXN];
int a[MAXN];
int main()
{
   // freopen("data.in","r",stdin);
    int n;
    while(cin>>n&&n){
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        memset(dp,0,sizeof(dp));
        dp[1]=a[1];
        int res=-1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<n;j++){
                if(a[j]<a[i]){
                    dp[i]=max(dp[i],dp[j]);
                }
            }
            dp[i]+=a[i];
            res=max(dp[i],res);
        }
        cout<<res<<endl;
    }
}

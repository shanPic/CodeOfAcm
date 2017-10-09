/*
* @FileName: D:\代码与算法\2017训练比赛\多校8\1011.cpp
* @Author: Pic
* @Date:   2017-08-17 14:04:08
* @Last Modified time: 2017-08-17 22:06:52
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=2000+30;
const LL mod=1e9+7;
const LL MOD=1e9+7;
LL dp[MAXN][MAXN];
LL F[MAXN], Finv[MAXN], inv[MAXN];//F是阶乘，Finv是逆元的阶乘

LL Comb(LL n,LL m){//comb(n, m)就是C(n, m) 
    if(m < 0 || m > n) return 0;
    return F[n] * 1LL * Finv[n - m] % MOD * Finv[m] % MOD;
}
void init()
{
	inv[1] = 1;
    for(int i = 2; i < MAXN; i ++){
        inv[i] = (MOD - MOD / i) * 1LL * inv[MOD % i] % MOD;
    }
    F[0] = Finv[0] = 1;
    for(int i = 1; i < MAXN; i ++){
        F[i] = F[i-1] * 1LL * i % MOD;
        Finv[i] = Finv[i-1] * 1LL * inv[i] % MOD;
    }

	//dp[0][0]=1;
    memset(dp,0,sizeof(dp));
	dp[1][1]=1;
	for(int i=2;i<=2010;i++){
		//dp[i][0]=0LL;
		for(int j=1;j<=i;j++){
			dp[i][j]=((j*dp[i-1][j]%mod)+dp[i-1][j-1])%mod;
		}
		//dp[i][i]=1LL;
	}
}
int main(){
	//freopen("data.in","r",stdin);
    init();
    int t;
    scanf("%d",&t);
    while(t--){
    	int n,m;
        LL res=0;
        scanf("%d%d",&n,&m);
        for(int i=1;i<m&&i<=n;i++){//名
            for(int j=1;j<=m-i&&j<=n;j++){//姓


               LL cur=(Comb(m,i)%MOD*(Comb(m-i,j)%MOD))%mod;
                //LL cur=(c[m][i]%mod*c[m-i][j]%mod)%mod;

                //if(i!=1){
                    cur=((cur%mod)*((dp[n][i]%mod*F[i])%MOD));
                //}

                //if(j!=1){
                    cur=((cur%mod)*(((dp[n][j])%mod*F[j])%MOD));
                //}
                res=(res+cur%MOD)%MOD;
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}
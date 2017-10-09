#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN = 1000000;
const ll mod=998244353;
int prime[MAXN+1];
void getPrime()
{
    memset(prime,0,sizeof(prime));
    for(int i = 2;i <= MAXN;i++)
    {
        if(!prime[i])prime[++prime[0]] = i;
        for(int j = 1;j <= prime[0] && prime[j] <= MAXN/i;j++)
        {
            prime[prime[j]*i] = 1;
            if(i % prime[j] == 0)break;
        }
    }
}
ll mult_mod(ll a,ll b){
    a%=mod;
    b%=mod;
    ll ret=0;
    while(b){
        if(b&1){
            ret+=a;
            ret%=mod;
        }
        a<<=1;
        if(a>=mod) a%=mod;
        b>>=1;
    }
    return ret;
}

int factor[1000][2];//factor[i][0]存素因子，factor[i][1]存素因子的个数
int fatCnt;//不重复的素因子个数
int pp=0;
int getFactors(long long x)
{
    fatCnt = 0;
    long long tmp = x;
    for(int i = 1; prime[i] <= tmp/prime[i];i++)
    {
        factor[fatCnt][1] = 0;
        if(tmp % prime[i] == 0 )
        {
            factor[fatCnt][0] = prime[i];
            while(tmp % prime[i] == 0)
            {
                factor[fatCnt][1] ++;
                tmp /= prime[i];
            }
            fatCnt++;
        }
    }
    if(tmp != 1)
    {
        factor[fatCnt][0] = tmp;
        factor[fatCnt++][1] = 1;
    }
    return fatCnt;
}
int main()
{ 
	freopen("data.in","r",stdin);
    getPrime();
    int t;
    scanf("%d",&t);
    while(t--){
        ll l,r,k,ans=0;
        scanf("%lld%lld%lld",&l,&r,&k);
        for(ll i=l;i<=r;i++){
            getFactors(i);
            ll tmp=1;
            for(int j=0;j<fatCnt;j++){
                tmp*=(k*factor[j][1]+1);
                tmp%=mod;
                //tmp=mult_mod(tmp,mult_mod(k,factor[j][1])+1);
            }
            ans+=tmp;
            ans%=mod;
        }
        printf("%lld,",ans);
    }  
    cout<<endl;
    return 0;
}

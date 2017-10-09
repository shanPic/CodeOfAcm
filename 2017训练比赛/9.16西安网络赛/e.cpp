/*
* @FileName: D:\代码与算法\2017训练比赛\9.16西安网络赛\e.cpp
* @Author: Pic
* @Created Time: 2017/9/16 13:37:07
*/
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
const ll  mod=999999999;
ll sum(ll x)
{
	ll res=0;
	while(x){
		res+=(x%10);
		x=x/10;
	}
	return res;
}
ll cal(ll i)
{
	ll res=0;
	res+=sum(i*9-1);
	res+=sum(mod-i+1);
	return res+16*9;
}
int main()
{
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	int t;
   	scanf("%d",&t);
	while(t--){
		ll n;
		scanf("%I64d",&n);
		ll ans=0;
		for(ll i=1;i<=99999;i++){
			if((cal(i*n))%233==0){
			//	cout<<11111<<endl;
				ans=i;
				break;
			}
		}
	//	cout<<ans<<endl;
		printf("%I64d",ans*(ll)9-(ll)1);
		for(int i=0;i<16;i++) printf("9");
		printf("%I64d",mod-ans+1);
		printf("\n");
	}	
	return 0;
}

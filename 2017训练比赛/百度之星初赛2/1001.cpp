/*
* @FileName: D:\代码与算法\2017训练比赛\百度之星初赛2\1001.cpp
* @Author: Pic
* @Date:   2017-08-13 14:23:37
* @Last Modified time: 2017-08-13 15:30:22
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
ll mod_pow(ll x, ll n, ll p){
    ll res = 1;
    while(n){
        if(n & 1) res =res * x % p;
        x = x * x % p;
        n >>= 1;
    }
    return res;
}
 
ll comb(ll n, ll m, ll p){
    if(m > n) return 0;
    ll ret = 1;
    m = min(n - m, m);
    for(int i = 1; i <= m; i ++){
        ll a = (n + i - m) % p;
        ll b = i % p;
        ret = ret * (a * mod_pow(b, p - 2, p) % p) % p;
    }
    return ret;
}
 
ll Lucas(ll n, ll m, ll p){
    if(m == 0) return 1;
    return comb(n % p, m % p, p) * Lucas(n / p, m / p, p) % p;
}
 
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		ll m,n;
		cin>>m>>n;
		ll bc=max(m,n);
		ll num=min(m,n);
		//LL res=0;
		//res=((mp[bc])/(mp[num]*mp[bc-num]))%MOD;
		cout<<Lucas(bc,num,1e9+7)<<endl;
	}
    return 0;
}
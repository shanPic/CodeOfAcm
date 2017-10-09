#include <bits/stdc++.h>
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
    int T;
    ll n, m, p;
    scanf("%d", &T);
    while(T--){
        scanf("%I64d%I64d%I64d", &n, &m, &p);
        printf("%I64d\n", Lucas(n, m, p));
    }
    return 0;
}
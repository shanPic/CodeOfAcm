#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int INF=0x3fffffff;
const int inf=-INF;
const int N=1e5+5;
const int M=2005;
const int mod=1000000007;
const double pi=acos(-1.0);

#define cls(x,c) memset(x,c,sizeof(x))
#define cpy(x,a) memcpy(x,a,sizeof(a))
#define ft(i,s,n) for (int i=s;i<=n;i++)
#define frt(i,s,n) for (int i=s;i>=n;i--)
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define lrt  rt<<1
#define rrt  rt<<1|1
#define middle int m=(r+l)>>1
#define lowbit(x) (x&-x)
#define pii pair<int,int>
#define mk make_pair
#define IN freopen("in.txt","r",stdin);
#define OUT freopen("out.txt","w",stdout);

int read() {
	char ch;
	while (ch = getchar(), !isdigit(ch));
	int res = ch - '0';
	while (ch = getchar(), isdigit(ch))
		res = res * 10 + ch - '0';
	return res;
}
//++++++++++++ÃÜ++++++++++++++·â++++++++++++++++++++Ïß

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T=read();
    while (T--){
        int n=read(),k=read();
        if (n==0) {puts("0");continue;}
        if (k==0) {puts("-1");continue;}
        if (k>n) {puts("-1");continue;}
        if (k==1) {printf("%d\n",n);continue;}
        int s=n,p=n,l=0,f=0;
        string as="";
        while (1)
        {
            s=p*k+l;p=s%10;l=s/10;
            char c=('0'+p);
            as=c+as;
            if (p==n&&l==0) break;
        }
         cout<<as<<endl;
    }
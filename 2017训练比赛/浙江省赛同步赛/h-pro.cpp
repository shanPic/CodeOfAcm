#include<bits/stdc++.h>
using namespace std;
const int MAXN=100000+30;
bool vis[MAXN];
int a[MAXN];
int b[MAXN];
int n;
int fa[MAXN];
int deg[MAXN];
int loca[MAXN];
int nowend;
int findf(int id)
{
    id--;
    while(deg[id]>=2){
        id--;
    }
    return id;
}
int findf2(int id)
{
    id--;
    while(deg[id]!=0){
        id--;
    }
    return id;
}
int read()
{
	int v = 0, f = 1;
	char c =getchar();
	while( c < 48 || 57 < c ){
		if(c=='-') f = -1;
		c = getchar();
	}
	while(48 <= c && c <= 57)
		v = v*10+c-48, c = getchar();
	return v*f;
}
void Out(int a)
{    //Êä³öÍâ¹Ò
	if(a < 0)
	{
		putchar('-');
		a = -a;
	}
	if(a >= 10)
	   Out(a / 10);
	putchar(a % 10 + '0');
}
int main()
{
    //freopen("data.in","r",stdin);
    int t;
    t=read();
    int n;
    nowend=0;
    while(t--){
        nowend=0;
        memset(fa,-1,sizeof(fa));
        memset(deg,0,sizeof(deg));
        n=read();
        for(int i=0;i<n;i++){
            a[i]=read();
        }
        for(int i=0;i<n;i++){
            b[i]=read();
            loca[b[i]]=i;
        }
        int f,j;
        fa[a[0]]=0;
        for(int i=1;i<n;i++){
            if(fa[a[i]]==-1){
                if(a[i]==b[i]){
                    f=findf(i);
                    fa[a[i]]=a[f];
                    deg[f]++;
                }
                else{
                    j=loca[a[i]];
                    f=findf2(i);
                    fa[a[i]]=fa[a[j]]=a[f];
                    deg[f]+=2;
                    if(i==j-1){
                        deg[i]+=2;
                        deg[j]+=2;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            //printf("%d",fa[i]);
            Out(fa[i]);
            if(i!=n) printf(" ");
        }
        printf("\n");
    }
}

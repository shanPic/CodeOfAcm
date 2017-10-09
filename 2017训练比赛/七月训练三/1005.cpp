/*
* @FileName: D:\代码与算法\2017训练比赛\七月训练三\1005.cpp
* @Author: Pic
* @Date:   2017-07-22 17:12:14
* @Last Modified time: 2017-07-23 15:42:12
*/


#include <stdio.h>
#include <string.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
const int MAXN=100000+30;
int fa[MAXN];
int val[MAXN];
int fin(int x)
{
	if(fa[x]==x) return x;
	else{
		//int tmp=fin(fa[x]);
		int tmp=fa[x];
		fa[x]=fin(fa[x]);
		val[x]=(val[tmp]^1);
		//fa[x]=tmp;
		return fa[x];
	}
}
void uion(int x,int y)
{
	int fx=fin(x),fy=fin(y);
	if(fx!=fy){
		// if(val[x]!=val[y]){
		// 	fa[fx]=0;
		// 	fa[fy]=0;
		// }
		// else{
		// 	val[fx]=(val[fy]^1);
		// 	fa[fx]=fy;
		// }
		fa[fx]=fy;
		val[fx]=(val[fy]^1);
	}
	return;
}
void init(int n)
{
	for(int i=0;i<=n;i++){
		fa[i]=i;
		val[i]=0;
	}
}
int main(){
	//freopen("data.in","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		getchar();
		init(n);
		char ch;
		int x,y;
		for(int i=0;i<m;i++){
			scanf("%c",&ch);
			if(ch=='D'){
				scanf("%d%d",&x,&y);
				uion(x,y);
			}
			else if(ch=='A'){
				scanf("%d%d",&x,&y);
				int fx=fin(x),fy=fin(y);
				if(fx!=fy){
					if(n!=2)
						printf("Not sure yet.\n");
					else{
						printf("In different gangs.\n");
					}
				}
				else{
					if(val[x]==val[y]){
						printf("In the same gang.\n");
					}
					else{
						printf("In different gangs.\n");
					}
				}
			}
			getchar();
		}
		// for(int i=0;i<n;i++){
		// 	printf("%d %d\n",fin(i),val[i]);
		// }
	}
    return 0;
}
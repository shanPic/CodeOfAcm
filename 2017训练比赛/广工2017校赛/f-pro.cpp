#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
int cnt = 1;
struct edge
{
	int y, val;
	int nxt;
};
edge tree[MAXN * 3];
int head[MAXN];
void addedge(int a, int b, int val)
{
	tree[cnt].y = b, tree[cnt].val = val;
	tree[cnt].nxt = head[a];
	head[a] = cnt++;
}
int dpt[MAXN], fa[MAXN],len[MAXN];
void dfs(int id)
{
	dpt[id] = dpt[fa[id]] + 1;
	int tmp = head[id];
	for (; tmp; tmp = tree[tmp].nxt) {
		if (tree[tmp].y != fa[id]) {
            fa[tree[tmp].y]=id;
			dfs(tree[tmp].y);
		}
		else{
			len[id]=tree[tmp].val;
		}
	}
	return ;
}
int e[MAXN];
int top;
bool check(int a, int b)
{
	top = 0;
	if (dpt[a] < dpt[b]) swap(a, b);
	while (dpt[a]  > dpt[b]) {
		e[++top]=len[a];
		if(top>=50)	return false;
		a=fa[a];
	}
	while(a!=b){
		e[++top]=len[a];
		e[++top]=len[b];
		if(top>=50) return false;
		a=fa[a];
		b=fa[b];
	}
	sort(e+1,e+top+1);
	for(int i=1;i<=top-2;i++){
		if(e[i]+e[i+1]>e[i+2]) return true;
	}
	return false;
}
void init()
{
    cnt=1;
    memset(dpt,0,sizeof(dpt));
	memset(head,0,sizeof(head));
	memset(fa,0,sizeof(fa));
	len[1]=0;
    fa[1]=0;
}
int main()
{
	//freopen("data.in","r",stdin);
	int t;
	int n, a, b, le;
	scanf("%d", &t);
	while (t--) {
		init();
		scanf("%d", &n);
		for (int i = 0; i < n-1; i++) {
			scanf("%d%d%d", &a, &b, &le);
			addedge(a, b, le);
			addedge(b, a, le);
		}
		dfs(1);
		int m;
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &a, &b);
			if (check(a, b))
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
}

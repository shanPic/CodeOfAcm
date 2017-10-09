#include<bits/stdc++.h>
using namespace std;
const int MAXN=22000;
int tree[MAXN];
int val[MAXN];
int n,Q;
int k;
struct que
{
	int fa,n;
	friend bool cmp(que a,que b){
		return a.fa<b.fa;
	}
}q[MAXN];
int find(int x)
{
	if(tree[x]==x) return x;
	int tmp=tree[x];
	tree[x]=find(tree[x]);
	tree[x]=tmp;
	val[x]=val[tmp]^val[x];
	return tre[x];
}
bool merg(int x,int y,int v)
{
	int xx=find(x),yy=find(yy);
	if(xx==yy) return val[x]^val[y]==v;
	tree[xx]=yy;
	val[xx]=val[xx]^val[yy]^v;
}
int query()
{
	for(int i=0;i<k;i++){
		q[i].fa=find(q[i].n);
	}
	sort(q,q+k+1,cmp);
	int l=0;
	while(l<=r){
		int cou=l+1;
		while(cou<=k&&()){
			
		}
	}
}
int main()
{
	char ch;
	char str[20];
	int x,y,v;
	while(~scanf("%d%d",&n,&Q)){
		//cin>>ch;
		getchar();
		ch=getchar();
		if(ch=='I'){
			fgets(str,8,stdin);
			int t=sscanf(str,"%d%d%d",&x,&y,&v);
			if(t==2){
				merg(x,n,y);
			}
			else{
				merg(x,y,v);
			}
		}
		else{
			scanf("%d",&k);
			for(int i=0;i<k;i++){
				scanf("%d",&q[i].n);
			}
			query();
		}
	}	
}
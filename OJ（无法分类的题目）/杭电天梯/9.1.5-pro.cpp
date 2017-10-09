//ran数组记录的是每一个节点的秩，num数组记录的是以此节点为根的并查集中元素的个数
//这样的写法是在路径压缩的时候合并了元素的秩
#include<bits/stdc++.h>
using namespace std;
const int MAXN=30100;
long long ran[MAXN],f[MAXN],num[MAXN];
void init()
{
	for(int i=0;i<MAXN;i++){
		ran[i]=0;
		f[i]=i;
		num[i]=1;
	}
}
int find(int x)
{
	if(x==f[x]) return x;

	int tmp=f[x];	
	f[x]=find(f[x]);
	ran[x]+=ran[tmp];   //注意此处一定要先递归再进行秩的合并（上层节点的秩和上上层合并完成后才能用上层的秩合并本层的）

	return f[x];
}
void merg(int a,int b)
{
	int x=find(a),y=find(b);
	if(x==y) return;
	f[x]=y;
	ran[x]=num[y];
	num[y]+=num[x];
}
int main()
{
	freopen("data.in","r",stdin);
	int p;
	int a,b;
	while(cin>>p){
        init();
		char ch;
		for(int i=0;i<p;i++){
			cin>>ch;
			if(ch=='M'){
				cin>>a>>b;
				merg(a,b);
			}
			else {
				cin>>a;
				find(a);
				cout<<ran[a]<<endl;
			}
		}
	}
}

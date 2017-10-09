/*
* @FileName: D:\代码与算法\2017训练比赛\CCPC网络赛\1003.cpp
* @Author: Pic
* @Date:   2017-08-19 12:25:08
* @Last Modified time: 2017-08-19 12:41:32
*/
#include <bits/stdc++.h>
using namespace std;
/*双联通分量（无向图）*/
/*强连通分量题的老套路:求分量,缩点图,输出DAG的相关信息.
tarjan遍历完成后，low数组保存的就是其所在的联通分量的编号（一个双联通分量中的节点，low数组编号相同）
一个结论：对于一棵无向树,我们要使得其变成边双连通图,需要添加的边数 == (树中度数为1的点的个数+1)/2*/
const int MAXN = 53000+30;
const int MAXM = 100010;
struct Edge
{
	int to, next;
	bool cut;//是否为桥的标记
};
struct BS {
	Edge edge[MAXM];
	int head[MAXN], tot;
	int Low[MAXN], DFN[MAXN], Stack[MAXN], Belong[MAXN]; //Belong数组的值是1~block
	int Index, top;
	int block;//边双连通块数
	bool Instack[MAXN];
	int bridge;//桥的数目
	void addedge(int u, int v)
	{
		edge[tot].to = v; edge[tot].next = head[u]; edge[tot].cut = false;
		head[u] = tot++;
	}
	void Tarjan(int u, int pre)
	{
		int v;
		Low[u] = DFN[u] = ++Index;
		Stack[top++] = u;
		Instack[u] = true;
		for (int i = head[u]; i != -1; i = edge[i].next)
		{
			v = edge[i].to;
			if (v == pre )continue;
			if ( !DFN[v] )
			{
				Tarjan(v, u);
				if ( Low[u] > Low[v] )Low[u] = Low[v];
				if (Low[v] > DFN[u])
				{
					bridge++;
					edge[i].cut = true;
					edge[i ^ 1].cut = true;
				}
			}
			else if ( Instack[v] && Low[u] > DFN[v] )
				Low[u] = DFN[v];
		}
		if (Low[u] == DFN[u])
		{
			block++;
			do
			{
				v = Stack[--top];
				Instack[v] = false;
				Belong[v] = block;
			}
			while ( v != u );
		}
	}
	void init()
	{
		tot = 0;
		memset(head, -1, sizeof(head));
	}
	void solve()
	{
		//初始化操作
		memset(DFN, 0, sizeof(DFN));
		memset(Instack, false, sizeof(Instack));
		Index = top = block = 0;
		memset(Belong, 0, sizeof(Belong));
		memset(head, -1, sizeof(head)); tot = 0;
		Index = top = 0;
		bridge = 0;
		int n, m;
		cin >> n >> m;
		int u, v;
		for (int i = 0; i < m; i++) {
			cin >> u >> v;
			addedge(u, v);
			addedge(v, u);
		}
		for (int i = 1; i <= n; i++)
			if (!DFN[i])
				Tarjan(i, i);
		int q;
		cin >> q;
		for (int i = 0; i < q; i++) {
			cin >> u >> v;
			if (Belong[u] == Belong[v]) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
}BS1,BS0;
int main()
{
	BS1.init();
	int t;
	scanf("%d",&t);
	while(t--){
		BS1.init();BS0.init();
		int n;
		scanf("%d",&n);
		int can;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				scnaf("%d",&can);
				if(can){
					BS1.addedge(i,j);
				}
				else{
					BS0.addedge(i,j);
				}
			}
		}
		if(BS1.solve()&&BS0.solve()){
			printf("Great Team!\n");
		}
		else{
			printf("Bad Team!\n");
		}
	}
}
#include<bits/stdc++.h>
using namespace std;
const int MAXN=110;
int n,m;
bool vis[MAXN][MAXN];
int G[MAXN][MAXN];//0表示可以走，大于0表示怪物，-1表示不可走
node node
{
	int type;//操作类型
	int x,y;//坐标
}path[1100];
int time=0;
bool dfs(int x,int y,int t)//t为时间
{

}
void print_path()
{
	
}
int main()
{
	char tmp;
	while(cin>>n>>m){
		memset(G,-1,sizof(G));
		getchar();
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				tmp=getchar();
				if(tmp=='.') G[i][j]=0;
				else if(tmp=='X') G[i][j]=-1;
				else G[i][j]=tmp-'0';
			}
			getchar();
		}
		if(dfs(0,0,1)){
			print_path();
		}
	}
}
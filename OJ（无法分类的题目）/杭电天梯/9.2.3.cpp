#include<bits/stdc++.h>
using namespace std;
int m[8][8];
bool vis[8][8];
bool vi[8][8];
int M,N;
int endx,endy;
int dfsx,dfsy;
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int to[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
struct node
{
	int x1,y1;//箱子所在位置
	int x2,y2;//人所在位置
	int step;
};
bool check(node x)
{
	if(x.x1==endx&&x.y1==endy)
		return 1;
	else return 0;
}
bool ok(node x)
{
	if(vis[x.x1][x.y1]==0&&x.x1<M&&x.x1>=0&&x.y1<N&&x.y1>=0&&m[x.x1][x.y1]!=1){
		return 1;
	}
	else return 0;
}
int DFS(int rx,int ry)
{
	//if(rx<0||rx>=M||ry<0||ry>=N) return 0;
	if(rx==dfsx&&ry==dfsy) {
            return 1;
	}
	for(int i=0;i<4;i++){
		int xx=rx+dir[i][0],yy=ry+dir[i][1];
		if(xx<0||xx>=M||yy<0||yy>=N||m[xx][yy]!=0||vi[xx][yy]) continue;
		vi[xx][yy]=1;
		if(DFS(xx,yy)) {
                return 1;
		}
		vi[xx][yy]=0;
	}
	return 0;
}
int BFS(node b)
{
	memset(vis,0,sizeof(vis));
	vis[b.x1][b.y1]=1;
	queue<node> q;
	q.push(b);
	while(!q.empty()){
		node t=q.front();
		q.pop();
		if(check(t)) return t.step;
		for(int i=0;i<4;i++){
			node tmp=t;
			tmp.step++;
			tmp.x1+=dir[i][0];
			tmp.y1+=dir[i][1];
			if(ok(tmp)){
				memset(vi,0,sizeof(vi));
				dfsx=t.x1+to[i][0];dfsy=t.y1+to[i][1];
				m[tmp.x1][tmp.y1]=2;
				if(DFS(tmp.x2,tmp.y2)){
					vis[tmp.x1][tmp.x2]=1;
					tmp.x2=dfsx,tmp.y2=dfsy;
					q.push(tmp);
				}
				m[tmp.x1][tmp.y1]=0;
			}
		}
	}
	return -1;
}
int main()
{
    freopen("data.in","r",stdin);
	int t;
	cin>>t;
	int x,y;
	while(t--){
		memset(m,-1,sizeof(m));
		cin>>M>>N;
		for(int i=0;i<M;i++){
			for(int j=0;j<N;j++){
				cin>>m[i][j];
			}
		}
		node b;
		b.step=0;
		for(int i=0;i<M;i++){
			for(int j=0;j<N;j++){
				if(m[i][j]==2) {b.x1=i,b.y1=j;m[i][j]=0;}
				if(m[i][j]==4) {b.x2=i,b.y2=j;m[i][j]=0;}
				if(m[i][j]==3) endx=i,endy=j;
			}
		}
		cout<<BFS(b)<<endl;
	}
}

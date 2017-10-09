#include<bits/stdc++.h>
using namespace std;
int m[10][10];
bool vis[10][10][4];
bool vi[10][10];
int M,N;
int endx,endy;
int dfsx,dfsy;
int dir[4][2]= {{1,0},{-1,0},{0,1},{0,-1}};
int to[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
struct node
{
	int x1,y1;//箱子所在位置
	int x2,y2;//人所在位置
	int step;
	void print(){
	    cout<<"step:"<<step<<"    "<<x1+1<<"    "<<y1+1<<"    "<<x2+1<<"    "<<y2+1<<endl;
	}
};
bool check(node x)
{
	if(x.x1==endx&&x.y1==endy)
		return 1;
	else return 0;
}
bool ok(node x)
{
	if(vis[x.x1][x.y1]==0&&x.x1>=0&&m[x.x1][x.y1]==0){
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
    vi[rx][ry]=1;
	for(int i=0;i<4;i++){
		int xx=rx+dir[i][0];int yy=ry+dir[i][1];
		if(xx<0||xx>=M||yy<0||yy>=N||m[xx][yy]!=0||vi[xx][yy]) continue;
		if(DFS(xx,yy)) {
                return 1;
		}
	}
    //vi[rx][ry]=0;
	return 0;
}
queue<node> q;
int BFS(node b)
{
	memset(vis,0,sizeof(vis));
	while(!q.empty()){
        q.pop();
	}
	q.push(b);
	node tmp,t;
	while(!q.empty()){
        t=q.front();
		q.pop();
		//cout<<"out"<<"    ";t.print();
		if(t.x1==endx&&t.y1==endy) return t.step;
		for(int i=0;i<4;i++){
            tmp=t;
			tmp.step++;
			tmp.x1+=dir[i][0];
			tmp.y1+=dir[i][1];
			if(vis[t.x1][t.y1][i]==0&&tmp.x1>=0&&tmp.x1<M&&tmp.y1>=0&&tmp.y1<N&&m[tmp.x1][tmp.y1]==0){
				memset(vi,0,sizeof(vi));
				vi[tmp.x2][tmp.y2]=1;
				dfsx=t.x1+to[i][0];dfsy=t.y1+to[i][1];
				m[t.x1][t.y1]=2;
				if(DFS(t.x2,t.y2)){
					vis[t.x1][t.y1][i]=1;
					tmp.x2=t.x1,tmp.y2=t.y1;
					q.push(tmp);
					//cout<<q.size()<<"     "<<"in"<<"    ";tmp.print();
				}
				m[t.x1][t.y1]=0;
			}
		}
	}
	return -1;
}
int main()
{
    //freopen("data.in","r",stdin);
	int t;
	//cin>>t;
	scanf("%d",&t);
	int x,y;
	while(t--){
		memset(m,-1,sizeof(m));
		//cin>>M>>N;
		scanf("%d%d",&M,&N);
		for(int i=0;i<M;i++){
			for(int j=0;j<N;j++){
				//cin>>m[i][j];
				scanf("%d",&m[i][j]);
			}
		}
		node b;
		b.step=0;
		for(int i=0;i<M;i++){
			for(int j=0;j<N;j++){
				if(m[i][j]==2) {b.x1=i,b.y1=j;m[i][j]=0;}
				if(m[i][j]==4) {b.x2=i,b.y2=j;m[i][j]=0;}
				if(m[i][j]==3) {endx=i,endy=j;m[i][j]=0;}
			}
		}
		cout<<BFS(b)<<endl;
	}
}

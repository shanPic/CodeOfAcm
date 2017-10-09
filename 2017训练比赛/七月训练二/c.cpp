/*
* @FileName: D:\代码与算法\2017训练比赛\七月训练二\c.cpp
* @Author: Pic
* @Date:   2017-07-16 00:20:36
* @Last Modified time: 2017-07-16 00:46:46
*/

#include <iostream>
#include<algorithm>
#include<queue>
#include<string.h>
#include<cstdio>
using namespace std;
const int MAXN=330;
const int INF=0x3f3f3f3f;
int dir[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };
int n;
int mp[MAXN][MAXN];
bool vis[MAXN][MAXN];
struct node
{
	int x,y,t;
};
int BFS()
{
	if(mp[0][0]==INF) return 0;
	node tmp;
	int res=-1;
	queue<node> q;	
	tmp.x=0,tmp.y=0,tmp.t=0;
	vis[0][0]=1;
	q.push(tmp);
	int x,y,t;
	int tmpx,tmpy;
	while(!q.empty()){
		//cout<<11111<<endl;
		tmp=q.front();q.pop();
		x=tmp.x,y=tmp.y,t=tmp.t;
		for(int i=0;i<4;i++){
			tmpx=x+dir[i][0],tmpy=y+dir[i][1];
			if(tmpx>=0&&tmpx<MAXN&&tmpy>=0&&tmpy<MAXN)
			if(mp[tmpx][tmpy]>t+1){
				if(mp[tmpx][tmpy]==INF){
					res=t+1;
					return res;
				}
				else{
					if(!vis[tmpx][tmpy]){
						vis[tmpx][tmpy]=1;
						tmp.x=tmpx,tmp.y=tmpy,tmp.t=t+1;
						q.push(tmp);
					}
				}
			}
		}
	}
	return res;
}
int main(){
	//freopen("data.in","r",stdin);
	int x,y;
	int t;
	while(~scanf("%d",&n)){
		//cout<<2222<<endl;
		memset(mp,0x3f,sizeof(mp));
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&x,&y,&t);
			mp[x][y]=min(t,mp[x][y]);
			int tmpx,tmpy;
			for(int j=0;j<4;j++){
				tmpx=x+dir[j][0],tmpy=y+dir[j][1];
				if(tmpx>=0&&tmpx<MAXN&&tmpy>=0&&tmpy<MAXN)
					mp[tmpx][tmpy]=min(t,mp[tmpx][tmpy]);
			}
		}
		memset(vis,0,sizeof(vis));
		printf("%d\n",BFS());
	}
    return 0;
}
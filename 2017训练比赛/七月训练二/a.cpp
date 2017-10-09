/*
* @FileName: D:\代码与算法\2017训练比赛\七月训练二\a.cpp
* @Author: Pic
* @Date:   2017-07-15 00:28:08
* @Last Modified time: 2017-07-15 00:35:55
*/

#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
const int MAXN=20+3;
int dir[4][2]={1,0,0,1,-1,0,0,-1};
int mp[MAXN][MAXN];
bool vis[MAXN][MAXN];
int cnt;
int w,h;
int bx,by;
void dfs(int x,int y){
	if(!vis[x][y]){
		vis[x][y]=1;
		if(mp[x][y]){
			cnt++;
			int tmpx,tmpy;
			for(int i=0;i<4;i++){
				tmpx=x+dir[i][0],tmpy=y+dir[i][1];
				if(tmpx>=0&&tmpx<h&&tmpy>=0&&tmpy<w)
					dfs(tmpx,tmpy);
			}
		}
	}
}
int main(){
	//freopen("data.in","r",stdin);
	while(~scanf("%d%d",&w,&h)&&w&&h){
		//cout<<w<<"\t"<<h<<endl;
		getchar();
		char ch;
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				scanf("%c",&ch);
				if(ch=='@'){
					bx=i,by=j;
					mp[i][j]=1;
				}
				else if(ch=='.'){
					mp[i][j]=1;
				}
				else {
					mp[i][j]=0;
				}
			}
			getchar();
		}
		cnt=0;
		memset(vis,0,sizeof(vis));
		dfs(bx,by);
		printf("%d\n",cnt);
	}
    return 0;
}
/*
* @FileName: D:\代码与算法\2017训练比赛\百度之星初赛\1006.cpp
* @Author: Pic
* @Date:   2017-08-12 14:42:35
* @Last Modified time: 2017-08-12 15:48:42
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN=100+30;
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int vis[MAXN][MAXN];
int n,m;
int mp[MAXN][MAXN];
bool dfs0(int x,int y)
{
	vis[x][y]=1;
	int flag=1;
	for(int i=0;i<4;i++){
		int nowx=x+dir[i][0],nowy=y+dir[i][1];
		if(mp[nowx][nowy]==0&&nowx<n&&nowx>=0&&nowy<m&&nowy>=0&&vis[nowx][nowy]==0){
			if(nowx==0||nowx==n-1||nowy==0||nowy==m-1) flag=0;
			if(!dfs0(nowx,nowy)){
				flag=0;
			}
		}
	}
	return flag;
}
void dfs1(int x,int y)
{
	vis[x][y]=1;
	for(int i=0;i<4;i++){
		int nowx=x+dir[i][0],nowy=y+dir[i][1];
		if(mp[nowx][nowy]&&nowx<n&&nowx>=0&&nowy<m&&nowy>=0&&vis[nowx][nowy]==0){
			dfs1(nowx,nowy);
		}
	}
}
int main(){
	//freopen("data.in","r",stdin);
	while(~scanf("%d%d",&n,&m)){
		char ch;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%c",&ch);
				if(ch=='1') mp[i][j]=1;
				else mp[i][j]=0;
			}
			getchar();
		}
		memset(vis,0,sizeof(vis));
		int cnt1=0,cnt0b=0,cnt0a=0;
		int flag=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(vis[i][j]==0){
					if(mp[i][j]){
						dfs1(i,j);
						cnt1++;
					}
					else{
						if(dfs0(i,j)){
							flag=1;
							cnt0b++;
						}
						else{
							cnt0a++;
						}
					}
				}
			}
		}
		if(flag){
			if(cnt1==1&&cnt0b==1) printf("0\n");
			else
				printf("-1\n");
		}
		else{
			if(cnt1==1) printf("1\n");
			else printf("-1\n");
		}

	}
    return 0;
}
/*
* @FileName: D:\代码与算法\2017训练比赛\七月训练二\f.cpp
* @Author: Pic
* @Date:   2017-07-16 17:41:58
* @Last Modified time: 2017-07-16 17:57:44
*/
#include<iostream>
#include <cstdio>
#include<set>
#include<string.h>
using namespace std;
int dir[4][2]={1,0,0,1,-1,0,0,-1};
int g[6][6];
set<int> s;
void dfs(int x,int y,int step,int num)
{
	if(step==6){
		s.insert(num);
		//cout<<11111<<endl;
		return;
	}
	else{
		num*=10;
		int tmpx,tmpy;
		for(int i=0;i<4;i++){
			tmpx=x+dir[i][0],tmpy=y+dir[i][1];
			if(tmpx>=0&&tmpx<5&&tmpy>=0&&tmpy<5){
				//vis[tmpx][tmpy]=1;
				dfs(tmpx,tmpy,step+1,num+g[tmpx][tmpy]);
				//vis[tmpx][tmpy]=0;
			}
		}
	}
}
int main(){
	//freopen("data.in","r",stdin);
	s.clear();
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			scanf("%d",&g[i][j]);
		}
	}
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			dfs(i,j,0,0);
		}
	}
	printf("%d\n",s.size());
	//cout<<s.size()<<endl;
    return 0;
}
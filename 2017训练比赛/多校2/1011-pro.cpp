/*
* @FileName: D:\代码与算法\2017训练比赛\多校2\1011-pro.cpp
* @Author: Pic
* @Date:   2017-07-27 13:21:16
* @Last Modified time: 2017-07-27 14:08:21
*/

#include<bits/stdc++.h>
using namespace std;
const int MAXN=500+30;
struct node 
{
	int x,y;
	double dist;
	node(){};
	node(int x,int y,int dist):x(x),y(y),dist(dist){};
};
node edge[MAXN][MAXN];
vector<node> vec[230];
int px[MAXN],py[MAXN];
double dis(int i,int j)
{
	return sqrt((a[i].x*a[j].x)+(a[i].y*a[j].y));
}
int res=0;
int pd(int e,int i,int flag,doubel dist)
{
	int m=vec[i].size();
	for(int j=0;j<m;j++){
		if(j!=flag&&vec[i][j].b==e&&vec[i][j].dist==dist){
			return j;
		}
	}
	return -1;

}
int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++){
			scanf("%d%d",&p[x],&p[y]);
		}
		double tmp=0;
		int dist;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				tmp=dis(i,j);
				dist=tmp;
				vec[dist].push(node(i,j,tmp));
			}
		}
		res=0;
		bool vis[MAXN]={0};
		queue<int> q;
		for(int i=1;i<230;i++){
			if(!vec[i].empty()){
				memset(vis,0,sizeof(vis));
				int m=vec[i].size();
				for(int j=0;j<m;j++){
					int flag=0;
					int b=vec[i][j].x,e=vec[i][j].y;
					int now=j;
					int bc=0;
					vis[b]=1;
					while(now=pd(e,i,j,dist)&&now!=-1){
						bc++;
						if(vis[now]){
							if(vec[i][now].e==b){
								flag=1;
							}
							break;
						}
						e=vec[i][now].e;
					}
					if(flag) res++;
				}
			}
		}
	}

    return 0;
}
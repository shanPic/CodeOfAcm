#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<string.h>
#include<cstdio>
using namespace std;
#define N 5050
#define NN 105
#define M 10001
#define inf 0x7fffffff
int place[8]={5120,2560,1280,640,320,160,80,40};
int fx,fy;
int ex,ey;
int m,n;

struct bus_stop{
	int x,y;
	char ch[30];
}B[N];
vector<bus_stop> bus_line[NN];

struct node{
	int next,v,w;
	node(){};
	node(int a,int b,int c){
		next=a;v=b;w=c;
	}
}E[M];
int head[NN],dis[NN],NE;
bool h[NN];
void init(){
	NE=0;
	memset(head,-1,sizeof(head));
}
void insert(int u,int v,int w){
	E[NE]=node(head[u],v,w);
	head[u]=NE++;
}
bool update(int u,int v,int w){
	if(dis[u]+w<dis[v]){
		dis[v]=dis[u]+w;
		return true;
	}
	return false;
}
void spfa(int beg,int end){
	queue<int> q;
	memset(h,0,sizeof(h));
	for(int i=0;i<=m+1;i++)
		dis[i]=inf;
	dis[beg]=0;
	q.push(beg);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		h[u]=0;
		for(int i=head[u];i!=-1;i=E[i].next){
			int v=E[i].v;
			if(update(u,v,E[i].w)&&!h[v]){
				h[v]=1;
				q.push(v);
			}
		}
	}
	if(dis[end]==inf){
		printf("take a taxi\n");
		return;
	}
	printf("%d\n",dis[end]);
}

int find(char *p){
	for(int i=0;i<n;i++)
		if(strcmp(p,B[i].ch)==0)
			return i;
}
bool find_bus(vector<bus_stop> p,vector<bus_stop> q){
	for(int i=0;i<p.size();i++)
		for(int j=0;j<q.size();j++)
			if(strcmp(p[i].ch,q[j].ch)==0)
				return true;
	return false;
}
void trans(char *p,int &x,int &y){
	x*=4;y*=4;
	for(int i=0;i<8;i++){
		if(p[i]=='1')
			y+=place[i];
		else if(p[i]=='2')
			x+=place[i];
		else if(p[i]=='3'){
			x+=place[i];
			y+=place[i];
		}
	}
}
double cal_dis(int fx,int fy,int ex,int ey){
	double temp1=(fx*1.0-ex*1.0)*(fx*1.0-ex*1.0);
	double temp2=(fy*1.0-ey*1.0)*(fy*1.0-ey*1.0);
	return sqrt(temp1+temp2);
}
int main(void){
	int t;
	scanf("%d",&t);
	while(t--){
		char s[10],e[10];
		scanf("%s%d%d",s,&fx,&fy);
		scanf("%s%d%d",e,&ex,&ey);
		trans(s,fx,fy);
		trans(e,ex,ey);
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%s",B[i].ch);
			scanf("%d%d",&B[i].x,&B[i].y);
		}
		scanf("%d",&m);
		for(int i=1;i<=m;i++){
			char ch[30];
			int k;
			scanf("%d",&k);
			bus_line[i].clear();
			while(k--){
				scanf("%s",ch);
				int id=find(ch);
				bus_line[i].push_back(B[id]);
			}
		}
		if(cal_dis(fx,fy,ex,ey)<=2000.0){
			printf("walk there\n");
			continue;
		}
		int beg=0;
		int end=m+1;
		bool flag1,flag2;
		flag1=flag2=0;
		init();
		for(int i=1;i<=m;i++)
			for(int j=0;j<bus_line[i].size();j++){
				double k1=cal_dis(fx,fy,bus_line[i][j].x,bus_line[i][j].y);
				double k2=cal_dis(ex,ey,bus_line[i][j].x,bus_line[i][j].y);
				if(k1<=1000.0){
					flag1=true;
					insert(beg,i,1);
				}
				if(k2<=1000.0){
					flag2=true;
					insert(i,end,0);
				}
			}
		if(!flag1||!flag2){
			printf("take a taxi\n");
			continue;
		}
		for(int i=1;i<=m;i++)
			for(int j=i+1;j<=m;j++)
				if(find_bus(bus_line[i],bus_line[j])){
					insert(i,j,1);
					insert(j,i,1);
				}
		spfa(beg,end);
	}
}

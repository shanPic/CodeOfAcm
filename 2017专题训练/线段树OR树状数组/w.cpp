#include<bits/stdc++.h>
using namespace std;
const int MAXN=8300<<3;
const int ROUND=8003;
int setv[MAXN];
int vis[8300];
int num[8300];
int fl,fr;
int target;
void pushdown(int id)
{
	if(setv[id]!=-1&&setv[id]!=-2){
		setv[id*2]=setv[id*2+1]=setv[id];
		setv[id]=-1;
	}
	else if(setv[id]==-2){
		setv[id]=-1;
	}
}
void update(int id,int l,int r)
{
	if(fl<=l&&fr>=r){
		setv[id]=target;
	}
	else{
		int mid=l+(r-l)/2;
		pushdown(id);
		if(fl<=mid) update(id*2,l,mid);
		if(fr>mid) update(id*2+1,mid+1,r);
	}
}
int flag;
void query(int id,int l,int r)
{
/*	if(flag==21) printf("%d %d  %d\n",id,l,r);
	cout<<"flag"<<flag++<<endl;*/
	if(setv[id]!=-1&&setv[id]!=-2){
		int x=setv[id];
		for(int i=l;i<=r;i++){
			vis[i]=x;
		}
	}
	else if(setv[id]==-1){
		int mid=l+(r-l)/2;
		query(id*2,l,mid);
		query(id*2+1,mid+1,r);
	}
}
void init()
{
	//memset(setv,0,sizeof(setv));
	for(int i=0;i<MAXN;i++){
		setv[i]=-2;
	}
	memset(vis,-1,sizeof(vis));
	memset(num,0,sizeof(num));
}
int main()
{
	//freopen("data.in","r",stdin);
	int n;
	while(~scanf("%d",&n)){
		//cout<<111<<endl;
		init();
		int x,y;
		for(int i=0;i<n;i++){
			//cout<<2222<<endl;
			scanf("%d%d%d",&x,&y,&target);
			if(x>y) swap(x,y);
			fl=x+1,fr=y;
			update(1,1,ROUND);
		}
		//cout<<333<<endl;
		query(1,1,ROUND);
		//cout<<444<<endl;
/*		for(int i=1;i<10;i++){
			cout<<i<<"\t"<<vis[i]<<endl;
		}*/
		int tmp;
		for(int i=1;i<ROUND;i++){
			tmp=vis[i];
			if(tmp!=-1){
				num[tmp]++;
				//vis[tmp]++;
				while(vis[i]==vis[i+1]){
					i++;
				}
			}
		}
		for(int i=0;i<ROUND;i++){
			if(num[i]!=0)
				printf("%d %d\n",i,num[i]);
		}
		printf("\n");
	}
}
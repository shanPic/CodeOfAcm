#include<bits/stdc++.h>
using namespace std;
const int MAXN=10000030>>3;
const int N=10000000;
int setv[MAXN];
void pushdown(int id)
{
	if(setv[id]!=-1){
        cout<<"pushdown"<<endl;
		setv[id*2]=setv[id];
		setv[id*2+1]=setv[id];
		setv[id]=-1;
        cout<<"pushdown_end"<<endl;
	}
}
int fl,fr;
int target;
void update(int id,int l,int r)
{
    cout<<33333<<endl;
	if(l>=fl&&r<=fr){
		setv[id]=target;
		return ;
	}
	else{
		int mid=l+(r-l)/2;
		pushdown(id);
		if(fl<=mid) update(id*2,l,mid);
		if(fr>mid) update(id*2+1,mid+1,r);
		return ;
	}
}
int cnt=0;
int vis[MAXN];
void query(int id,int l,int r)
{
	if(setv[id]!=-1){
		if(vis[setv[id]]==0){
			cnt++;
			vis[setv[id]]=1;
		}
		return;
	}
	else{
		int mid=l+(r-l)/2;
		if(fl<=mid) query(id*2,l,mid);
		if(fr>mid) query(id*2+1,mid+1,r);
	}
}
int main()
{
	freopen("data.in","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--){
	    memset(setv,-1,sizeof(setv));
        cout<<11111<<endl;
		int n;
		int x,y;
		int num=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
            cout<<22222<<endl;
			scanf("%d%d",&x,&y);
			if(x>y) swap(x,y);
			fl=x,fr=y;
			target=(++num);
			update(1,1,N);
		}
		cnt=0;
		memset(vis,0,sizeof(vis));
		query(1,1,N);
		printf("%d\n",cnt);
	}
}

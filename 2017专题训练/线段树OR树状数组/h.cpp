#include<bits/stdc++.h>
using namespace std;
const int MAXN=600030;
long long sum[MAXN];
long long a[MAXN];
long long n;
void buildTree(int id,int l,int r)
{
	if(l==r){
		sum[id]=a[l];
		return ;
	}
	else{
		int mid=l+(r-l)/2;
		buildTree(id*2,l,mid);
		buildTree(id*2+1,mid+1,r);
		sum[id]=sum[id*2]+sum[id*2+1];
	}
}
int fl,fr;
void update(int id,int l,int r)
{
	if(fl<=l&&fr>=r&&sum[id]==(r-l)+1){
		return;
	}
	if(l==r){
		if(sum[id]==1) return;
		sum[id]=(int)sqrt(1.0*sum[id]);
		return ;
	}
	else{
		int mid=l+(r-l)/2;
		if(fl<=mid){
			update(id*2,l,mid);
		}
		if(fr>mid){
			update(id*2+1,mid+1,r);
		}
		sum[id]=sum[id*2]+sum[id*2+1];
	}
}
long long _sum=0;
void query(int id,int l,int r)
{
	if(fl<=l&&fr>=r){
		_sum+=sum[id];
		return;
	}
	else{
		int mid=l+(r-l)/2;
		if(fl<=mid){
			query(id*2,l,mid);
		}
		if(fr>mid){
			query(id*2+1,mid+1,r);
		}
		return;
	}
}
int main()
{
	//freopen("data.in","r",stdin);
	int cnt=0;
	while(~scanf("%lld",&n)){
		printf("Case #%d:\n",++cnt);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		//cout<<11111<<endl;
		buildTree(1,1,n);
		///cout<<22222<<endl;
		int t;
		scanf("%d",&t);
		int m;
		for(int i=0;i<t;i++){
			//cout<<33333<<endl;
			scanf("%d",&m);
			if(m){
				_sum=0;
				scanf("%d%d",&fl,&fr);
				if(fl>fr) swap(fl,fr);
				query(1,1,n);
				printf("%lld\n",_sum);
			}
			else{
				scanf("%d%d",&fl,&fr);
				if(fl>fr) swap(fl,fr);
				update(1,1,n);
			}
		}
		printf("\n");
	}
}
/*
线段树成段更新，求总和
#注意在使用前要先建树，否则无法使用
#注意line57，59，75，76的比较条件都是fl，fr。不是l，r
#moni之后发现，是maintain函数有错误，模拟5，9，3时10的情况即可
*/
#include<bits/stdc++.h>
using namespace std;
const int INFINITE = INT_MAX;
const int MAXN = 400030;
int N;
int sum[MAXN];
int setv[MAXN];
void buildTree(int id,int left,int right)
{
    if(left==right){
        sum[id]=1;
        setv[id]=-1;
    }
    else{
        int mid=left+(right-left)/2;
        buildTree(id*2,left,mid);
        buildTree(id*2+1,mid+1,right);
        setv[id]=-1;
        sum[id]=sum[id*2]+sum[id*2+1];
    }
}
void maintain(int id,int l,int r)
{
	//sum[id]=0;
	if(setv[id]==-1&&l!=r){
		sum[id]=sum[id*2]+sum[id*2+1];
	}
	else if(setv[id]!=-1){
		sum[id]=setv[id]*((r-l)+1);//注意小括号
	}
}
void pushdown(int id)
{
	if(setv[id]!=-1){
		setv[id*2]=setv[id];
		setv[id*2+1]=setv[id];
		setv[id]=-1;
	}
}
int fl,fr;//需要更新的目标区间
int val;//更新后变成的值
void update(int id,int l,int r)
{
	if(l>=fl&&r<=fr){
		setv[id]=val;
	}
	else{
		pushdown(id);//将标记向下传递
		
		int mid=l+(r-l)/2;

		if(fl<=mid) update(id*2,l,mid);
		else maintain(id*2,l,mid);		//处理左树

		if(fr>mid) update(id*2+1,mid+1,r);
		else maintain(id*2+1,mid+1,r);	//处理右树

	}

	maintain(id,l,r);	//将本节点下的左右子树的更改传递到本节点

}
int main()
{
	int t;
	//cin >> t;
	scanf("%d",&t);
	int cnt=0;
	while (t--) {
		scanf("%d",&N);
		buildTree(1,1,N);
		int q;
		int x,y,z;
		//cin>>q;
		scanf("%d",&q);
		for(int i=0;i<q;i++){
			//cin>>x>>y>>z;
			scanf("%d%d%d",&x,&y,&z);
			val=z;
			fl=x,fr=y;
			update(1,1,N);
		}
		//cout<<"Case "<<++cnt<<": The total value of the hook is "<<sum[1]<<"."<<endl;
		printf("Case %d: The total value of the hook is %d.\n",++cnt,sum[1]);
	}
}

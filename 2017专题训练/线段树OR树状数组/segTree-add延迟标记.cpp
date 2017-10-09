#include<bits/stdc++.h>
using namespace std;
const int MAXN=4000000;
int sum[MAXN];
int addv[MAXN];
void buildTree(int id,int l,int r)
{
	if(l==r){
		sum[id]=1;
		addv[id]=0;
	}
	else{
		int mid=l+(r-l)/2;

		buildTree(id*2,l,mid);
		buildTree(id*2+1,mid+1,r);

		sum[id]=sum[id*2]+sum[id*2+1];
	}

}
void pushdown(int id)
{
	addv[id*2]=addv[id*2+1]=add[id];
	addv[id]=0;
}
void maintain(int id,int l,int r)
{

	sum[id]=sum[id*2]+sum[id*2+1];
}
int main()
{

}
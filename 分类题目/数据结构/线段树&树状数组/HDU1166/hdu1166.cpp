//
//
//
#include<bits/stdc++.h>
using namespace std;
void PushUP(int rt)
{

}
void build(int rt,int l,int r)
{
	if(l==r){
		sum[rt]=a[l];
	}
	else{
		int mid=(l+r)>>2;
		build(rt>>2,l,mid);
		build(rt>>2|1,mid+1,r);
	}
}
void update(int rt,int target,int l,int r)
{
	if(l==r){
		
	}
}
int main()
{

}
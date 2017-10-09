/*
* @FileName: D:\代码与算法\2017训练比赛\七月训练四\1013.cpp
* @Author: Pic
* @Date:   2017-08-04 21:31:01
* @Last Modified time: 2017-08-05 20:21:10
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <queue>
using namespace std;
typedef __int64 ll;
const int MAXN=20000+30;
//注意，这道题的vol有相同的情况出现。这样的话就不能先按x坐标排序，统计左右比这个点小的个数，然后按照vol排序统计左右比这个点小的点的vol和
//而是应该同步地统计这两个量，防止相同的情况
struct BIT{	
	void init()
	{
		memset(Tree_sum,0,sizeof(Tree_sum));
	}
	ll Tree_sum[MAXN];//存储树状数组的数组
	//int maxn=20000+30;  //树状数组的下标最大值
	ll lowbit(ll x)   //lowbit函数, 找到x与与 *最近的一个末位连续0比他多的数* 的距离
	{
	    return x&(-x);
	}
	ll getsum(ll x)   //获取0至x区间的和
	{
	    ll sum=0;
	    for(;x>0;x-=lowbit(x)){
	        sum+=Tree_sum[x];
	    }
	    return sum;
	}
	void update(ll x,ll v)    //更新某点的值
	{
	    for(;x<=MAXN;x+=lowbit(x)){
	        Tree_sum[x]+=v;
	    }
	}
};
BIT tr,tr2;
struct node
{
	ll vol,x,id;
}a[MAXN];
ll n1[MAXN];
bool cmp(node a,node b)
{
    return a.vol<b.vol;
}
bool cmp1(node a,node b)
{
	return a.x<b.x;
}
int main(){
    //freopen("data.in","r",stdin);
	ll n;
	while(~scanf("%I64d",&n)){
		for(int i=0;i<n;i++){
			//scanf("%d%d",&a[i].vol,&a[i].x);
			//cin>>a[i].vol>>a[i].x;
			scanf("%I64d%I64d",&a[i].vol,&a[i].x);
			a[i].id=i;
		}
		tr.init();
		tr2.init();
		sort(a,a+n,cmp1);
        sort(a,a+n,cmp);
        ll res=0,sum=0,sumn=0;
        for(int i=0;i<n;i++){
        	sumn=tr.getsum(a[i].x);
            ll suma=tr2.getsum(a[i].x);
            res+=((sum-suma-suma)*a[i].vol);
            res+=((2*sumn-i)*a[i].vol*a[i].x);
            //cout<<res<<endl;
            tr2.update(a[i].x,a[i].x);
            tr.update(a[i].x,1);
            sum+=a[i].x;
        }
        //printf("%lld\n",res);
        //cout<<res<<endl;
        printf("%I64d\n",res);
	}
    return 0;
}
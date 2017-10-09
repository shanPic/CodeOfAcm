/*
* @FileName: D:\代码与算法\2017训练比赛\CF#426\b-pro.cpp
* @Author: Pic
* @Date:   2017-08-16 19:51:14
* @Last Modified time: 2017-08-17 10:19:23
*/

#include<bits/stdc++.h>
using namespace std;
const int INFINITE = INT_MAX;
const int MAXN=35000+30;
const int MAXNUM = MAXN*4+30;
struct SegTreeNode
{
    int val;
    int addMark;//延迟标记
}segTree[MAXNUM];//定义线段树

/*
功能：当前节点的标志域向孩子节点传递
root: 当前线段树的根节点下标
*/
void pushDown(int root)
{
    if(segTree[root].addMark != 0)
    {
        //设置左右孩子节点的标志域，因为孩子节点可能被多次延迟标记又没有向下传递
        //所以是 “+=”
        segTree[root*2+1].addMark += segTree[root].addMark;
        segTree[root*2+2].addMark += segTree[root].addMark;
        //根据标志域设置孩子节点的值。因为我们是求区间最小值，因此当区间内每个元
        //素加上一个值时，区间的最小值也加上这个值
        segTree[root*2+1].val += segTree[root].addMark;
        segTree[root*2+2].val += segTree[root].addMark;
        //传递后，当前节点标记域清空，防止多次向下传递，造成数据错误
        segTree[root].addMark = 0;
    }
}

/*
功能：线段树的区间查询
root：当前线段树的根节点下标
[nstart, nend]: 当前节点所表示的区间
[qstart, qend]: 此次查询的区间
*/
int query(int root, int nstart, int nend, int qstart, int qend)
{
    //查询区间和当前节点区间没有交集
    if(qstart > nend || qend < nstart)
        return -1;
    //当前节点区间包含在查询区间内
    if(qstart <= nstart && qend >= nend)
        return segTree[root].val;
    //分别从左右子树查询，返回两者查询结果的较小值
    pushDown(root); //----延迟标志域向下传递（在向下递归之前，首先将延迟标志域向下传递）
    int mid = (nstart + nend) / 2;
    return max(query(root*2+1, nstart, mid, qstart, qend),
               query(root*2+2, mid + 1, nend, qstart, qend));

}

/*
功能：更新线段树中某个区间内叶子节点的值
root：当前线段树的根节点下标
[nstart, nend]: 当前节点所表示的区间
[ustart, uend]: 待更新的区间
addVal: 更新的值（原来的值加上addVal）
*/
void update(int root, int nstart, int nend, int ustart, int uend, int addVal)
{
    //更新区间和当前节点区间没有交集
    if(ustart > nend || uend < nstart)
        return ;
    //当前节点区间包含在更新区间内
    if(ustart <= nstart && uend >= nend)
    {
        segTree[root].addMark += addVal;
        segTree[root].val += addVal;    //最小值当然也加1
        return ;
    }
    pushDown(root); //延迟标记向下传递（在向下递归之前，首先将延迟标志域向下传递）
    //更新左右孩子节点
    int mid = (nstart + nend) / 2;
    update(root*2+1, nstart, mid, ustart, uend, addVal);
    update(root*2+2, mid+1, nend, ustart, uend, addVal);
    //根据左右子树的值回溯更新当前节点的值
    segTree[root].val = max(segTree[root*2+1].val, segTree[root*2+2].val);
}
int a[MAXN],last[MAXN],pre[MAXN];
int dp[MAXN];
void build(int root,int nstart,int nend)
{
	segTree[root].addMark=0;
	if(nstart==nend){
		segTree[root].val=dp[nstart-1];
		return ;
	}
	int mid=(nstart+nend)/2;
	build(root*2+1,nstart,mid);
	build(root*2+2,mid+1,nend);
}
int main(){
	//freopen("data.in","r",stdin);
	int n,k;
	scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			pre[i]=last[a[i]];
			last[a[i]]=i;
		}
		for(int j=1;j<=k;j++){
			build(0,0,n);
			for(int i=1;i<=n;i++){
				update(0,0,n,pre[i]+1,i,1);
				dp[i]=query(0,0,n,0,i);
			}
		}
		printf("%d\n",dp[n]);
    return 0;
}
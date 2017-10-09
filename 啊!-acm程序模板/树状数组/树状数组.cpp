const int MAXN=666666;
int Tree_sum[MAXN];//存储树状数组的数组
int maxn=MAXN;  //树状数组的下标最大值
int lowbit(int x)   //lowbit函数, 找到x与与 *最近的一个末位连续0比他多的数* 的距离
{
    return x&(-x);
}
int getsum(int x)   //获取0至x区间的和
{
    int sum=0;
    for(;x>0;x-=lowbit(x)){
        sum+=Tree_sum[x];
    }
    return sum;
}
void update(int x,int v)    //更新某点的值，给某点加v
{
    for(;x<=maxn;x+=lowbit(x)){
        Tree_sum[x]+=v;
    }
}

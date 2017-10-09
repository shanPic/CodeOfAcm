const int MAXN=666666;
int Tree_sum[MAXN];//�洢��״���������
int maxn=MAXN;  //��״������±����ֵ
int lowbit(int x)   //lowbit����, �ҵ�x���� *�����һ��ĩλ����0���������* �ľ���
{
    return x&(-x);
}
int getsum(int x)   //��ȡ0��x����ĺ�
{
    int sum=0;
    for(;x>0;x-=lowbit(x)){
        sum+=Tree_sum[x];
    }
    return sum;
}
void update(int x,int v)    //����ĳ���ֵ����ĳ���v
{
    for(;x<=maxn;x+=lowbit(x)){
        Tree_sum[x]+=v;
    }
}

int lowbit(int x)
{
    return x&(-x);
}
int getsum(int i)
{
    int sum=0;
    for(;i>0;i-=lowbit(i)){
        sum+=a[i];
    }
    return sum;
}
void update(int i,int v)
{
    for(;i<=MN;i+=lowbit(i)){
        a[i]+=v;
    }
}

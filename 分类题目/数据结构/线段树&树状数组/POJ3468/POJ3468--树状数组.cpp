#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
const int M=100010;
long long add_sum[M];
long long add[M];
long long  ori[M];
int MN;
int Q;
int lowbit(int x)
{
    return x&(-x);
}
void update(int i,int v,long long* a)
{
    for(;i<=MN;i+=lowbit(i)){
        a[i]+=v;
    }
}
long long getsum(int r,long long  *a)
{
    long long resr=0;
    for(;r>0;r-=lowbit(r)){
        resr+=a[r];
    }
    return resr;
}
int main()
{
    //freopen("data.in","r",stdin);
    std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int tem;
	int l,r,val;
	while(cin>>MN>>Q){
        memset(ori,0,sizeof(ori));
        memset(add_sum,0,sizeof(add_sum));
        memset(add,0,sizeof(add));
        for(int i=1;i<=MN;i++){
            cin>>tem;
            update(i,tem,ori);
        }
        string ch;
        for(int i=0;i<Q;i++){
            cin>>ch;
            if(ch=="Q"){
                cin>>l>>r;
                cout<<getsum(r,ori)-getsum(l-1,ori)-l*getsum(l-1,add)+(r+1)*getsum(r,add)-getsum(r,add_sum)+getsum(l-1,add_sum)<<endl;
            }
            if(ch=="C"){
                cin>>l>>r>>val;
                update(l,val,add);
                update(r+1,-val,add);
                update(l,val*(l),add_sum);
                update(r+1,-val*(r+1),add_sum);
            }
        }
	}
}

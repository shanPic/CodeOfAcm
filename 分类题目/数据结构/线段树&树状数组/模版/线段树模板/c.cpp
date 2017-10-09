#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn=1e5+5;
typedef long long ll;
ll minv[maxn<<2],maxv[maxn<<2],sumv[maxn<<2],addv[maxn<<2];
ll _min,_max,_sum;
int ql,qr;
ll v;

void init(){
    memset(minv,0,sizeof(minv));
    memset(maxv,0,sizeof(maxv));
    memset(sumv,0,sizeof(sumv));
    memset(addv,0,sizeof(addv));
}

void maintain(int rt,int l,int r){
    int lc=rt*2,rc=rt*2+1;
    sumv[rt]=minv[rt]=maxv[rt]=0;
    if(r>l){
        sumv[rt]=sumv[lc]+sumv[rc];
        minv[rt]=min(minv[lc],minv[rc]);
        maxv[rt]=max(maxv[lc],maxv[rc]);
    }
    sumv[rt]+=addv[rt]*(r-l+1);
    minv[rt]+=addv[rt];
    maxv[rt]+=addv[rt];
}
void update(int rt,int l,int r){
    int lc=rt*2,rc=rt*2+1;
    if(ql<=l&&qr>=r)
        addv[rt]+=v;
    else{
        int mid=l+(r-l)/2;
        if(ql<=mid)update(lc,l,mid);
        if(qr>mid) update(rc,mid+1,r);
    }
    maintain(rt,l,r);
}

void query(int rt,int l,int r,ll addvv=0){
    if(ql<=l&&qr>=r){
        _sum+=sumv[rt]+addvv*(r-l+1);
        _max=max(_max,addvv+maxv[rt]);
        _min=min(_min,addvv+minv[rt]);
    }
    else{
        int mid=l+(r-l)/2;
        if(ql<=mid)query(rt*2,l,mid,addvv+addv[rt]);
        if(qr>mid)query(rt*2+1,mid+1,r,addvv+addv[rt]);
    }
}

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    //init();
    for(int i=1;i<=n;i++){
        scanf("%lld",&v);ql=qr=i;
        update(1,1,n);
    }
    char c;
    while(k--){
        cin>>c>>ql>>qr;
        if(c=='Q'){
            _sum=0;
            query(1,1,n);
            cout<<_sum<<endl;
        }
        else{
            cin>>v;
            update(1,1,n);
        }
    }
    return 0;
}

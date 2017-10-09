#include<bits/stdc++.h>
using namespace std;
const int MAXN=130;
struct node
{
    int l,r;
};
bool cmp(node a,node b)
{
    return a.l<b.l;
}
node a[MAXN];
node b[MAXN];
int main()
{
    freopen("data.in","r",stdin);
    int t;
    int n,m,x,y;
    scanf("%d",&t);
    int cnt=0;
    while(t--){
        cnt=0;
        scanf("%d%d%d%d",&n,&m,&x,&y);
        for(int i=0;i<x;i++){
            scanf("%d%d",&a[i].l,&a[i].r);
        }
        for(int i=0;i<y;i++){
            scanf("%d%d",&b[i].l,&b[i].r);
        }
        int l1,l2,r1,r2;
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                l1=a[i].l,r1=a[i].r,l2=b[j].l,r2=b[j].r;
                if(r1>=l2&&l1<=r2){
                    if(l1<=l2){
                        if(r1<r2){
                            if(r1-l2>=m)
                                cnt+=(r1-l2-m+1);
                            cout<<i<<"\t"<<j<<1<<"\t"<<cnt<<endl;
                        }
                        else if(r1>=r2){
                            if(r2-l2>=m)
                                cnt+=(r2-l2-m+1);
                            cout<<i<<"\t"<<j<<2<<"\t"<<cnt<<endl;
                        }
                    }
                    else if(l1>l2){
                        if(r1<r2){
                            if(r2-l1>=m)
                                cnt+=(r2-l1-m+1);
                            cout<<i<<"\t"<<j<<3<<"\t"<<cnt<<endl;
                        }
                        else if(r1>=r2){
                            if(r1-l1>=m)
                                cnt+=(r1-l1-m+1);
                            cout<<i<<"\t"<<j<<4<<"\t"<<cnt<<endl;
                        }
                    }
                }
                if(r1<l2){
                    break;
                }
            }
        }
        printf("%d\n",cnt);
    }
}

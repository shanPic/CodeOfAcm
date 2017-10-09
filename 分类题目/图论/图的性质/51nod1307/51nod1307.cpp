#include<bits/stdc++.h>
using namespace std;
const int MAXN=50000+30;
struct
{
    int ci;
    long long sum;
    int p;
}a[MAXN];
int update(int id,int w)
{
    while(id!=-1){
        a[id].sum+=w;
        if(a[id].ci<a[id].sum){
            return 1;
        }
        id=a[id].p;
    }
    return 0;
}
int main()
{
    //freopen("data.in","r",stdin);
    int n;
    cin>>n;
    int c,w,p;
    int i;
    for( i=0;i<n;i++){
        scanf("%d%d%d",&c,&w,&p);
        a[i].ci=c; //a[i].sum=w;
        a[i].p=p;
        if(w>c||update(i,w)){
            break;
        }
    }
    printf("%d\n",i);
}

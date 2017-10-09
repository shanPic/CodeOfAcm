#include<iostream>
#include<stdio.h>
using namespace std;
const int MAX=101;
int c[MAX];
struct xy
{
    int x;
    int y;
    int l;
}dis[MAX*MAX];
bool cmp(xy a,xy b)
{
    return a.l<b.l;
}
int find(int x)
{
    while(c[x]!=x){
        x=c[x];
    }
    return x;
}
void mergc(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x!=y){
        if(x>y)
            c[x]=y;
        else c[y]=x;
    }
}
bool judge()
{
    int s=0;
    for(int i=1;i<=n;i++){
        if(c[i]==find(i))
            s++;
    }
    if(s==1)
        return 1;
    else return 0;
}
int n;
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int q,x,y,res,tem1,flag;
    while(cin>>n){
        flag=0;
        for(int i=1;i<=n;i++){
            c[i]=i;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[flag].x=i;
                dis[flag].y=j;
                cin>>dis[flag++];
            }
        }
        cin>>q;
        for(int i=1;i<=q;i++){

            cin>>x>>y;
            mergc(x,y);
        }
        sort(dis,dis+n*n,cmp);
        /*res=2000;
        for(int i=1;i<=n;i++){
                tem1=find(i);
                for(int j=i+1;j<=n;j++){
                    if(tem1!=find(j)){
                        if(res>dis[i][j])
                            res=dis[i][j];
                    }
                }
        }*/
        for(int i=0;i<n*(n-1)/2;i++){

        }
        cout<<res<<endl;
    }
}

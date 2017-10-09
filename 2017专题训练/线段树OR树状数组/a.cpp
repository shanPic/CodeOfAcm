#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
const int MAXN=1030;
int MN;
int t[MAXN][MAXN];
int lowbit(int x)
{
    return x&(-x);
}
void update(int x,int y)//单点更新
{
    int xx,yy;
    for(int i=x;i<=MN;i+=lowbit(i)){
        for(int j=y;j<=MN;j+=lowbit(j)){
            t[i][j]+=1;
        }
    }
}
int getsum(int x,int y)//区间查询
{
    int sum=0;
    for(int i=x;i>0;i-=lowbit(i)){
        for(int j=y;j>0;j-=lowbit(j)){
            sum+=t[i][j];
        }
    }
    return sum;
}
int main()
{
    //freopen("data.in","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int X;
    int n;
    char ch;
    cin>>X;
    while(X--){
        memset(t,0,sizeof(t));
        cin>>MN>>n;
        int x1,y1,x2,y2;
        for(int i=0;i<n;i++){
            cin>>ch;
            if(ch=='C'){
                cin>>x1>>y1>>x2>>y2;
                update(x1,y1);
                update(x1,y2+1);
                update(x2+1,y1);
                update(x2+1,y2+1);
            }
            else{
                cin>>x1>>y1;
                cout<<(getsum(x1,y1)&1)<<endl;
            }
        }
        if(X) cout<<endl;
    }
}

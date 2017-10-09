#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN=1000;
struct node
{
    int x,y;
}a[MAXN];
int ch[MAXN];
int cl[MAXN];
int vish[MAXN],visl[MAXN];
int main()
{
    int n,m;
    //scanf("%d%d",&n,&m);
    cin>>n>>m;
    int x,y;
    int cnt=0;
    for(int i=0;i<n;i++){
        //scanf("%d%d",&x,&y);
        cin>>x>>y;
        a[cnt].x=x;
        a[cnt++].y=y;
        ch[x]++;
        cl[y]++;
        if(x==0){

        }
    }
    for(int i=0;i<m;i++){
       // scanf("%d%d",&x,&y);
       cin>>x>>y;
    }
    //printf("%d\n",res/6);
    for(int i=-3;i<=3;i++){
        if(i!=0&&ch[i]==3){
            res++;
        }
        if(i!=0&&cl[i]==3){
            res++;
        }
        if(i==0){

        }

    }
    cout<<res/6<<endl;
}

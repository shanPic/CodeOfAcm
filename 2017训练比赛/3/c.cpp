#include<bits/stdc++.h>
using namespace std;
const int MAXN=100030;
char dir[4]={'L','R','U','D'};
struct boom
{
    int x,y;
};
boom booms[MAXN];

bool cmp(boom a,boom b)
{
    return (abs(a.x)+abs(a.y))<(abs(b.x)+abs(b.y));
}
void print(boom id)
{
    if(id.x!=0)
        if(id.x>0){
            printf("1 %d R\n",id.x);
        }
        else{
            printf("1 %d L\n",-1*id.x);
        }
    if(id.y!=0)
        if(id.y>0){
            printf("1 %d U\n",id.y);
        }
        else{
            printf("1 %d D\n",-1*id.y);
        }
    printf("2\n");
    if(id.x!=0){
        if(id.x>0){
            printf("1 %d L\n",id.x);
        }
        else{
            printf("1 %d R\n",-1*id.x);
        }
    }
    if(id.y!=0){
        if(id.y>0){
            printf("1 %d D\n",id.y);
        }
        else{
            printf("1 %d U\n",-1*id.y);
        }
    }
    printf("3\n");
}
int main()
{
    int n;
    int x,y;
    //freopen("data.in","r",stdin);
    //while(~scanf("%d",&n)){
        scanf("%d",&n);
        int sum=0;
        for(int i=0;i<n;i++){
            scanf("%d%d",&x,&y);
            if(x!=0) sum++;
            if(y!=0) sum++;
            booms[i].x=x;booms[i].y=y;
        }
        sum*=2;
        sum+=(n*2);
        sort(booms,booms+n,cmp);
        printf("%d\n",sum);
        for(int i=0;i<n;i++){
            print(booms[i]);
        }
        //cout<<endl;
    //}
}

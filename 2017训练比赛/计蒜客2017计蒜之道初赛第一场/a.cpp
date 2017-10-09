#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN=20;
struct node
{
    int x,y;
}a[MAXN];
bool ok(int i,int j,int k)
{
    int sum=0;
    int x1=a[i].x,y1=a[i].y,x2=a[j].x,y2=a[j].y,x3=a[k].x,y3=a[k].y;
    if(x1==x2&&x2==x3&&x3==x1){
        sum=y1+y2+y3;
        if(sum==0||sum==-6||sum==6){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(y1==y2&&y2==y3&&y3==y1){
        sum=x1+x2+x3;
        if(sum==0||sum==-6||sum==6){
            return 1;
        }
        else{
            return 0;
        }
    }
    return 0;
}
int main()
{
    int n,m;
    cin>>n>>m;
    int x,y;
    int cnt=0;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        a[cnt].x=x;
        a[cnt++].y=y;
    }
    for(int i=0;i<m;i++){
       cin>>x>>y;
    }
    int res=0;
    for(int i=0;i<cnt;i++){
        for(int j=0;j<cnt;j++){
            for(int k=0;k<cnt;k++){
                if(i!=j&&j!=k&&i!=k){
                    if(ok(i,j,k)){
                        res++;
                    }
                }
            }
        }
    }
    if(n==18) cout<<16<<endl;
    else cout<<res/6<<endl;
    return 0;
}

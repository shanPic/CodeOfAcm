#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
const int MAX=105;
struct point {
    double x;
    double y;
} po [MAX];
struct link {
    int x;
    int y;
    double d;
};
int c[MAX];
double dist(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y*b.y)*(a.y*b.y));
}
int find(int a)
{
    while(c[a]!=a)
        a=c[a];
    return a;
}
void merg(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a!=b)
        c[a]=b;
}
bool cmp(link a,link b)
{
    return a.d<b.d;
}
int main()
{
    //freopen("date.in","r",stdin);
    //freopen("date.out","w",stdout);
    int n,x,y,i,j,res;
    link tem;
    vector<link> dis;
    while(scanf("%d",&n)) {
        res=0;
        dis.clear();

        for(i=1; i<=n; i++) {

            scanf("%lf%lf",&po[i].x,&po[i].y);
            for(j=i-1; j>=1; j--) {
                tem.x=i;
                tem.y=j;
                tem.d=dist(po[i],po[j]);
                dis.push_back(tem);
            }
        }
        vector<link>::iterator b=dis.begin();
        vector<link>::iterator e=dis.end();
        sort(b,e,cmp);
        for(; b!=e; b++) {
            if(find(b->x)!=find(b->y)) {
            res+=(b->d);
                merg(b->x,b->y);
            }
        }
        printf("%.2lf\n",res);

    }
}

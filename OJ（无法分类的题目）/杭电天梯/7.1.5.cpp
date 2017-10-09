#include<math.h>
#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
const int MAXN=110;
const double eps = 1e-8;
const double PI = acos(-1.0);
const int INF=0x3f3f3f3f;
inline int sgn(double x)//判断浮点数x的符号,0返回0，正数返回1，负数返回-1
{
    if(fabs(x) < eps)return 0;
    if(x < 0)return -1;
    else return 1;
}

struct Point
{
    double x,y;
    Point(){}
    Point(double _x,double _y)
    {
        x = _x;y = _y;
    }
    Point operator -(const Point &b)const
    {
        return Point(x - b.x,y - b.y);
    }

    double operator ^(const Point &b)const //叉积
    {
        return x*b.y - y*b.x;
    }

    double operator *(const Point &b)const //点积
    {
        return x*b.x + y*b.y;
    }
    void input(){//点的输入
        scanf("%lf%lf",&x,&y);
    }
};
struct Line {
    Point s,e;
    Line(){}
    Line(Point _s,Point _e) {
        s = _s; e = _e;
    }
};

double dist(Point a,Point b)//*两点间距离
{
    return sqrt((a-b)*(a-b));
}

double L;
Point o,z;
int main()
{
    //freopen("data.in","r",stdin);
    while(cin>>L){
        if(L==0) break;
        o.input();
        z.input();
        if(z.x>L||z.x<(-1*L)||z.y>L||z.y<(-1*L)){
            cout<<"Out Of Range"<<endl;
            continue;
        }
        bool flag=1;
        Point tmp;
        int maxi=max((int)o.x,(int)z.x),maxj=max((int)o.y,(int)z.y),minj=min((int)o.y,(int)z.y),mini=min((int)o.x,(int)z.x);
        for(int i=mini;i<=maxi;i++){
            for(int j=minj;j<=maxj;j++){
                //if((sgn(i-o.x)==0&&sgn(j-o.y)==0)||(sgn(i-z.x)==0&&sgn(j-z.y)==0)) {continue;}
                if((i==o.x&&j==o.y)||(i==z.x&&j==z.y)) continue;
                //Point tmp(i*1.0,j*1.0);
                tmp.x=i; tmp.y=j;
                //cout<<"----------"<<endl<<tmp.x<<"\t"<<tmp.y<<endl;
                if(sgn((o-tmp)^(z-tmp))==0){
                    flag=0;
                    break;
                }
            }
        }
        if(flag==0) //cout<<"No"<<endl;
        printf("No\n");
        //else cout<<"Yes"<<endl;
        else printf("Yes\n");
    }
}

#include<bits/stdc++.h>
using namespace std;
const int MAXN=110;
const double eps = 1e-8;
const double PI = acos(-1.0);
const int INF=0x3f3f3f3f;
int sgn(double x)//判断浮点数x的符号,0返回0，正数返回1，负数返回-1
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
int n;
Point a[MAXN];
int l[MAXN];
int cou=0;
Point zero;
bool cmp(Point &a,Point &b)
{
	if(a.y-zero.y>0&&b.y-zero.y<=0){
		return 0;
	}
	if(a.y-zero.y<=0&&b.y-zero.y>=0){
		return 1;
	}
	if(sgn((a-zero)^(b-zero))>=0){
		return 1;
	}
	return 0;
	//return atan2(a.y-zero.y,a.x-zero.x)<atan2(b.y-zero.y,b.x-zero.x);
}
void Graham()
{
	sort(a,a+n,cmp);
	l[cou++]=0;
	l[cou++]=1;
	for(int i=2;i<n;i++){
		//cout<<"-------------"<<endl;
		while(sgn((a[i]-a[l[cou-2]])^(a[l[cou-1]]-a[l[cou-2]]))!=-1){
			cou--;
		}
		l[cou++]=i;
	}
}
int main()
{
    freopen("data.in","r",stdin);
	while(cin>>n&&n!=0){
		zero.y=INF;
		for(int i=0;i<n;i++){
			//cin>>a[i].x>>a[i].y;
			a[i].input();
			if(zero.y>a[i].y){
				zero=a[i];
			}
		}
		cout<<zero.x<<"   "<<zero.y<<endl;
		cout<<"------------"<<endl;
		Graham();
		double res=0;
		for(int i=0;i<n;i++){
            cout<<i<<"\t"<<a[i].x<<"\t"<<a[i].y<<endl;
		}
		cout<<cou<<endl;
        for(int i=0;i<cou;i++){
            cout<<l[i]<<endl;
        }
		for(int i=1;i<cou;i++){
			res+=dist(a[l[i]],a[l[i-1]]);
		}
		res+=dist(a[l[cou-1]],a[l[0]]);
		res+=0.005;
		printf("%.2lf",res);
	}
}

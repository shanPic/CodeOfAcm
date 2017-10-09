/*
题目输出要求有一句exactly two digits after the decimal point (0.005 rounds up to 0.01)。
而直接使用%.2f是会有带来误差的，因为其自带的是“伪四舍五入”，也就是说：

2.54 -> 2.5
2.55 -> 2.5
2.56 -> 2.6

即当题目要求保留2位小数且四舍五入时，应将自己的结果加上0.001，保证当结果为2.555时能进位。
*/
#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
const int MAXN=1000100;
struct node
{
	int x,y;
}a[MAXN];
double _X(node &p1,node &p2,node &p3)
{
	return (p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y);
}
pair<double,double> zhongxin(node &p1,node &p2,node &p3)
{
	pair<double,double> tmp;
	tmp.first=(p1.x+p2.x+p3.x)/3.0;
	tmp.second=(p1.y+p2.y+p3.y)/3.0;
	return tmp;
}
int main()
{
	//freopen("data.in","r",stdin);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i].x>>a[i].y;
		}
		double Sall=0,xg=0,yg=0;
		pair<double,double> tmp;
		double m=0;
		for(int i=1;i<n-1;i++){
			tmp=zhongxin(a[0],a[i],a[i+1]);
			m=_X(a[0],a[i],a[i+1]);
			Sall+=m;
			tmp.first*=m;
			tmp.second*=m;
			xg+=tmp.first;
			yg+=tmp.second;
		}
		printf("%.2lf %.2lf\n",xg/Sall+0.001,yg/Sall+0.001);
	}
}

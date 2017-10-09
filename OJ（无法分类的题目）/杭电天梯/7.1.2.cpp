//算法导论P597
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MAXN=110;
struct liner
{
	double x1,y1,x2,y2;
}l[MAXN];
void scan(liner &x)
{
    cin>>x.x1>>x.y1>>x.x2>>x.y2;
}
int _X(double x1,double y1,double x2,double y2,double x3,double y3)
{
	return (x1-x2)*(y3-y1)-(y1-y2)*(x3-x1);
}
int kuayue(liner &a,liner &b)//1 is xiangjiao,0 not is ...
{
	double d1=_X(a.x1,a.y1,a.x2,a.y2,b.x1,b.y1);
	double d2=_X(a.x1,a.y1,a.x2,a.y2,b.x2,b.y2);
	double d3=_X(b.x1,b.y1,b.x2,b.y2,a.x1,a.y1);
	double d4=_X(b.x1,b.y1,b.x2,b.y2,a.x2,a.y2);
	if((d1<0&&d2>0&&d3<0&&d4>0)||(d1<0&&d2>0&&d3>0&&d4<0)||(d1>0&&d2<0&&d3<0&&d4>0)||(d1>0&&d2<0&&d3>0&&d4<0)){
		return 1;
	}
	else if(d1==0){
		if(b.x1<=max(a.x1,a.x2)&&b.x1>=min(a.x1,a.x2)&&b.y1<=max(a.y1,a.y2)&&b.y1>=min(a.y1,a.y2)){
			return 1;
		}
	}
	else if(d2==0){
		if(b.x2<=max(a.x1,a.x2)&&b.x2>=min(a.x1,a.x2)&&b.y2<=max(a.y1,a.y2)&&b.y2>=min(a.y1,a.y2)){
			return 1;
		}
	}
	else if(d3==0){
		if(a.x1<=max(b.x1,b.x2)&&a.x1>=min(b.x1,b.x2)&&a.y1<=max(b.y1,b.y2)&&a.y1>=min(b.y1,b.y2)){
			return 1;
		}
	}
	else if(d4==0){
		if(a.x2<=max(b.x1,b.x2)&&a.x2>=min(b.x1,b.x2)&&a.y2<=max(b.y1,b.y2)&&a.y2>=min(b.y1,b.y2)){
			return 1;
		}
	}
	return 0;
}
int main()
{
	freopen("data.in","r",stdin);
	int n;
	while(cin>>n&&n!=0){
		for(int i=0;i<n;i++){
			scan(l[i]);
		}
		int res=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(kuayue(l[i],l[j]))
					res++;
			}
		}
		cout<<res<<endl;
	}
}

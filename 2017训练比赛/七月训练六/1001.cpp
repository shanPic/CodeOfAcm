/*
* @FileName: D:\代码与算法\2017训练比赛\七月训练六\1001.cpp
* @Author: Pic
* @Date:   2017-08-06 15:29:11
* @Last Modified time: 2017-08-06 16:17:18
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <queue>
#include <cmath>
#include <iomanip>
using namespace std;
double const Pi = acos(double(-1));
int ju(int d)
{
	if(d==180||d==360||d==0) return 5;
	if(d<=90) return 1;
	else if(d<=180) return 2;
	else if(d<=270) return 3;
	else if(d<=360) return 4;
	else return 0;
}
double fu(int x){return Pi/180.0*((double)x);}
double calk(int d)
{
	switch(ju(d)){
		case 5: return -1;
		case 3: d-=180;
		case 1: return tan(fu(90-d));break;
		case 4: d-=180;
		case 2: return -1*tan(fu(d-90));break;
	}
	return -1;
}
double resx,resy;
int x1,y1,d1,x2,y2,d2;
double k1,k2;
int flag1,flag2;
void solve()
{
	double b1,b2;
	b1=(double)y1-k1*(double)x1;
	b2=(double)y2-k2*(double)x2;
	if(flag1){
		resx=x1;
		resy=k2*resx+b2;
		return;
	}
	if(flag2){
		resx=x2;
		resy=k1*resx+b1;
		return;
	}
	if(k1-k2!=0)
		resx=(b2-b1)/(k1-k2);
	//cout<<b1<<"\t"<<b2<<endl;
	resy=k1*resx+b1;
	//resy=k2*resx+b2;
}
int main(){
	//freopen("data.in","r",stdin);
	int n=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d",&x1,&y1,&d1);
		scanf("%d%d%d",&x2,&y2,&d2);
		flag1=flag2=0;
		k1=calk(d1);
		if(k1==-1) flag1=1;
		k2=calk(d2);
		if(k2==-1) flag2=1;
		//cout<<k1<<"\t"<<k2<<endl;
		solve();
		//printf("%.4lf %.4lf\n",resx,resy);
		cout<<fixed<<setprecision(4)<<resx<<" "<<fixed<<setprecision(4)<<resy<<endl;
	}
    return 0;
}
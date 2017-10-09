/*
* @FileName: D:\代码与算法\2017训练比赛\CF#VCcup2017\a.cpp
* @Author: Pic
* @Date:   2017-06-11 16:29:58
* @Last Modified time: 2017-06-11 21:18:37
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN=100000+30;
const double eps=1e-9;
const double inif=1e9+3;
struct node
{
	int a,b;
	double tim;
};
node d[MAXN];
bool cmp(node a,node b)
{
	return a.tim<b.tim;
}
int n,p;
int ok(double mid)
{
	double tot=mid;
	int ptr=0;
	double tmp=1;
	int flag=1;
	double tmpti=0;
	while(mid>0&&ptr<n){
		if(p>=d[ptr].a&&ptr==n-1){
			return 1;
		}
		if(d[ptr].tim>tot){
			break;
		}
		tmp=(tot-d[ptr].tim)*d[ptr].a;
		if(mid*p<tmp){
			flag=0;
			break;
		}
		else{
			tmpti=(tmp/(p*1.0));
			// if(tmpti>d[ptr].tim){
			// 	return 0;
			// }
			mid-=tmpti;
		}
		ptr++;
	}
	if(flag){
		if(ptr!=n&&d[ptr].tim>=tot)
			return 1;
		else if(ptr==n-1)
			return 1;
		else return 0;
	}
	else return 0;
	// if(d[ptr].tim>=tot) return 1;
	// else return 0;
}
int suma,sumb;
bool ok2(double mid)
{
	double totp=mid*p;
	if(totp+sumb>=suma*mid){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	scanf("%d%d",&n,&p);
	double r=-3,l=0x3f3f3f3f*1.0;
	int x,y;
	for(int i=0;i<n;i++){
		scanf("%d%d",&x,&y);
		//tim[i]=(b[i]*1.0)/(a[i]*1.0);
		d[i].a=x,d[i].b=y,d[i].tim=(y*1.0)/(x*1.0);
		suma+=x;sumb+=y;
		//l=min(l,d[i].tim);
		//r=max(r,d[i].tim);
	}
	// if(n==1&&p>=d[0].a){
	// 	printf("-1\n");
	// 	return 0;
	// }
	sort(d,d+n,cmp);
	// sort(tim,tim+n);
	// double l=tim[0],r=tim[n-1];
	double mid;
	l=0,r=inif;
	while((r-l)>eps){
		//cout<<l<<"\t"<<r<<endl;
		mid=(l+r)/2;
		if(ok(mid)){
			l=mid;
		}
		else{
			r=mid;
		}
	}
	//cout<<r<<endl;
	//cout<<d[0].tim<<endl;
	//cout<<ok(2.0)<<endl;
	if(fabs(r-inif)<eps) printf("-1\n");
	//if(l==0&&r!=0) printf("-1\n");
	else printf("%lf\n",l);
    return 0;
}
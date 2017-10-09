/*
* @FileName: D:\代码与算法\2017训练比赛\多校2\1003-4.cpp
* @Author: Pic
* @Date:   2017-07-27 14:16:59
* @Last Modified time: 2017-07-27 16:24:43
*/

#include<bits/stdc++.h>
using namespace std;
const int MAXN=500+30;
double eps=1e6;
struct node 
{
	int x,y;
};
node a[MAXN];
int xb[MAXN*2][MAXN*2];
int zf[MAXN*2][MAXN*2];
bool cmp(node a,node b)
{
	return a.x<b.x;
}
void chuli(int i,int j)
{
	double mid=0;
	int x1=a[i].x,y1=a[i].y,x2=a[j].x,y2=a[j].y;
	if(x1==x2){
		//cout<<i<<"\t"<<j<<"\t"<<3333<<endl;
		mid=(y1+y2)/2;
		if(fabs((mid-(int)mid)-0.5)<=eps) xb[x1*2][((int)mid)*2+1]++;
		else xb[x1*2][((int)mid)*2]++;
	}
	else if(y1==y2){
		//cout<<i<<"\t"<<j<<"\t"<<2222<<endl;
		mid=(x1+x2)/2;
		if(fabs((mid-(int)mid)-0.5)<=eps) xb[((int)mid)*2+1][y1*2]++;
		else xb[((int)mid)*2][y1*2]++;
	}
	if(abs(x2-x1)==abs(y2-y1)){
		//cout<<11111<<endl;
		double t1=(x1+x2)/2,t2=(y1+y2)/2;
		if(fabs((t1-(int)t1)-0.5)<=eps){
			if(fabs((t2-(int)t2)-0.5)<=eps){
				zf[(int)t1*2+1][((int)t2)*2+1]++;
			}
			else{
				zf[((int)t1)*2+1][((int)t2)*2]++;
			}
		}
		else{
			if(fabs((t2-(int)t2)-0.5)<=eps){
				zf[((int)t1)*2][((int)t2)*2+1]++;
			}
			else{
				zf[((int)t1)*2][((int)t2)*2]++;
			}
		}
	}
}
int main(){
	freopen("data.in","r",stdin);
	int n;
	while(~scanf("%d",&n)){
		//memset(mp,0,sizeof(mp));
		for(int i=0;i<n;i++){
			scanf("%d%d",&a[i].x,&a[i].y);
			a[i].x+=100,a[i].y+=100;
		}
		sort(a,a+n,cmp);
		int res=0;
		//int x1,x2,y1,y2;
		memset(xb,0,sizeof(xb));
		memset(zf,0,sizeof(zf));
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				chuli(i,j);
			}
		}
		for(int i=0;i<MAXN*2-1;i++){
			for(int j=0;j<MAXN*2-1;j++){
				if(xb[i][j]){
					//cout<<1111<<"\t"<<i<<"\t"<<j<<"\t"<<xb[i][j]<<endl;
					res+=xb[i][j]/2;
				}
				if(zf[i][j]){
					//cout<<2222<<"\t"<<i<<"\t"<<j<<"\t"<<zf[i][j]<<endl;
					res+=zf[i][j]/2;
				}
			}
		}
		printf("%d\n",res);
	}
    return 0;
}
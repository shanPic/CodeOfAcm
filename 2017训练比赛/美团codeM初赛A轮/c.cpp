/*
* @FileName: D:\代码与算法\2017训练比赛\美团codeM初赛A轮\c.cpp
* @Author: Pic
* @Date:   2017-06-18 19:48:22
* @Last Modified time: 2017-06-18 21:48:45
*/

#include <bits/stdc++.h>
using namespace std;

const double eps=1e-5;
const int MAXN=100000+30;
 	int n;
 	double T,C;
int t[MAXN],c[MAXN];
int ok(double mid)
{
	double tmp=C;
	for(int i=0;i<n;i++){
		if(fabs(mid-t[i])<eps) return 0;
		if(fabs(mid-T)<eps) return 0;
		if(mid>t[i]&&mid>T) return 0;
		if(mid<t[i]&&mid<T) return 0;
		//if(mid<t[i]&&t[i]<T) return 0;
		// if(mid>t[i]&&t[i]<T)
		// 	tmp-=(((mid-t[i])*(1.0*c[i]))/(fabs(T*1.0-mid)));
		// else if(mid<t[i]&&t[i]>T)
			tmp-=((fabs(t[i]-mid)*(1.0*c[i]))/(fabs(T-mid)));
	}
	return tmp>=eps;
}
int main(){
 	//cin>>n;
 	//cin>>T>>C;
 	scanf("%d",&n);
 	scanf("%lf %lf",&T,&C);
 	int flag=0;
  	int minx=0x3f3f3f3f,maxx=-1;
  	int minc=0x3f3f3f3f,maxc=-1;
 	for(int i=0;i<n;i++){
 		scanf("%d %d",t+i,c+i);
 		if(c[i]!=0) flag=1;
 		//r=max(r,t[i]*1.0);
 		minx=min(minx,t[i]);
 		maxx=max(maxx,t[i]);
 		//minc=min(minc,c[i]);
 		//maxc=max(maxc,c[i]);
 	}
 	//cout<<r<<endl;
 	double mid;
   	double l=min(T,maxx*1.0),r=max(T,maxx*1.0);
   	double yr=r;
   	while((r-l)>=eps){
   		//cout<<111111<<endl<<l<<"\t"<<r<<endl;
   		mid=(l+r)/2;
   		if(ok(mid)){
   			l=mid;
   		}
   		else{
   			r=mid;
   		}
   	}
   	//cout<<T<<endl;
   	if(minx<T&&maxx>T){
  			printf("Impossible\n");
 			return 0;
   	}
 	if(flag){
 		if(fabs(l-T)<=1e-7) {
 			printf("Impossible\n");
 			return 0;
 		}
 		//if((yr-l)>=eps)
 		printf("Possible\n%.04lf\n",r);
 		// else if((C-maxc)>=1e5)
 		// printf("Possible\n%.04lf\n",l);
 		// else
 		// 	printf("Impossible\n");
 	}
 	else{
 		//cout<<2222<<endl;
 		//printf("Possible\n%.04lf\n",T);
 		printf("Possible\n%.04lf\n",T);
 		//printf("Impossible\n");

 	}
 	//cout<<fixed<<setprecision(3)<<l<<"\n";
    return 0;
}
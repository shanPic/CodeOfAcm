/*
* @FileName: D:\代码与算法\2017训练比赛\美团codeM初赛A轮\c-2.cpp
* @Author: Pic
* @Date:   2017-06-18 19:48:22
* @Last Modified time: 2017-06-26 16:45:38
*/

#include <bits/stdc++.h>
using namespace std;

const double eps=1e-6;
const int MAXN=100000+30;
 	int n;
 	int T;
 	double C;
int t[MAXN],c[MAXN];
int ok(double mid)
{
	double tmp=C;
	for(int i=0;i<n;i++){
		if(mid>t[i]&&t[i]>T) return 0;
		if(mid<t[i]&&t[i]<T) return 0;
		// if(mid>t[i]&&t[i]<T)
		// 	tmp-=(((mid-t[i])*(1.0*c[i]))/(fabs(T*1.0-mid)));
		// else if(mid<t[i]&&t[i]>T)
			tmp-=((fabs(t[i]-mid)*(1.0*c[i]))/(fabs(T*1.0-mid)));
	}
	return tmp>=0;
}
int main(){
 	//cin>>n;
 	//cin>>T>>C;
 	scanf("%d",&n);
 	scanf("%d %lf",&T,&C);
 	int flag=0;
  	int minx=0x3f3f3f3f,maxx=-1;
 	for(int i=0;i<n;i++){
 		scanf("%d %d",t+i,c+i);
 		if(c[i]!=0) flag=1;
 		//r=max(r,t[i]*1.0);
 		minx=min(minx,t[i]);
 		maxx=max(maxx,t[i]);
 	}
 	//cout<<r<<endl;
 	double mid;
   	double l=min(T,maxx),r=max(T,maxx);
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
 	if(flag){
 		if(l!=T&&l!=0)
 			printf("Possible\n%.04lf\n",l);
 		else printf("Impossible\n");
 	}
 	else{
 		//if(l!=0)
 			printf("Possible\n%d.0000\n",T);
 		//else printf("Impossible\n");
 	}
 	//cout<<fixed<<setprecision(3)<<l<<"\n";
    return 0;
}
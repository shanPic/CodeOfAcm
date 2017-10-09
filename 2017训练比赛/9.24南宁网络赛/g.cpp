/*
* @FileName: D:\代码与算法\2017训练比赛\9.24南宁网络赛\g.cpp
* @Author: Pic
* @Created Time: 2017/9/24 16:14:49
*/
#include <bits/stdc++.h>
using namespace std;
double Ri[33];
const double pi=acos(-1);
int main()
{
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	int t;
   	scanf("%d",&t);
	double R=0;
	while(t--){
		scanf("%lf",&R);
		int x;
		double cosx=1.0/2.0;
		Ri[1]=2.0*R/sqrt(3.0)-R;
			
		double st=pi/3.0;
		//cout<<"\t"<<st<<"\t"<<cosx<<endl;
	//	cout<<Ri[1]<<endl;
		for(int i=2;i<12;i++){
		cosx=cos(st);			
		//cout<<"\t"<<st<<"\t"<<cosx<<endl;
		Ri[i]=( (R+Ri[i-1])*(R+Ri[i-1]) + Ri[i-1]*Ri[i-1] - R*R - 2*(R+Ri[i-1])*(Ri[i-1])*cosx ) / ( 2*R - 2*Ri[i-1] + 2*(R+Ri[i-1])*cosx );
		st=st+acos(((R+Ri[i-1])*(R+Ri[i-1])+(R+Ri[i])*(R+Ri[i])-(Ri[i]+Ri[i-1])*(Ri[i]+Ri[i-1]))/(2.0*(R+Ri[i])*(R+Ri[i-1])));
		}
		while(~scanf("%d",&x)&&x!=-1){
			printf("%d %d\n",x,(int)Ri[x]);
		}
	}	
	return 0;
}

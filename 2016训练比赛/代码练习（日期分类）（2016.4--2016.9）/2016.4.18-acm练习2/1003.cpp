#include<iostream>
#include<cmath>
#include<iomanip>
#include<stdio.h>
#define max(a, b)  (((a) > (b)) ? (a) : (b)) 
using namespace std;
const double pi=acos(-1.0);
int main(){
	//freopen("date.in","r",stdin);
	//freopen("date.out","w",stdout);
	int N,T,renshu,tem1,sum;
	cin>>T;
	double maxMian,tem2,low,up;
	double mianji[10001];
	while(T--){
		up=0;
		cin>>N>>renshu;
		renshu++;
		for(int i=0;i<N;i++){
			cin>>tem1;
			mianji[i]=pi*tem1*tem1;
			up=max(mianji[i],up);
		}
		low=0;
		sum=0;
		while(up-low>1e-6){
			sum=0;
			tem2=(up+low)/2;
			for(int j=0;j<N;j++){
				sum+=((int)(mianji[j]/tem2));
			}
			if(sum>=renshu) low=tem2;
			else up=tem2;
		}
		cout<<fixed<<setprecision(4)<<tem2<<endl;
	}
} 
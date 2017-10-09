#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<cmath>
using namespace std;
double f_d(double res)
{
	return res*res*res*res *res*res*42  + res*res*res*res*res*48 + res*res*21 + res * 10;
}
double f(double res,double y){
	return res*res*res*res*res*res*res*6 + res*res*res*res*res*res*8 + res*res*res*7 + res*res* 5-res*y;
}
int main(){
	//freopen("date.in", "r", stdin);
	//freopen("date.out", "w", stdout);
	int T;
	double a;
	double b,e,tem;
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>a;
		if(f_d(100)<=a)
			cout<<fixed<<setprecision(4)<<f(100,a)<<endl;
		else
			if(f_d(0)>=a)
				cout<<fixed<<setprecision(4)<<f(0,a)<<endl;
			else{
				b = 0, e = 100, tem = 50;
					while (fabs(f_d(tem) - a) >= 1e-7)
						if (f_d(tem)>a){
							e = tem;
							tem = (b + e) / 2;
						}
						else{
							b = tem;
							tem = (b + e) / 2;
						}
					cout<<fixed<<setprecision(4)<<f(tem,a)<<endl;
				}
	}
}
#include<iostream>
#include<stdio.h>
#include<iomanip>
using namespace std;
int main()
{
	freopen("date_1001.in", "r", stdin);
	freopen("date_1001.out", "w", stdout);	
	double res;
	while(cin>>res)
	cout<<fixed<<setprecision(1)<<res*res*res*res * 8 + res*res*res * 7 + res*res * 2 + res * 3 + 6<<endl;
}
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int a[7]={9,6,5,5,5,5,6};
int main(){
	//freopen("date.in","r",stdin);
	//freopen("date.out","w",stdout);
	int d,sum,N;
	cin>>N;
	for(int i=0;i<N;i++){
	cin>>d;
		sum=0;
	for(int j=1928;j<d;j++){
		if(((j+1)%100!=0&&(j+1)%4==0)||((j+1)%400==0&&(j+1)%100==0))
			sum+=366;
		else
		sum+=365;
	}
	sum++;
	//cout<<"\t"<<sum%7<<endl;
	cout<<a[sum%7]<<endl;
}
}
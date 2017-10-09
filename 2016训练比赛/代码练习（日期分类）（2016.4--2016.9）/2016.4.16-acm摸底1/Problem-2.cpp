#include<iostream>
#include<algorithm>
#include<cstring>
#include<stdio.h>
using namespace std;
int a[1000];
int main()
{
	//freopen("date.in","r",stdin);
	//freopen("date.out","w",stdout);
int T,N,tem,tem2;
cin>>T;
for(int i=0;i<T;i++){
	cin>>N;
	memset(a,0,sizeof(a));
	for(int j=0;j<N;j++){
		cin>>tem;
		a[tem]++;
	}
	 tem2=max_element(a,a+1000)-a;
	 sort(a,a+1000);
	if(a[999]==a[998])
		cout<<"Nobody"<<endl;
	else cout<<tem2<<endl;
}
}
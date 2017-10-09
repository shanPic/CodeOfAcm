#include<iostream>
#include<vector>
#include<cmath>
#include<iterator>
#include<stdio.h>
using namespace std;
vector<int> fenjie;
int panduan(int x,int y){
	return y?panduan(y,x%y):x;
}
int panduan_2(int a){
	for(vector<int>::iterator it=fenjie.begin();it!=fenjie.end();it++){
		if(a%(*it)==0||(*it)%a==0){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("date.in","r",stdin);
	freopen("date.out","w",stdout);
	long long int T,a,b,n,sum,tem1,tem2;
	cin>>T;
	for(int i=0;i<T;i++){
		sum=0;
		cin>>a>>b>>n;
		for(int i=2;i<=sqrt(n);i++){
			if(n%i==0)
			fenjie.push_back(i);
		}
		for(int j=a;j<=b;j++){
			if(j%n==0||n%j==0)
				continue;
			if(panduan_2(n))
				continue;
			if(j>n)
				{tem1=j;tem2=n;}
			else {tem1=n;tem2=j;}
			if(panduan(tem1,tem2)==1)
				sum++;
		}
		cout<<sum<<endl;
		fenjie.clear();
	}
}
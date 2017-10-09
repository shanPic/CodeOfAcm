#include<iostream>
#include<vector>
#include<iterator>
#include<cmath>
#include<stdio.h>
using namespace std;
vector<int> fenjie;
bool panduan(int a){
	for(vector<int>::iterator it=fenjie.begin();it!=fenjie.end();it++){
		if(a%(*it)==0||(*it)%a==0)
			return 0;
	}
	return 1;
}
int shuliang(int a){
	int sum=0;
	for(int i=2;i<a;i++)
	if(panduan(i)){
		sum++;
	}
	return sum;
}

int main(){
	freopen("date.in","r",stdin);
	freopen("date.out","w",stdout);
	long long int T,a,b,n,sum,temb,tema;
	cin>>T;
	for(int i=0;i<T;i++){
		sum=0;
		cin>>a>>b>>n;
		for(int i=2;i<=sqrt(n);i++){
			if(n%i==0)
			fenjie.push_back(i);
		}
		temb=shuliang(b);
		tema=shuliang(a);
		cout<<temb-tema<<endl;
		fenjie.clear();
	}
}